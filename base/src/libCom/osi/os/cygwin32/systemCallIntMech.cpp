
/*************************************************************************\
* Copyright (c) 2002 The University of Chicago, as Operator of Argonne
*     National Laboratory.
* Copyright (c) 2002 The Regents of the University of California, as
*     Operator of Los Alamos National Laboratory.
* EPICS BASE Versions 3.13.7
* and higher are distributed subject to a Software License Agreement found
* in file LICENSE that is included with this distribution. 
\*************************************************************************/
/* Revision-Id: anj@aps.anl.gov-20131120004103-rrs4qf6hlp20naol */
/*
 *      Author:		Jeff Hill 
 */

#include <cygwin/version.h>

#define epicsExportSharedSymbols
#include "osiSock.h"

enum epicsSocketSystemCallInterruptMechanismQueryInfo 
        epicsSocketSystemCallInterruptMechanismQuery ()
{
#if 0
    // Some broken versions of cygwin needed this:
    return esscimqi_socketCloseRequired;
#else
    return esscimqi_socketBothShutdownRequired;
#endif
}
