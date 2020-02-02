/*************************************************************************\
* Copyright (c) 2002 Southeastern Universities Research Association, as
*     Operator of Thomas Jefferson National Accelerator Facility.
* EPICS BASE is distributed subject to a Software License Agreement found
* in file LICENSE that is included with this distribution. 
\*************************************************************************/

/* Revision-Id: anj@aps.anl.gov-20131120222110-3o0wgh76u652ad4e */

/* recDfanout.c - Record Support Routines for Dfanout records */
/*
 * Original Author: 	Matt Bickley   (Sometime in 1994)
 *
 * Modification Log:
 * -----------------
 * .01  1994        mhb     Started with longout record to make the data fanout
 * .02  May 10, 96  jt	    Bug Fix
 * .03  11SEP2000   mrk     LONG=>DOUBLE, add SELL,SELN,SELM
 */


#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "dbDefs.h"
#include "epicsPrint.h"
#include "epicsMath.h"
#include "alarm.h"
#include "dbAccess.h"
#include "dbEvent.h"
#include "dbFldTypes.h"
#include "devSup.h"
#include "errMdef.h"
#include "recSup.h"
#include "recGbl.h"
#include "special.h"
#include "menuOmsl.h"

#define GEN_SIZE_OFFSET
#include "dfanoutRecord.h"
#undef  GEN_SIZE_OFFSET
#include "epicsExport.h"

/* Create RSET - Record Support Entry Table*/
#define report NULL
#define initialize NULL
static long init_record(dfanoutRecord *, int);
static long process(dfanoutRecord *);
#define special NULL
#define get_value NULL
#define cvt_dbaddr NULL
#define get_array_info NULL
#define put_array_info NULL
static long get_units(DBADDR *, char *);
static long get_precision(DBADDR *, long *);
#define get_enum_str NULL
#define get_enum_strs NULL
#define put_enum_str NULL
static long get_graphic_double(DBADDR *,struct dbr_grDouble *);
static long get_control_double(DBADDR *,struct dbr_ctrlDouble *);
static long get_alarm_double(DBADDR *,struct dbr_alDouble *);

rset dfanoutRSET={
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
epicsExportAddress(rset,dfanoutRSET);


static void checkAlarms(dfanoutRecord *);
static void monitor(dfanoutRecord *);
static void push_values(dfanoutRecord *);

#define OUT_ARG_MAX 8


static long init_record(dfanoutRecord *prec, int pass)
{
    if (pass==0) return(0);

    recGblInitConstantLink(&prec->sell,DBF_USHORT,&prec->seln);
    /* get the initial value dol is a constant*/
    if(recGblInitConstantLink(&prec->dol,DBF_DOUBLE,&prec->val))
	    prec->udf = isnan(prec->val);
    return(0);
}

static long process(dfanoutRecord *prec)
{
    long status=0;

    if (!prec->pact
    && (prec->dol.type != CONSTANT)
    && (prec->omsl == menuOmslclosed_loop)){
	status = dbGetLink(&(prec->dol),DBR_DOUBLE,&(prec->val),0,0);
	if(prec->dol.type!=CONSTANT && RTN_SUCCESS(status))
            prec->udf = isnan(prec->val);
    }
    prec->pact = TRUE;
    recGblGetTimeStamp(prec);
    /* Push out the data to all the forward links */
    dbGetLink(&(prec->sell),DBR_USHORT,&(prec->seln),0,0);
    checkAlarms(prec);
    push_values(prec);
    monitor(prec);
    recGblFwdLink(prec);
    prec->pact=FALSE;
    return(status);
}

static long get_units(DBADDR *paddr,char *units)
{
    dfanoutRecord *prec=(dfanoutRecord *)paddr->precord;

    strncpy(units,prec->egu,DB_UNITS_SIZE);
    return(0);
}

static long get_precision(DBADDR *paddr,long *precision)
{
    dfanoutRecord *prec=(dfanoutRecord *)paddr->precord;
    int   fieldIndex = dbGetFieldIndex(paddr);

    if(fieldIndex == dfanoutRecordVAL
    || fieldIndex == dfanoutRecordHIHI
    || fieldIndex == dfanoutRecordHIGH
    || fieldIndex == dfanoutRecordLOW
    || fieldIndex == dfanoutRecordLOLO
    || fieldIndex == dfanoutRecordHOPR
    || fieldIndex == dfanoutRecordLOPR) {
        *precision = prec->prec;
    } else {
        recGblGetPrec(paddr,precision);
    }
    return(0);
}

static long get_graphic_double(DBADDR *paddr,struct dbr_grDouble	*pgd)
{
    dfanoutRecord *prec=(dfanoutRecord *)paddr->precord;
    int   fieldIndex = dbGetFieldIndex(paddr);

    if(fieldIndex == dfanoutRecordVAL
    || fieldIndex == dfanoutRecordHIHI
    || fieldIndex == dfanoutRecordHIGH
    || fieldIndex == dfanoutRecordLOW
    || fieldIndex == dfanoutRecordLOLO
    || fieldIndex == dfanoutRecordHOPR
    || fieldIndex == dfanoutRecordLOPR) {
        pgd->upper_disp_limit = prec->hopr;
        pgd->lower_disp_limit = prec->lopr;
    } else recGblGetGraphicDouble(paddr,pgd);
    return(0);
}

static long get_control_double(DBADDR *paddr,struct dbr_ctrlDouble *pcd)
{
    dfanoutRecord *prec=(dfanoutRecord *)paddr->precord;
    int   fieldIndex = dbGetFieldIndex(paddr);

    if(fieldIndex == dfanoutRecordVAL
    || fieldIndex == dfanoutRecordHIHI
    || fieldIndex == dfanoutRecordHIGH
    || fieldIndex == dfanoutRecordLOW
    || fieldIndex == dfanoutRecordLOLO) {
        pcd->upper_ctrl_limit = prec->hopr;
        pcd->lower_ctrl_limit = prec->lopr;
    } else recGblGetControlDouble(paddr,pcd);
    return(0);
}
static long get_alarm_double(DBADDR *paddr,struct dbr_alDouble *pad)
{
    dfanoutRecord *prec=(dfanoutRecord *)paddr->precord;
    int   fieldIndex = dbGetFieldIndex(paddr);

    
    if(fieldIndex == dfanoutRecordVAL) {
        pad->upper_alarm_limit = prec->hhsv ? prec->hihi : epicsNAN;
        pad->upper_warning_limit = prec->hsv ? prec->high : epicsNAN;
        pad->lower_warning_limit = prec->lsv ? prec->low : epicsNAN;
        pad->lower_alarm_limit = prec->llsv ? prec->lolo : epicsNAN;
    } else recGblGetAlarmDouble(paddr,pad);
    return(0);
}

static void checkAlarms(dfanoutRecord *prec)
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

static void monitor(dfanoutRecord *prec)
{
	unsigned short	monitor_mask;

	double		delta;

        monitor_mask = recGblResetAlarms(prec);
        /* check for value change */
        delta = prec->mlst - prec->val;
        if(delta<0) delta = -delta;
        if (!(delta <= prec->mdel)) { /* Handles MDEL == NAN */
                /* post events for value change */
                monitor_mask |= DBE_VALUE;
                /* update last value monitored */
                prec->mlst = prec->val;
        }
        /* check for archive change */
        delta = prec->alst - prec->val;
        if(delta<0) delta = -delta;
        if (!(delta <= prec->adel)) { /* Handles ADEL == NAN */
                /* post events on value field for archive change */
                monitor_mask |= DBE_LOG;
                /* update last archive value monitored */
                prec->alst = prec->val;
        }

        /* send out monitors connected to the value field */
        if (monitor_mask){
                db_post_events(prec,&prec->val,monitor_mask);
	}
	return;
}

static void push_values(dfanoutRecord *prec)
{
    struct link     *plink; /* structure of the link field  */
    int             i;
    long            status;
    unsigned short  state;

    switch (prec->selm){
    case (dfanoutSELM_All):
        for(i=0, plink=&(prec->outa); i<OUT_ARG_MAX; i++, plink++) {
                status=dbPutLink(plink,DBR_DOUBLE,&(prec->val),1);
                if(status) recGblSetSevr(prec,LINK_ALARM,MAJOR_ALARM);
        }
        break;
    case (dfanoutSELM_Specified):
        if(prec->seln>OUT_ARG_MAX) {
            recGblSetSevr(prec,SOFT_ALARM,INVALID_ALARM);
            break;
        }
        if(prec->seln==0) break;
        plink=&(prec->outa);
        plink += (prec->seln -1);
        status=dbPutLink(plink,DBR_DOUBLE,&(prec->val),1);
        if(status) recGblSetSevr(prec,LINK_ALARM,MAJOR_ALARM);
        break;
    case (dfanoutSELM_Mask):
        if(prec->seln==0) break;
        for(i=0, plink=&(prec->outa), state=prec->seln;
        i<OUT_ARG_MAX;
        i++, plink++, state>>=1) {
            if(state&1) {
                status=dbPutLink(plink,DBR_DOUBLE,&(prec->val),1);
                if(status) recGblSetSevr(prec,LINK_ALARM,MAJOR_ALARM);
            }
        }
        break;
    default:
        recGblSetSevr(prec,SOFT_ALARM,INVALID_ALARM);
    }

}
