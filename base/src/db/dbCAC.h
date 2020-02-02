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
 *  Revision-Id: johill@lanl.gov-20130516183331-ccgep7u4xccqzaw3
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
 *
 * NOTES:
 * 1) This interface is preliminary and will change in the future
 */

#ifndef dbCACh
#define dbCACh

#ifdef epicsExportSharedSymbols
#   define dbCACh_restore_epicsExportSharedSymbols
#   undef epicsExportSharedSymbols
#endif

#include "tsDLList.h"
#include "tsFreeList.h"
#include "resourceLib.h"
#include "cacIO.h"
#include "compilerDependencies.h"
#include "epicsMemory.h"

#ifdef dbCACh_restore_epicsExportSharedSymbols
#   define epicsExportSharedSymbols
#   include "shareLib.h"
#endif

#include "db_access.h"
#include "dbNotify.h"
#include "dbEvent.h"
#include "dbAddr.h"
#include "dbLock.h"
#include "dbCommon.h"
#include "db_convert.h"
#include "resourceLib.h"

extern "C" void putNotifyCompletion ( putNotify *ppn );

class dbContext;
class dbChannelIO;
class dbPutNotifyBlocker;
class dbSubscriptionIO;

class dbBaseIO
    : public chronIntIdRes < dbBaseIO > {
public:
    virtual dbSubscriptionIO * isSubscription () = 0;
    virtual void show ( epicsGuard < epicsMutex > &, unsigned level ) const = 0;
    virtual void show ( unsigned level ) const = 0;
    dbBaseIO ();
    dbBaseIO ( const dbBaseIO & );
    dbBaseIO & operator = ( const dbBaseIO & );
protected:
    virtual ~dbBaseIO() {}
};

extern "C" void dbSubscriptionEventCallback ( void *pPrivate, struct dbAddr *paddr,
    int eventsRemaining, struct db_field_log *pfl );

class dbSubscriptionIO : 
    public tsDLNode < dbSubscriptionIO >, 
    public dbBaseIO {
public:
    dbSubscriptionIO ( 
        epicsGuard < epicsMutex > &, epicsMutex &,
        dbContext &, dbChannelIO &, struct dbAddr &, cacStateNotify &, 
        unsigned type, unsigned long count, unsigned mask, dbEventCtx );
    void destructor ( CallbackGuard &, epicsGuard < epicsMutex > & );
    void unsubscribe ( CallbackGuard &, epicsGuard < epicsMutex > & );
    void channelDeleteException ( CallbackGuard &, epicsGuard < epicsMutex > & );
    void show ( epicsGuard < epicsMutex > &, unsigned level ) const;
    void show ( unsigned level ) const;
    void * operator new ( size_t size, 
        tsFreeList < dbSubscriptionIO, 256, epicsMutexNOOP > & );
    epicsPlacementDeleteOperator (( void *, 
        tsFreeList < dbSubscriptionIO, 256, epicsMutexNOOP > & ))
private:
    epicsMutex & mutex;
    unsigned long count;
    cacStateNotify & notify;
    dbChannelIO & chan;
    dbEventSubscription es;
    unsigned type;
    unsigned id;
    dbSubscriptionIO * isSubscription ();
    friend void dbSubscriptionEventCallback ( 
        void * pPrivate, struct dbAddr * paddr,
        int eventsRemaining, struct db_field_log * pfl );
    dbSubscriptionIO ( const dbSubscriptionIO & );
    dbSubscriptionIO & operator = ( const dbSubscriptionIO & );
    virtual ~dbSubscriptionIO ();
    void operator delete ( void * );
};

class dbContext;

class dbContextPrivateListOfIO {
public:
    dbContextPrivateListOfIO ();
    ~dbContextPrivateListOfIO ();
private:
    tsDLList < dbSubscriptionIO > eventq;
    dbPutNotifyBlocker * pBlocker;
    friend class dbContext;
    dbContextPrivateListOfIO ( const dbContextPrivateListOfIO & );
    dbContextPrivateListOfIO & operator = ( const dbContextPrivateListOfIO & );
};

class dbContextReadNotifyCacheAllocator  {
public:
    dbContextReadNotifyCacheAllocator ();
    ~dbContextReadNotifyCacheAllocator ();
    char * alloc ( unsigned long size );
    void free ( char * pFree );
    void show ( unsigned level ) const;
private:
    struct cacheElem_t {
        struct cacheElem_t * pNext;
    };
    unsigned long _readNotifyCacheSize;
    cacheElem_t * _pReadNotifyCache;
    void reclaimAllCacheEntries ();
    dbContextReadNotifyCacheAllocator ( const dbContextReadNotifyCacheAllocator & );
    dbContextReadNotifyCacheAllocator & operator = ( const dbContextReadNotifyCacheAllocator & );
};

class dbContextReadNotifyCache  {
public:
    dbContextReadNotifyCache ( epicsMutex & );
    void callReadNotify ( epicsGuard < epicsMutex > &, 
        struct dbAddr & addr, unsigned type, unsigned long count, 
            cacReadNotify & notify );
    void show ( epicsGuard < epicsMutex > &, unsigned level ) const;
private:
    dbContextReadNotifyCacheAllocator _allocator;
    epicsMutex & _mutex;
    dbContextReadNotifyCache ( const dbContextReadNotifyCache & );
    dbContextReadNotifyCache & operator = ( const dbContextReadNotifyCache & );
};

class dbContext : public cacContext {
public:
    dbContext ( epicsMutex & cbMutex, epicsMutex & mutex, 
        cacContextNotify & notify );
    virtual ~dbContext ();
    void destroyChannel ( CallbackGuard &,epicsGuard < epicsMutex > &, dbChannelIO & );
    void callReadNotify ( epicsGuard < epicsMutex > &, 
            struct dbAddr & addr, unsigned type, unsigned long count, 
            cacReadNotify & notify );
    void callStateNotify ( struct dbAddr &addr, unsigned type, unsigned long count, 
            const struct db_field_log * pfl, cacStateNotify & notify );
    void subscribe ( 
            epicsGuard < epicsMutex > &,
            struct dbAddr & addr, dbChannelIO & chan,
            unsigned type, unsigned long count, unsigned mask, 
            cacStateNotify & notify, cacChannel::ioid * pId );
    void initiatePutNotify ( 
            epicsGuard < epicsMutex > &, dbChannelIO &, struct dbAddr &, 
            unsigned type, unsigned long count, const void * pValue, 
            cacWriteNotify & notify, cacChannel::ioid * pId ); 
    void show ( unsigned level ) const;
    void showAllIO ( const dbChannelIO & chan, unsigned level ) const;
    void destroyAllIO ( CallbackGuard & cbGuard,
        epicsGuard < epicsMutex > &, dbChannelIO & chan );
    void ioCancel ( CallbackGuard &, epicsGuard < epicsMutex > &,
        dbChannelIO & chan, const cacChannel::ioid &id );
    void ioShow ( epicsGuard < epicsMutex > &,
        const cacChannel::ioid & id, unsigned level ) const;
private:
    tsFreeList < dbPutNotifyBlocker, 64, epicsMutexNOOP > dbPutNotifyBlockerFreeList;
    tsFreeList < dbSubscriptionIO, 256, epicsMutexNOOP > dbSubscriptionIOFreeList;
    tsFreeList < dbChannelIO, 256, epicsMutexNOOP > dbChannelIOFreeList;
    chronIntIdResTable < dbBaseIO > ioTable;
    dbContextReadNotifyCache readNotifyCache;
    dbEventCtx ctx;
    unsigned long stateNotifyCacheSize;
    epicsMutex & mutex;
    epicsMutex & cbMutex;
    cacContextNotify & notify;
    epics_auto_ptr < cacContext > pNetContext;
    char * pStateNotifyCache;

    cacChannel & createChannel ( 
        epicsGuard < epicsMutex > &,
        const char * pChannelName, cacChannelNotify &, 
        cacChannel::priLev );
    void flush ( 
        epicsGuard < epicsMutex > & );
    unsigned circuitCount (
        epicsGuard < epicsMutex > & ) const;
    void selfTest (
        epicsGuard < epicsMutex > & ) const;
    unsigned beaconAnomaliesSinceProgramStart (
        epicsGuard < epicsMutex > & ) const;
    void show ( 
        epicsGuard < epicsMutex > &, unsigned level ) const;

    dbContext ( const dbContext & );
    dbContext & operator = ( const dbContext & );
};

inline dbContextPrivateListOfIO::dbContextPrivateListOfIO () :
    pBlocker ( 0 )
{
}

inline dbContextPrivateListOfIO::~dbContextPrivateListOfIO () 
{
    assert ( ! this->pBlocker );
}

inline void dbContext::callReadNotify ( 
    epicsGuard < epicsMutex > & guard, struct dbAddr &addr, 
    unsigned type, unsigned long count, cacReadNotify & notifyIn )
{
    guard.assertIdenticalMutex ( this-> mutex );
    this->readNotifyCache.callReadNotify ( guard, addr, type, count, notifyIn );
}

#endif // dbCACh

