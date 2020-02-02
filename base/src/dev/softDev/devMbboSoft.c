/*************************************************************************\
* Copyright (c) 2002 The University of Chicago, as Operator of Argonne
*     National Laboratory.
* Copyright (c) 2002 The Regents of the University of California, as
*     Operator of Los Alamos National Laboratory.
* EPICS BASE Versions 3.13.7
* and higher are distributed subject to a Software License Agreement found
* in file LICENSE that is included with this distribution. 
\*************************************************************************/
/* devMbboSoft.c */
/* base/src/dev Revision-Id: anj@aps.anl.gov-20101005192737-disfz3vs0f3fiixd */
/*
 *      Original Author: Bob Dalesio
 *      Current Author:  Marty Kraimer
 *      Date:            6-1-90
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "alarm.h"
#include "dbDefs.h"
#include "dbAccess.h"
#include "recGbl.h"
#include "recSup.h"
#include "devSup.h"
#include "mbboRecord.h"
#include "epicsExport.h"

/* Create the dset for devMbboSoft */
static long init_record(mbboRecord *prec);
static long write_mbbo(mbboRecord *prec);
struct {
	long		number;
	DEVSUPFUN	report;
	DEVSUPFUN	init;
	DEVSUPFUN	init_record;
	DEVSUPFUN	get_ioint_info;
	DEVSUPFUN	write_mbbo;
}devMbboSoft={
	5,
	NULL,
	NULL,
	init_record,
	NULL,
	write_mbbo
};
epicsExportAddress(dset,devMbboSoft);

static long init_record(mbboRecord *prec)
{
 
    long status=0;
 
    /*dont convert*/
    status=2;
    return status;
 
} /* end init_record() */

static long write_mbbo(mbboRecord *prec)
{
    long status;

    status = dbPutLink(&prec->out,DBR_USHORT, &prec->val,1);
    return(0);
}
