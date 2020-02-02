/*************************************************************************\
* Copyright (c) 2002 The University of Saskatchewan
* EPICS BASE is distributed subject to a Software License Agreement found
* in file LICENSE that is included with this distribution. 
\*************************************************************************/
/*
 * Revision-Id: anj@aps.anl.gov-20101005192737-disfz3vs0f3fiixd
 *
 * Author: Eric Norum
 */

#ifndef osdTimeh
#define osdTimeh

#include <sys/time.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

epicsShareFunc void convertDoubleToWakeTime(double timeout,
    struct timespec *wakeTime);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ifndef osdTimeh */

