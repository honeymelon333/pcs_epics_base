/*************************************************************************\
* Copyright (c) 2002 The University of Chicago, as Operator of Argonne
*     National Laboratory.
* Copyright (c) 2002 The Regents of the University of California, as
*     Operator of Los Alamos National Laboratory.
* EPICS BASE Versions 3.13.7
* and higher are distributed subject to a Software License Agreement found
* in file LICENSE that is included with this distribution. 
\*************************************************************************/
/* devHistogramSoft.c */
/* base/src/dev Revision-Id: anj@aps.anl.gov-20101005192737-disfz3vs0f3fiixd */
/*
 *      Author:		Janet Anderson
 *      Date:		07/02/91
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "alarm.h"
#include "cvtTable.h"
#include "dbDefs.h"
#include "dbAccess.h"
#include "recGbl.h"
#include "recSup.h"
#include "devSup.h"
#include "link.h"
#include "histogramRecord.h"
#include "epicsExport.h"

/* Create the dset for devHistogramSoft */
static long init_record(histogramRecord *prec);
static long read_histogram(histogramRecord *prec);
struct {
	long		number;
	DEVSUPFUN	report;
	DEVSUPFUN	init;
	DEVSUPFUN	init_record;
	DEVSUPFUN	get_ioint_info;
	DEVSUPFUN	read_histogram;
	DEVSUPFUN	special_linconv;
}devHistogramSoft={
	6,
	NULL,
	NULL,
	init_record,
	NULL,
	read_histogram,
	NULL
};
epicsExportAddress(dset,devHistogramSoft);

static long init_record(histogramRecord	*prec)
{
    long status = 0;

    /* histogram.svl must be a CONSTANT or a PV_LINK or a DB_LINK or a CA_LINK*/
    switch (prec->svl.type) {
    case (CONSTANT) :
        if(recGblInitConstantLink(&prec->svl,DBF_DOUBLE,&prec->sgnl))
            prec->udf = FALSE;
	break;
    case (PV_LINK) :
    case (DB_LINK) :
    case (CA_LINK) :
	break;
    default :
	recGblRecordError(S_db_badField,(void *)prec,
		"devHistogramSoft (init_record) Illegal SVL field");
	return(S_db_badField);
    }
    return(status);
}

static long read_histogram(histogramRecord *prec)
{
    long status;

    status = dbGetLink(&prec->svl,DBR_DOUBLE, &prec->sgnl,0,0);
    return(0); /*add count*/
}
