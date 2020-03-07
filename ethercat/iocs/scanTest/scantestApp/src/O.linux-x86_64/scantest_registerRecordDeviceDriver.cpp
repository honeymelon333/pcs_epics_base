/* THIS IS A GENERATED FILE. DO NOT EDIT! */
/* Generated from ../O.Common/scantest.dbd */

#include <string.h>

#include "epicsStdlib.h"
#include "iocsh.h"
#include "iocshRegisterCommon.h"
#include "registryCommon.h"

extern "C" {

epicsShareExtern rset *pvar_rset_aaiRSET;
epicsShareExtern int (*pvar_func_aaiRecordSizeOffset)(dbRecordType *pdbRecordType);
epicsShareExtern rset *pvar_rset_aaoRSET;
epicsShareExtern int (*pvar_func_aaoRecordSizeOffset)(dbRecordType *pdbRecordType);
epicsShareExtern rset *pvar_rset_aiRSET;
epicsShareExtern int (*pvar_func_aiRecordSizeOffset)(dbRecordType *pdbRecordType);
epicsShareExtern rset *pvar_rset_aoRSET;
epicsShareExtern int (*pvar_func_aoRecordSizeOffset)(dbRecordType *pdbRecordType);
epicsShareExtern rset *pvar_rset_aSubRSET;
epicsShareExtern int (*pvar_func_aSubRecordSizeOffset)(dbRecordType *pdbRecordType);
epicsShareExtern rset *pvar_rset_biRSET;
epicsShareExtern int (*pvar_func_biRecordSizeOffset)(dbRecordType *pdbRecordType);
epicsShareExtern rset *pvar_rset_boRSET;
epicsShareExtern int (*pvar_func_boRecordSizeOffset)(dbRecordType *pdbRecordType);
epicsShareExtern rset *pvar_rset_calcRSET;
epicsShareExtern int (*pvar_func_calcRecordSizeOffset)(dbRecordType *pdbRecordType);
epicsShareExtern rset *pvar_rset_calcoutRSET;
epicsShareExtern int (*pvar_func_calcoutRecordSizeOffset)(dbRecordType *pdbRecordType);
epicsShareExtern rset *pvar_rset_compressRSET;
epicsShareExtern int (*pvar_func_compressRecordSizeOffset)(dbRecordType *pdbRecordType);
epicsShareExtern rset *pvar_rset_dfanoutRSET;
epicsShareExtern int (*pvar_func_dfanoutRecordSizeOffset)(dbRecordType *pdbRecordType);
epicsShareExtern rset *pvar_rset_eventRSET;
epicsShareExtern int (*pvar_func_eventRecordSizeOffset)(dbRecordType *pdbRecordType);
epicsShareExtern rset *pvar_rset_fanoutRSET;
epicsShareExtern int (*pvar_func_fanoutRecordSizeOffset)(dbRecordType *pdbRecordType);
epicsShareExtern rset *pvar_rset_longinRSET;
epicsShareExtern int (*pvar_func_longinRecordSizeOffset)(dbRecordType *pdbRecordType);
epicsShareExtern rset *pvar_rset_longoutRSET;
epicsShareExtern int (*pvar_func_longoutRecordSizeOffset)(dbRecordType *pdbRecordType);
epicsShareExtern rset *pvar_rset_mbbiRSET;
epicsShareExtern int (*pvar_func_mbbiRecordSizeOffset)(dbRecordType *pdbRecordType);
epicsShareExtern rset *pvar_rset_mbbiDirectRSET;
epicsShareExtern int (*pvar_func_mbbiDirectRecordSizeOffset)(dbRecordType *pdbRecordType);
epicsShareExtern rset *pvar_rset_mbboRSET;
epicsShareExtern int (*pvar_func_mbboRecordSizeOffset)(dbRecordType *pdbRecordType);
epicsShareExtern rset *pvar_rset_mbboDirectRSET;
epicsShareExtern int (*pvar_func_mbboDirectRecordSizeOffset)(dbRecordType *pdbRecordType);
epicsShareExtern rset *pvar_rset_permissiveRSET;
epicsShareExtern int (*pvar_func_permissiveRecordSizeOffset)(dbRecordType *pdbRecordType);
epicsShareExtern rset *pvar_rset_selRSET;
epicsShareExtern int (*pvar_func_selRecordSizeOffset)(dbRecordType *pdbRecordType);
epicsShareExtern rset *pvar_rset_seqRSET;
epicsShareExtern int (*pvar_func_seqRecordSizeOffset)(dbRecordType *pdbRecordType);
epicsShareExtern rset *pvar_rset_stateRSET;
epicsShareExtern int (*pvar_func_stateRecordSizeOffset)(dbRecordType *pdbRecordType);
epicsShareExtern rset *pvar_rset_stringinRSET;
epicsShareExtern int (*pvar_func_stringinRecordSizeOffset)(dbRecordType *pdbRecordType);
epicsShareExtern rset *pvar_rset_stringoutRSET;
epicsShareExtern int (*pvar_func_stringoutRecordSizeOffset)(dbRecordType *pdbRecordType);
epicsShareExtern rset *pvar_rset_subRSET;
epicsShareExtern int (*pvar_func_subRecordSizeOffset)(dbRecordType *pdbRecordType);
epicsShareExtern rset *pvar_rset_subArrayRSET;
epicsShareExtern int (*pvar_func_subArrayRecordSizeOffset)(dbRecordType *pdbRecordType);
epicsShareExtern rset *pvar_rset_waveformRSET;
epicsShareExtern int (*pvar_func_waveformRecordSizeOffset)(dbRecordType *pdbRecordType);
epicsShareExtern rset *pvar_rset_asynRSET;
epicsShareExtern int (*pvar_func_asynRecordSizeOffset)(dbRecordType *pdbRecordType);

static const char * const recordTypeNames[29] = {
    "aai",
    "aao",
    "ai",
    "ao",
    "aSub",
    "bi",
    "bo",
    "calc",
    "calcout",
    "compress",
    "dfanout",
    "event",
    "fanout",
    "longin",
    "longout",
    "mbbi",
    "mbbiDirect",
    "mbbo",
    "mbboDirect",
    "permissive",
    "sel",
    "seq",
    "state",
    "stringin",
    "stringout",
    "sub",
    "subArray",
    "waveform",
    "asyn"
};

static const recordTypeLocation rtl[29] = {
    {pvar_rset_aaiRSET, pvar_func_aaiRecordSizeOffset},
    {pvar_rset_aaoRSET, pvar_func_aaoRecordSizeOffset},
    {pvar_rset_aiRSET, pvar_func_aiRecordSizeOffset},
    {pvar_rset_aoRSET, pvar_func_aoRecordSizeOffset},
    {pvar_rset_aSubRSET, pvar_func_aSubRecordSizeOffset},
    {pvar_rset_biRSET, pvar_func_biRecordSizeOffset},
    {pvar_rset_boRSET, pvar_func_boRecordSizeOffset},
    {pvar_rset_calcRSET, pvar_func_calcRecordSizeOffset},
    {pvar_rset_calcoutRSET, pvar_func_calcoutRecordSizeOffset},
    {pvar_rset_compressRSET, pvar_func_compressRecordSizeOffset},
    {pvar_rset_dfanoutRSET, pvar_func_dfanoutRecordSizeOffset},
    {pvar_rset_eventRSET, pvar_func_eventRecordSizeOffset},
    {pvar_rset_fanoutRSET, pvar_func_fanoutRecordSizeOffset},
    {pvar_rset_longinRSET, pvar_func_longinRecordSizeOffset},
    {pvar_rset_longoutRSET, pvar_func_longoutRecordSizeOffset},
    {pvar_rset_mbbiRSET, pvar_func_mbbiRecordSizeOffset},
    {pvar_rset_mbbiDirectRSET, pvar_func_mbbiDirectRecordSizeOffset},
    {pvar_rset_mbboRSET, pvar_func_mbboRecordSizeOffset},
    {pvar_rset_mbboDirectRSET, pvar_func_mbboDirectRecordSizeOffset},
    {pvar_rset_permissiveRSET, pvar_func_permissiveRecordSizeOffset},
    {pvar_rset_selRSET, pvar_func_selRecordSizeOffset},
    {pvar_rset_seqRSET, pvar_func_seqRecordSizeOffset},
    {pvar_rset_stateRSET, pvar_func_stateRecordSizeOffset},
    {pvar_rset_stringinRSET, pvar_func_stringinRecordSizeOffset},
    {pvar_rset_stringoutRSET, pvar_func_stringoutRecordSizeOffset},
    {pvar_rset_subRSET, pvar_func_subRecordSizeOffset},
    {pvar_rset_subArrayRSET, pvar_func_subArrayRecordSizeOffset},
    {pvar_rset_waveformRSET, pvar_func_waveformRecordSizeOffset},
    {pvar_rset_asynRSET, pvar_func_asynRecordSizeOffset}
};

epicsShareExtern dset *pvar_dset_devAaiSoft;
epicsShareExtern dset *pvar_dset_devAaoSoft;
epicsShareExtern dset *pvar_dset_devAiSoft;
epicsShareExtern dset *pvar_dset_devAiSoftRaw;
epicsShareExtern dset *pvar_dset_devTimestampAI;
epicsShareExtern dset *pvar_dset_devAiGeneralTime;
epicsShareExtern dset *pvar_dset_asynAiInt32;
epicsShareExtern dset *pvar_dset_asynAiInt32Average;
epicsShareExtern dset *pvar_dset_asynAiFloat64;
epicsShareExtern dset *pvar_dset_asynAiFloat64Average;
epicsShareExtern dset *pvar_dset_devAoSoft;
epicsShareExtern dset *pvar_dset_devAoSoftRaw;
epicsShareExtern dset *pvar_dset_devAoSoftCallback;
epicsShareExtern dset *pvar_dset_asynAoInt32;
epicsShareExtern dset *pvar_dset_asynAoFloat64;
epicsShareExtern dset *pvar_dset_devBiSoft;
epicsShareExtern dset *pvar_dset_devBiSoftRaw;
epicsShareExtern dset *pvar_dset_asynBiInt32;
epicsShareExtern dset *pvar_dset_asynBiUInt32Digital;
epicsShareExtern dset *pvar_dset_devBoSoft;
epicsShareExtern dset *pvar_dset_devBoSoftRaw;
epicsShareExtern dset *pvar_dset_devBoSoftCallback;
epicsShareExtern dset *pvar_dset_devBoGeneralTime;
epicsShareExtern dset *pvar_dset_asynBoInt32;
epicsShareExtern dset *pvar_dset_asynBoUInt32Digital;
epicsShareExtern dset *pvar_dset_devCalcoutSoft;
epicsShareExtern dset *pvar_dset_devCalcoutSoftCallback;
epicsShareExtern dset *pvar_dset_devEventSoft;
epicsShareExtern dset *pvar_dset_devLiSoft;
epicsShareExtern dset *pvar_dset_devLiGeneralTime;
epicsShareExtern dset *pvar_dset_asynLiInt32;
epicsShareExtern dset *pvar_dset_asynLiUInt32Digital;
epicsShareExtern dset *pvar_dset_devLoSoft;
epicsShareExtern dset *pvar_dset_devLoSoftCallback;
epicsShareExtern dset *pvar_dset_asynLoInt32;
epicsShareExtern dset *pvar_dset_asynLoUInt32Digital;
epicsShareExtern dset *pvar_dset_devMbbiSoft;
epicsShareExtern dset *pvar_dset_devMbbiSoftRaw;
epicsShareExtern dset *pvar_dset_asynMbbiInt32;
epicsShareExtern dset *pvar_dset_asynMbbiUInt32Digital;
epicsShareExtern dset *pvar_dset_devMbbiDirectSoft;
epicsShareExtern dset *pvar_dset_devMbbiDirectSoftRaw;
epicsShareExtern dset *pvar_dset_asynMbbiDirectUInt32Digital;
epicsShareExtern dset *pvar_dset_devMbboSoft;
epicsShareExtern dset *pvar_dset_devMbboSoftRaw;
epicsShareExtern dset *pvar_dset_devMbboSoftCallback;
epicsShareExtern dset *pvar_dset_asynMbboInt32;
epicsShareExtern dset *pvar_dset_asynMbboUInt32Digital;
epicsShareExtern dset *pvar_dset_devMbboDirectSoft;
epicsShareExtern dset *pvar_dset_devMbboDirectSoftRaw;
epicsShareExtern dset *pvar_dset_devMbboDirectSoftCallback;
epicsShareExtern dset *pvar_dset_asynMbboDirectUInt32Digital;
epicsShareExtern dset *pvar_dset_devSiSoft;
epicsShareExtern dset *pvar_dset_devTimestampSI;
epicsShareExtern dset *pvar_dset_devSiGeneralTime;
epicsShareExtern dset *pvar_dset_asynSiOctetCmdResponse;
epicsShareExtern dset *pvar_dset_asynSiOctetWriteRead;
epicsShareExtern dset *pvar_dset_asynSiOctetRead;
epicsShareExtern dset *pvar_dset_devSoSoft;
epicsShareExtern dset *pvar_dset_devSoSoftCallback;
epicsShareExtern dset *pvar_dset_devSoStdio;
epicsShareExtern dset *pvar_dset_asynSoOctetWrite;
epicsShareExtern dset *pvar_dset_devSASoft;
epicsShareExtern dset *pvar_dset_devWfSoft;
epicsShareExtern dset *pvar_dset_asynWfOctetCmdResponse;
epicsShareExtern dset *pvar_dset_asynWfOctetWriteRead;
epicsShareExtern dset *pvar_dset_asynWfOctetRead;
epicsShareExtern dset *pvar_dset_asynWfOctetWrite;
epicsShareExtern dset *pvar_dset_asynInt8ArrayWfIn;
epicsShareExtern dset *pvar_dset_asynInt8ArrayWfOut;
epicsShareExtern dset *pvar_dset_asynInt16ArrayWfIn;
epicsShareExtern dset *pvar_dset_asynInt16ArrayWfOut;
epicsShareExtern dset *pvar_dset_asynInt32ArrayWfIn;
epicsShareExtern dset *pvar_dset_asynInt32ArrayWfOut;
epicsShareExtern dset *pvar_dset_asynInt32TimeSeries;
epicsShareExtern dset *pvar_dset_asynFloat32ArrayWfIn;
epicsShareExtern dset *pvar_dset_asynFloat32ArrayWfOut;
epicsShareExtern dset *pvar_dset_asynFloat64ArrayWfIn;
epicsShareExtern dset *pvar_dset_asynFloat64ArrayWfOut;
epicsShareExtern dset *pvar_dset_asynFloat64TimeSeries;
epicsShareExtern dset *pvar_dset_asynRecordDevice;

static const char * const deviceSupportNames[81] = {
    "devAaiSoft",
    "devAaoSoft",
    "devAiSoft",
    "devAiSoftRaw",
    "devTimestampAI",
    "devAiGeneralTime",
    "asynAiInt32",
    "asynAiInt32Average",
    "asynAiFloat64",
    "asynAiFloat64Average",
    "devAoSoft",
    "devAoSoftRaw",
    "devAoSoftCallback",
    "asynAoInt32",
    "asynAoFloat64",
    "devBiSoft",
    "devBiSoftRaw",
    "asynBiInt32",
    "asynBiUInt32Digital",
    "devBoSoft",
    "devBoSoftRaw",
    "devBoSoftCallback",
    "devBoGeneralTime",
    "asynBoInt32",
    "asynBoUInt32Digital",
    "devCalcoutSoft",
    "devCalcoutSoftCallback",
    "devEventSoft",
    "devLiSoft",
    "devLiGeneralTime",
    "asynLiInt32",
    "asynLiUInt32Digital",
    "devLoSoft",
    "devLoSoftCallback",
    "asynLoInt32",
    "asynLoUInt32Digital",
    "devMbbiSoft",
    "devMbbiSoftRaw",
    "asynMbbiInt32",
    "asynMbbiUInt32Digital",
    "devMbbiDirectSoft",
    "devMbbiDirectSoftRaw",
    "asynMbbiDirectUInt32Digital",
    "devMbboSoft",
    "devMbboSoftRaw",
    "devMbboSoftCallback",
    "asynMbboInt32",
    "asynMbboUInt32Digital",
    "devMbboDirectSoft",
    "devMbboDirectSoftRaw",
    "devMbboDirectSoftCallback",
    "asynMbboDirectUInt32Digital",
    "devSiSoft",
    "devTimestampSI",
    "devSiGeneralTime",
    "asynSiOctetCmdResponse",
    "asynSiOctetWriteRead",
    "asynSiOctetRead",
    "devSoSoft",
    "devSoSoftCallback",
    "devSoStdio",
    "asynSoOctetWrite",
    "devSASoft",
    "devWfSoft",
    "asynWfOctetCmdResponse",
    "asynWfOctetWriteRead",
    "asynWfOctetRead",
    "asynWfOctetWrite",
    "asynInt8ArrayWfIn",
    "asynInt8ArrayWfOut",
    "asynInt16ArrayWfIn",
    "asynInt16ArrayWfOut",
    "asynInt32ArrayWfIn",
    "asynInt32ArrayWfOut",
    "asynInt32TimeSeries",
    "asynFloat32ArrayWfIn",
    "asynFloat32ArrayWfOut",
    "asynFloat64ArrayWfIn",
    "asynFloat64ArrayWfOut",
    "asynFloat64TimeSeries",
    "asynRecordDevice"
};

static const dset * const devsl[81] = {
    pvar_dset_devAaiSoft,
    pvar_dset_devAaoSoft,
    pvar_dset_devAiSoft,
    pvar_dset_devAiSoftRaw,
    pvar_dset_devTimestampAI,
    pvar_dset_devAiGeneralTime,
    pvar_dset_asynAiInt32,
    pvar_dset_asynAiInt32Average,
    pvar_dset_asynAiFloat64,
    pvar_dset_asynAiFloat64Average,
    pvar_dset_devAoSoft,
    pvar_dset_devAoSoftRaw,
    pvar_dset_devAoSoftCallback,
    pvar_dset_asynAoInt32,
    pvar_dset_asynAoFloat64,
    pvar_dset_devBiSoft,
    pvar_dset_devBiSoftRaw,
    pvar_dset_asynBiInt32,
    pvar_dset_asynBiUInt32Digital,
    pvar_dset_devBoSoft,
    pvar_dset_devBoSoftRaw,
    pvar_dset_devBoSoftCallback,
    pvar_dset_devBoGeneralTime,
    pvar_dset_asynBoInt32,
    pvar_dset_asynBoUInt32Digital,
    pvar_dset_devCalcoutSoft,
    pvar_dset_devCalcoutSoftCallback,
    pvar_dset_devEventSoft,
    pvar_dset_devLiSoft,
    pvar_dset_devLiGeneralTime,
    pvar_dset_asynLiInt32,
    pvar_dset_asynLiUInt32Digital,
    pvar_dset_devLoSoft,
    pvar_dset_devLoSoftCallback,
    pvar_dset_asynLoInt32,
    pvar_dset_asynLoUInt32Digital,
    pvar_dset_devMbbiSoft,
    pvar_dset_devMbbiSoftRaw,
    pvar_dset_asynMbbiInt32,
    pvar_dset_asynMbbiUInt32Digital,
    pvar_dset_devMbbiDirectSoft,
    pvar_dset_devMbbiDirectSoftRaw,
    pvar_dset_asynMbbiDirectUInt32Digital,
    pvar_dset_devMbboSoft,
    pvar_dset_devMbboSoftRaw,
    pvar_dset_devMbboSoftCallback,
    pvar_dset_asynMbboInt32,
    pvar_dset_asynMbboUInt32Digital,
    pvar_dset_devMbboDirectSoft,
    pvar_dset_devMbboDirectSoftRaw,
    pvar_dset_devMbboDirectSoftCallback,
    pvar_dset_asynMbboDirectUInt32Digital,
    pvar_dset_devSiSoft,
    pvar_dset_devTimestampSI,
    pvar_dset_devSiGeneralTime,
    pvar_dset_asynSiOctetCmdResponse,
    pvar_dset_asynSiOctetWriteRead,
    pvar_dset_asynSiOctetRead,
    pvar_dset_devSoSoft,
    pvar_dset_devSoSoftCallback,
    pvar_dset_devSoStdio,
    pvar_dset_asynSoOctetWrite,
    pvar_dset_devSASoft,
    pvar_dset_devWfSoft,
    pvar_dset_asynWfOctetCmdResponse,
    pvar_dset_asynWfOctetWriteRead,
    pvar_dset_asynWfOctetRead,
    pvar_dset_asynWfOctetWrite,
    pvar_dset_asynInt8ArrayWfIn,
    pvar_dset_asynInt8ArrayWfOut,
    pvar_dset_asynInt16ArrayWfIn,
    pvar_dset_asynInt16ArrayWfOut,
    pvar_dset_asynInt32ArrayWfIn,
    pvar_dset_asynInt32ArrayWfOut,
    pvar_dset_asynInt32TimeSeries,
    pvar_dset_asynFloat32ArrayWfIn,
    pvar_dset_asynFloat32ArrayWfOut,
    pvar_dset_asynFloat64ArrayWfIn,
    pvar_dset_asynFloat64ArrayWfOut,
    pvar_dset_asynFloat64TimeSeries,
    pvar_dset_asynRecordDevice
};

epicsShareExtern drvet *pvar_drvet_drvAsyn;

static const char *driverSupportNames[1] = {
    "drvAsyn"
};

static struct drvet *drvsl[1] = {
    pvar_drvet_drvAsyn
};

epicsShareExtern void (*pvar_func_asSub)(void);
epicsShareExtern void (*pvar_func_asynRegister)(void);
epicsShareExtern void (*pvar_func_asynInterposeFlushRegister)(void);
epicsShareExtern void (*pvar_func_asynInterposeEosRegister)(void);
epicsShareExtern void (*pvar_func_ecAsynRegistrar)(void);

epicsShareExtern int *pvar_int_asCaDebug;
epicsShareExtern int *pvar_int_dbRecordsOnceOnly;
epicsShareExtern int *pvar_int_dbBptNotMonotonic;
epicsShareExtern int *pvar_int_dbTemplateMaxVars;
static struct iocshVarDef vardefs[] = {
	{"asCaDebug", iocshArgInt, (void * const)pvar_int_asCaDebug},
	{"dbRecordsOnceOnly", iocshArgInt, (void * const)pvar_int_dbRecordsOnceOnly},
	{"dbBptNotMonotonic", iocshArgInt, (void * const)pvar_int_dbBptNotMonotonic},
	{"dbTemplateMaxVars", iocshArgInt, (void * const)pvar_int_dbTemplateMaxVars},
	{NULL, iocshArgInt, NULL}
};

int scantest_registerRecordDeviceDriver(DBBASE *pbase)
{
    const char *bldTop = "/usr/local/epics/ethercat/iocs/scanTest";
    const char *envTop = getenv("TOP");

    if (envTop && strcmp(envTop, bldTop)) {
        printf("Warning: IOC is booting with TOP = \"%s\"\n"
               "          but was built with TOP = \"%s\"\n",
               envTop, bldTop);
    }

    if (!pbase) {
        printf("pdbbase is NULL; you must load a DBD file first.\n");
        return -1;
    }

    registerRecordTypes(pbase, 29, recordTypeNames, rtl);
    registerDevices(pbase, 81, deviceSupportNames, devsl);
    registerDrivers(pbase, 1, driverSupportNames, drvsl);
    (*pvar_func_asSub)();
    (*pvar_func_asynRegister)();
    (*pvar_func_asynInterposeFlushRegister)();
    (*pvar_func_asynInterposeEosRegister)();
    (*pvar_func_ecAsynRegistrar)();
    iocshRegisterVariable(vardefs);
    return 0;
}

/* registerRecordDeviceDriver */
static const iocshArg registerRecordDeviceDriverArg0 =
                                            {"pdbbase",iocshArgPdbbase};
static const iocshArg *registerRecordDeviceDriverArgs[1] =
                                            {&registerRecordDeviceDriverArg0};
static const iocshFuncDef registerRecordDeviceDriverFuncDef =
                {"scantest_registerRecordDeviceDriver",1,registerRecordDeviceDriverArgs};
static void registerRecordDeviceDriverCallFunc(const iocshArgBuf *)
{
    scantest_registerRecordDeviceDriver(*iocshPpdbbase);
}

} // extern "C"
/*
 * Register commands on application startup
 */
static int Registration() {
    iocshRegisterCommon();
    iocshRegister(&registerRecordDeviceDriverFuncDef,
        registerRecordDeviceDriverCallFunc);
    return 0;
}

static int done = Registration();
