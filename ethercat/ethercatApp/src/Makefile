TOP=../..

include $(TOP)/configure/CONFIG

# LIBRARY

USR_SYS_LIBS += xml2
LIBRARY_IOC += ecAsyn 

VERSION=1-5-2dls7
ETHERLAB=/usr/locale/epics/etherlabmaster-hg

ecAsyn_SRCS += ecAsyn.cpp gadc.cpp
ecAsyn_LIBS += asyn scannerlib rtutils 
ecAsyn_INCLUDES += -I$(ETHERLAB)/include
gadc_INCLUDES += -I$(ETHERLAB)/include

INC += gadc.h

DBD += ecAsyn.dbd

# IOC

USR_INCLUDES += -I/usr/include/libxml2

# These two lines are needed for non-vxWorks builds, such as Linux
ethercat_SRCS_DEFAULT += ethercatMain.cpp
ethercat_SRCS_vxWorks += -nil-

# The following adds object code from base/src/vxWorks
ethercat_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

ethercat_LIBS += ecAsyn asyn
ethercat_LIBS += $(EPICS_BASE_IOC_LIBS)

include $(TOP)/configure/RULES
