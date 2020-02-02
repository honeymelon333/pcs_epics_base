/*************************************************************************\
* Copyright (c) 2002 The University of Chicago, as Operator of Argonne
*     National Laboratory.
* Copyright (c) 2002 The Regents of the University of California, as
*     Operator of Los Alamos National Laboratory.
* EPICS BASE Versions 3.13.7
* and higher are distributed subject to a Software License Agreement found
* in file LICENSE that is included with this distribution. 
\*************************************************************************/

/*  
 *  Revision-Id: anj@aps.anl.gov-20101005192737-disfz3vs0f3fiixd
 *
 *                              
 *                    L O S  A L A M O S
 *              Los Alamos National Laboratory
 *               Los Alamos, New Mexico 87545
 *                                  
 *  Copyright, 1986, The Regents of the University of California.
 *                                  
 *           
 *	Author Jeffrey O. Hill
 *	johill@lanl.gov
 *	505 665 1831
 */

#define epicsExportSharedSymbols

#include "dbCAC.h"
#include "dbChannelIO.h"
#include "dbPutNotifyBlocker.h"

#ifdef _MSC_VER
#   pragma warning ( push )
#   pragma warning ( disable:4660 )
#endif

template class tsFreeList < dbChannelIO, 256, epicsMutexNOOP >;
template class tsFreeList < dbPutNotifyBlocker, 64, epicsMutexNOOP >;
template class tsFreeList < dbSubscriptionIO, 256, epicsMutexNOOP >;
template class resTable < dbBaseIO, chronIntId >;
template class chronIntIdResTable < dbBaseIO >;

#ifdef _MSC_VER
#   pragma warning ( pop )
#endif
