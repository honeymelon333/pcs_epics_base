/*************************************************************************\
* Copyright (c) 2002 The University of Chicago, as Operator of Argonne
*     National Laboratory.
* Copyright (c) 2002 The Regents of the University of California, as
*     Operator of Los Alamos National Laboratory.
* EPICS BASE is distributed subject to a Software License Agreement found
* in file LICENSE that is included with this distribution. 
\*************************************************************************/

/*
 * Revision-Id: anj@aps.anl.gov-20120514161633-fhizyzdnqaez8wwg
 *
 *  Author: Jeffrey O. Hill
 *      hill@luke.lanl.gov
 *      (505) 665 1831
 *  Date:   5-88
 */

#ifndef rsrvh
#define rsrvh

#include "shareLib.h"

epicsShareFunc int rsrv_init(void);
epicsShareFunc int rsrv_run(void);
epicsShareFunc int rsrv_pause(void);

epicsShareFunc void epicsShareAPI casr (unsigned level);
epicsShareFunc void epicsShareAPI casHostNameInitiatingCurrentThread (
                        char * pBuf, unsigned bufSize );
epicsShareFunc void epicsShareAPI casUserNameInitiatingCurrentThread (
                        char * pBuf, unsigned bufSize );
epicsShareFunc void casStatsFetch (
                        unsigned *pChanCount, unsigned *pConnCount );

#define RSRV_OK 0
#define RSRV_ERROR (-1)

#endif /*rsrvh */
