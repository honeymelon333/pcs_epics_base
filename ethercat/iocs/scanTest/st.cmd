#!bin/linux-x86_64/scantest
dbLoadDatabase("dbd/scantest.dbd")
scantest_registerRecordDeviceDriver(pdbbase)

ADC_Ethercat_Sampler("RF0", 1, "Ch1Sample.Ch1Value", "Ch1CycleCount.Ch1CycleCount")

ecAsynInit("/tmp/0", 1000000)

dbLoadRecords("../../db/MASTER.template", "DEVICE=JRECTEST:0,PORT=MASTER0,SCAN=I/O Intr")
dbLoadRecords("../../db/EL3054.template", "DEVICE=AI1,PORT=AI1,SCAN=1 second")
#dbLoadRecords("../../db/EL1004.template", "DEVICE=JRECTEST:2,PORT=AO,SCAN=I/O Intr")
#dbLoadRecords("../../db/EL3702.template", "DEVICE=JRECTEST:3,PORT=RF0,SCAN=I/O Intr")
#dbLoadRecords("../../db/EL2004.template", "DEVICE=JRECTEST:4,PORT=OUT0,SCAN=I/O Intr")
#dbLoadRecords("../../db/gadc.template", "DEVICE=JRECTEST:3,PORT=RF0,SCAN=.1 second,CHANNEL=1,SAMPLES=100840,INTSCAN=.1 second")
#dbLoadRecords("../../db/xfc.template", "DEVICE=JRECTEST:3,PORT=RF0,SCAN=.1 second,CHANNEL=1")

iocInit()
