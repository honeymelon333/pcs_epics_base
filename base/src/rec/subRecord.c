/*************************************************************************\
* Copyright (c) 2008 UChicago Argonne LLC, as Operator of Argonne
*     National Laboratory.
* Copyright (c) 2002 The Regents of the University of California, as
*     Operator of Los Alamos National Laboratory.
* EPICS BASE is distributed subject to a Software License Agreement found
* in file LICENSE that is included with this distribution. 
\*************************************************************************/

/* Revision-Id: anj@aps.anl.gov-20131120222110-3o0wgh76u652ad4e */

/* Record Support Routines for Subroutine records */
/*
 *      Original Author: Bob Dalesio
 *      Date:            01-25-90
 */

#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "dbDefs.h"
#include "epicsPrint.h"
#include "epicsMath.h"
#include "registryFunction.h"
#include "alarm.h"
#include "cantProceed.h"
#include "dbAccess.h"
#include "epicsPrint.h"
#include "dbEvent.h"
#include "dbFldTypes.h"
#include "errMdef.h"
#include "recSup.h"
#include "recGbl.h"
#include "special.h"

#define GEN_SIZE_OFFSET
#include "subRecord.h"
#undef  GEN_SIZE_OFFSET
#include "epicsExport.h"

/* Create RSET - Record Support Entry Table*/
#define report NULL
#define initialize NULL
static long init_record(subRecord *, int);
static long process(subRecord *);
static long special(DBADDR *, int);
#define get_value NULL
#define cvt_dbaddr NULL
#define get_array_info NULL
#define put_array_info NULL
static long get_units(DBADDR *, char *);
static long get_precision(DBADDR *, long *);
#define get_enum_str NULL
#define get_enum_strs NULL
#define put_enum_str NULL
static long get_graphic_double(DBADDR *, struct dbr_grDouble *);
static long get_control_double(DBADDR *, struct dbr_ctrlDouble *);
static long get_alarm_double(DBADDR *, struct dbr_alDouble *);

rset subRSET={
    RSETNUMBER,
    report,
    initialize,
    init_record,
    process,
    special,
    get_value,
    cvt_dbaddr,
    get_array_info,
    put_array_info,
    get_units,
    get_precision,
    get_enum_str,
    get_enum_strs,
    put_enum_str,
    get_graphic_double,
    get_control_double,
    get_alarm_double
};
epicsExportAddress(rset, subRSET);

static void checkAlarms(subRecord *);
static long do_sub(subRecord *);
static long fetch_values(subRecord *);
static void monitor(subRecord *);

#define INP_ARG_MAX 12

static long init_record(subRecord *prec, int pass)
{
    SUBFUNCPTR psubroutine;
    long status = 0;
    struct link *plink;
    int i;
    double *pvalue;

    if (pass==0) return(0);

    plink = &prec->inpa;
    pvalue = &prec->a;
    for (i = 0; i < INP_ARG_MAX; i++, plink++, pvalue++) {
        if (plink->type == CONSTANT) {
            recGblInitConstantLink(plink, DBF_DOUBLE, pvalue);
        }
    }

    if (prec->inam[0]) {
        /* convert the initialization subroutine name  */
        psubroutine = (SUBFUNCPTR)registryFunctionFind(prec->inam);
        if (psubroutine == 0) {
            recGblRecordError(S_db_BadSub, (void *)prec, "recSub(init_record)");
            return S_db_BadSub;
        }
        /* invoke the initialization subroutine */
        status = (*psubroutine)(prec);
    }

    if (prec->snam[0] == 0) {
        epicsPrintf("%s.SNAM is empty\n", prec->name);
        prec->pact = TRUE;
        return 0;
    }
    prec->sadr = (SUBFUNCPTR)registryFunctionFind(prec->snam);
    if (prec->sadr == NULL) {
        recGblRecordError(S_db_BadSub, (void *)prec, "recSub(init_record)");
        return S_db_BadSub;
    }
    prec->mlst = prec->val;
    prec->alst = prec->val;
    prec->lalm = prec->val;
    return 0;
}

static long process(subRecord *prec)
{
    long status = 0;
    int pact = prec->pact;

    if (!pact) {
        prec->pact = TRUE;
        status = fetch_values(prec);
        prec->pact = FALSE;
    }
    if (status == 0) status = do_sub(prec);

    /* Is subroutine asynchronous? */
    if (!pact && prec->pact) return 0;
    prec->pact = TRUE;

    /* Asynchronous function (documented API!) */
    if (status == 1) return 0;

    recGblGetTimeStamp(prec);

    /* check for alarms */
    checkAlarms(prec);

    /* publish changes */
    monitor(prec);

    recGblFwdLink(prec);
    prec->pact = FALSE;

    return 0;
}

static long special(DBADDR *paddr, int after)
{
    subRecord *prec = (subRecord *)paddr->precord;

    if (!after) {
        if (prec->snam[0] == 0 && prec->pact)
            prec->pact = FALSE;
            prec->rpro = FALSE;
        return 0;
    }

    if (prec->snam[0] == 0) {
        epicsPrintf("%s.SNAM is empty\n", prec->name);
        prec->pact = TRUE;
        return 0;
    }

    prec->sadr = (SUBFUNCPTR)registryFunctionFind(prec->snam);
    if (prec->sadr) return 0;

    recGblRecordError(S_db_BadSub, (void *)prec,
            "subRecord(special) registryFunctionFind failed");
    return S_db_BadSub;
}

static long get_units(DBADDR *paddr, char *units)
{
    subRecord *prec = (subRecord *)paddr->precord;

    strncpy(units, prec->egu, DB_UNITS_SIZE);
    return 0;
}

static long get_precision(DBADDR *paddr, long *precision)
{
    subRecord *prec = (subRecord *)paddr->precord;
    int fieldIndex = dbGetFieldIndex(paddr);

    *precision = prec->prec;
    if (fieldIndex != subRecordVAL)
        recGblGetPrec(paddr, precision);

    return 0;
}


static long get_graphic_double(DBADDR *paddr, struct dbr_grDouble *pgd)
{
    subRecord *prec = (subRecord *)paddr->precord;
    int fieldIndex = dbGetFieldIndex(paddr);

    switch (fieldIndex) {
    case subRecordVAL:
    case subRecordHIHI:     case subRecordHIGH:
    case subRecordLOW:      case subRecordLOLO:
    case subRecordA:        case subRecordB:
    case subRecordC:        case subRecordD:
    case subRecordE:        case subRecordF:
    case subRecordG:        case subRecordH:
    case subRecordI:        case subRecordJ:
    case subRecordK:        case subRecordL:
    case subRecordLA:       case subRecordLB:
    case subRecordLC:       case subRecordLD:
    case subRecordLE:       case subRecordLF:
    case subRecordLG:       case subRecordLH:
    case subRecordLI:       case subRecordLJ:
    case subRecordLK:       case subRecordLL:
        pgd->upper_disp_limit = prec->hopr;
        pgd->lower_disp_limit = prec->lopr;
        break;

    default:
        recGblGetGraphicDouble(paddr, pgd);
    }
    return 0;
}

static long get_control_double(DBADDR *paddr, struct dbr_ctrlDouble *pcd)
{
    subRecord *prec = (subRecord *)paddr->precord;
    int fieldIndex = dbGetFieldIndex(paddr);

    switch (fieldIndex) {
    case subRecordVAL:
    case subRecordHIHI:     case subRecordHIGH:
    case subRecordLOW:      case subRecordLOLO:
    case subRecordA:        case subRecordB:
    case subRecordC:        case subRecordD:
    case subRecordE:        case subRecordF:
    case subRecordG:        case subRecordH:
    case subRecordI:        case subRecordJ:
    case subRecordK:        case subRecordL:
        pcd->upper_ctrl_limit = prec->hopr;
        pcd->lower_ctrl_limit = prec->lopr;
        break;

    default:
        recGblGetControlDouble(paddr, pcd);
    }
    return 0;
}

static long get_alarm_double(DBADDR *paddr, struct dbr_alDouble *pad)
{
    subRecord *prec = (subRecord *)paddr->precord;
    int fieldIndex = dbGetFieldIndex(paddr);

    if (fieldIndex == subRecordVAL) {
        pad->upper_alarm_limit = prec->hhsv ? prec->hihi : epicsNAN;
        pad->upper_warning_limit = prec->hsv ? prec->high : epicsNAN;
        pad->lower_warning_limit = prec->lsv ? prec->low : epicsNAN;
        pad->lower_alarm_limit = prec->llsv ? prec->lolo : epicsNAN;
    } else {
        recGblGetAlarmDouble(paddr, pad);
    }
    return 0;
}

static void checkAlarms(subRecord *prec)
{
    double val, hyst, lalm;
    double alev;
    epicsEnum16 asev;

    if (prec->udf) {
        recGblSetSevr(prec, UDF_ALARM, INVALID_ALARM);
        return;
    }

    val = prec->val;
    hyst = prec->hyst;
    lalm = prec->lalm;

    /* alarm condition hihi */
    asev = prec->hhsv;
    alev = prec->hihi;
    if (asev && (val >= alev || ((lalm == alev) && (val >= alev - hyst)))) {
        if (recGblSetSevr(prec, HIHI_ALARM, asev))
            prec->lalm = alev;
        return;
    }

    /* alarm condition lolo */
    asev = prec->llsv;
    alev = prec->lolo;
    if (asev && (val <= alev || ((lalm == alev) && (val <= alev + hyst)))) {
        if (recGblSetSevr(prec, LOLO_ALARM, asev))
            prec->lalm = alev;
        return;
    }

    /* alarm condition high */
    asev = prec->hsv;
    alev = prec->high;
    if (asev && (val >= alev || ((lalm == alev) && (val >= alev - hyst)))) {
        if (recGblSetSevr(prec, HIGH_ALARM, asev))
            prec->lalm = alev;
        return;
    }

    /* alarm condition low */
    asev = prec->lsv;
    alev = prec->low;
    if (asev && (val <= alev || ((lalm == alev) && (val <= alev + hyst)))) {
        if (recGblSetSevr(prec, LOW_ALARM, asev))
            prec->lalm = alev;
        return;
    }

    /* we get here only if val is out of alarm by at least hyst */
    prec->lalm = val;
    return;
}

static void monitor(subRecord *prec)
{
    unsigned monitor_mask;
    double delta;
    double *pnew;
    double *pold;
    int i;

    /* get alarm mask */
    monitor_mask = recGblResetAlarms(prec);
    /* check for value change */
    delta = prec->val - prec->mlst;
    if (delta < 0.0) delta = -delta;
    if (!(delta <= prec->mdel)) { /* Handles MDEL == NAN */
        /* post events for value change */
        monitor_mask |= DBE_VALUE;
        /* update last value monitored */
        prec->mlst = prec->val;
    }
    /* check for archive change */
    delta = prec->val - prec->alst;
    if (delta < 0.0) delta = -delta;
    if (!(delta <= prec->adel)) { /* Handles ADEL == NAN */
        /* post events on value field for archive change */
        monitor_mask |= DBE_LOG;
        /* update last archive value monitored */
        prec->alst = prec->val;
    }
    /* send out monitors connected to the value field */
    if (monitor_mask) {
        db_post_events(prec, &prec->val, monitor_mask);
    }
    /* check all input fields for changes */
    for (i = 0, pnew = &prec->a, pold = &prec->la;
         i < INP_ARG_MAX; i++, pnew++, pold++) {
        if (*pnew != *pold) {
            db_post_events(prec, pnew, monitor_mask | DBE_VALUE | DBE_LOG);
            *pold = *pnew;
        }
    }
    return;
}

static long fetch_values(subRecord *prec)
{
    struct link *plink = &prec->inpa;
    double *pvalue = &prec->a;
    int i;

    for (i = 0; i < INP_ARG_MAX; i++, plink++, pvalue++) {
        if (dbGetLink(plink, DBR_DOUBLE, pvalue, 0, 0))
            return -1;
    }
    return 0;
}

static long do_sub(subRecord *prec)
{
    SUBFUNCPTR psubroutine = prec->sadr;
    long status;

    if (psubroutine == NULL) {
        recGblSetSevr(prec, BAD_SUB_ALARM, INVALID_ALARM);
        return 0;
    }

    status = (*psubroutine)(prec);
    if (status < 0) {
        recGblSetSevr(prec, SOFT_ALARM, prec->brsv);
    } else {
        prec->udf = isnan(prec->val);
    }
    return status;
}
