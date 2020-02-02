
#ifndef INCepidFeedbackStateH
#define INCepidFeedbackStateH
typedef enum {
	epidFeedbackState_Off,
	epidFeedbackState_On
}epidFeedbackState;
#endif /*INCepidFeedbackStateH*/

#ifndef INCepidFeedbackModeH
#define INCepidFeedbackModeH
typedef enum {
	epidFeedbackMode_PID,
	epidFeedbackMode_MaxMin
}epidFeedbackMode;
#endif /*INCepidFeedbackModeH*/
#ifndef INCepidH
#define INCepidH
#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "epicsTime.h"
typedef struct epidRecord {
	char		name[61];	/* Record Name */
	char		desc[41];	/* Descriptor */
	char		asg[29];	/* Access Security Group */
	epicsEnum16	scan;	/* Scan Mechanism */
	epicsEnum16	pini;	/* Process at iocInit */
	epicsInt16	phas;	/* Scan Phase */
	epicsInt16	evnt;	/* Event Number */
	epicsInt16	tse;	/* Time Stamp Event */
	DBLINK		tsel;	/* Time Stamp Link */
	epicsEnum16	dtyp;	/* Device Type */
	epicsInt16	disv;	/* Disable Value */
	epicsInt16	disa;	/* Disable */
	DBLINK		sdis;	/* Scanning Disable */
	epicsMutexId	mlok;	/* Monitor lock */
	ELLLIST		mlis;	/* Monitor List */
	epicsUInt8	disp;	/* Disable putField */
	epicsUInt8	proc;	/* Force Processing */
	epicsEnum16	stat;	/* Alarm Status */
	epicsEnum16	sevr;	/* Alarm Severity */
	epicsEnum16	nsta;	/* New Alarm Status */
	epicsEnum16	nsev;	/* New Alarm Severity */
	epicsEnum16	acks;	/* Alarm Ack Severity */
	epicsEnum16	ackt;	/* Alarm Ack Transient */
	epicsEnum16	diss;	/* Disable Alarm Sevrty */
	epicsUInt8	lcnt;	/* Lock Count */
	epicsUInt8	pact;	/* Record active */
	epicsUInt8	putf;	/* dbPutField process */
	epicsUInt8	rpro;	/* Reprocess  */
	struct asgMember *asp;	/* Access Security Pvt */
	struct putNotify *ppn;	/* addr of PUTNOTIFY */
	struct putNotifyRecord *ppnr;	/* pputNotifyRecord */
	struct scan_element *spvt;	/* Scan Private */
	struct rset	*rset;	/* Address of RSET */
	struct dset	*dset;	/* DSET address */
	void		*dpvt;	/* Device Private */
	struct dbRecordType *rdes;	/* Address of dbRecordType */
	struct lockRecord *lset;	/* Lock Set */
	epicsEnum16	prio;	/* Scheduling Priority */
	epicsUInt8	tpro;	/* Trace Processing */
	char bkpt;	/* Break Point */
	epicsUInt8	udf;	/* Undefined */
	epicsTimeStamp	time;	/* Time */
	DBLINK		flnk;	/* Forward Process Link */
	epicsFloat64	val;	/* Setpoint */
	epicsEnum16	smsl;	/* Setpoint Mode Select */
	DBLINK		stpl;	/* Setpoint Location */
	DBLINK		inp;	/* Controlled Value Loc */
	DBLINK		outl;	/* Output Location */
	DBLINK		trig;	/* Readback Trigger */
	epicsFloat64	tval;	/* Trigger Value */
	epicsFloat64	cval;	/* Controlled Value */
	epicsFloat64	cvlp;	/* Prev. Controlled Value */
	epicsFloat64	oval;	/* Output value */
	epicsFloat64	ovlp;	/* Prev output */
	epicsInt16	prec;	/* Display Precision */
	epicsFloat64	mdt;	/* Min Delta T */
	epicsEnum16	fmod;	/* Feedback Mode */
	epicsEnum16	fbon;	/* Feedback On/Off */
	epicsEnum16	fbop;	/* Prev. feedback On/Off */
	epicsFloat64	kp;	/* Proportional Gain */
	epicsFloat64	ki;	/* Intergral Gain */
	epicsFloat64	kd;	/* Derivative Gain */
	char		egu[16];	/* Engineering Units */
	epicsFloat64	hopr;	/* High Operating Range */
	epicsFloat64	lopr;	/* Low Operating Range */
	epicsFloat64	drvh;	/* High Drive Limit */
	epicsFloat64	drvl;	/* Low Drive Limit */
	epicsFloat64	hihi;	/* Hihi Deviation Limit */
	epicsFloat64	lolo;	/* Lolo Deviation Limit */
	epicsFloat64	high;	/* High Deviation Limit */
	epicsFloat64	low;	/* Low Deviation Limit */
	epicsEnum16	hhsv;	/* Hihi Severity */
	epicsEnum16	llsv;	/* Lolo Severity */
	epicsEnum16	hsv;	/* High Severity */
	epicsEnum16	lsv;	/* Low Severity */
	epicsFloat64	hyst;	/* Alarm Deadband */
	epicsFloat64	adel;	/* Archive Deadband */
	epicsFloat64	mdel;	/* Monitor Deadband */
	epicsFloat64	odel;	/* Output Deadband */
	epicsFloat64	p;	/* P component */
	epicsFloat64	pp;	/* Prev. P component */
	epicsFloat64	i;	/* I component */
	epicsFloat64	ip;	/* Prev. I component */
	epicsFloat64	d;	/* D component */
	epicsFloat64	dp;	/* Prev. D component */
	epicsTimeStamp  ct;	/* Time */
	epicsTimeStamp   ctp;	/* Previous time */
	epicsFloat64	dt;	/* Delta T */
	epicsFloat64	dtp;	/* Prev. Delta T */
	epicsFloat64	err;	/* Error */
	epicsFloat64	errp;	/* Prev. Error */
	epicsFloat64	lalm;	/* Last Value Alarmed */
	epicsFloat64	alst;	/* Last Value Archived */
	epicsFloat64	mlst;	/* Last Value Monitored */
} epidRecord;
#define epidRecordNAME	0
#define epidRecordDESC	1
#define epidRecordASG	2
#define epidRecordSCAN	3
#define epidRecordPINI	4
#define epidRecordPHAS	5
#define epidRecordEVNT	6
#define epidRecordTSE	7
#define epidRecordTSEL	8
#define epidRecordDTYP	9
#define epidRecordDISV	10
#define epidRecordDISA	11
#define epidRecordSDIS	12
#define epidRecordMLOK	13
#define epidRecordMLIS	14
#define epidRecordDISP	15
#define epidRecordPROC	16
#define epidRecordSTAT	17
#define epidRecordSEVR	18
#define epidRecordNSTA	19
#define epidRecordNSEV	20
#define epidRecordACKS	21
#define epidRecordACKT	22
#define epidRecordDISS	23
#define epidRecordLCNT	24
#define epidRecordPACT	25
#define epidRecordPUTF	26
#define epidRecordRPRO	27
#define epidRecordASP	28
#define epidRecordPPN	29
#define epidRecordPPNR	30
#define epidRecordSPVT	31
#define epidRecordRSET	32
#define epidRecordDSET	33
#define epidRecordDPVT	34
#define epidRecordRDES	35
#define epidRecordLSET	36
#define epidRecordPRIO	37
#define epidRecordTPRO	38
#define epidRecordBKPT	39
#define epidRecordUDF	40
#define epidRecordTIME	41
#define epidRecordFLNK	42
#define epidRecordVAL	43
#define epidRecordSMSL	44
#define epidRecordSTPL	45
#define epidRecordINP	46
#define epidRecordOUTL	47
#define epidRecordTRIG	48
#define epidRecordTVAL	49
#define epidRecordCVAL	50
#define epidRecordCVLP	51
#define epidRecordOVAL	52
#define epidRecordOVLP	53
#define epidRecordPREC	54
#define epidRecordMDT	55
#define epidRecordFMOD	56
#define epidRecordFBON	57
#define epidRecordFBOP	58
#define epidRecordKP	59
#define epidRecordKI	60
#define epidRecordKD	61
#define epidRecordEGU	62
#define epidRecordHOPR	63
#define epidRecordLOPR	64
#define epidRecordDRVH	65
#define epidRecordDRVL	66
#define epidRecordHIHI	67
#define epidRecordLOLO	68
#define epidRecordHIGH	69
#define epidRecordLOW	70
#define epidRecordHHSV	71
#define epidRecordLLSV	72
#define epidRecordHSV	73
#define epidRecordLSV	74
#define epidRecordHYST	75
#define epidRecordADEL	76
#define epidRecordMDEL	77
#define epidRecordODEL	78
#define epidRecordP	79
#define epidRecordPP	80
#define epidRecordI	81
#define epidRecordIP	82
#define epidRecordD	83
#define epidRecordDP	84
#define epidRecordCT	85
#define epidRecordCTP	86
#define epidRecordDT	87
#define epidRecordDTP	88
#define epidRecordERR	89
#define epidRecordERRP	90
#define epidRecordLALM	91
#define epidRecordALST	92
#define epidRecordMLST	93
#endif /*INCepidH*/
#ifdef GEN_SIZE_OFFSET
#ifdef __cplusplus
extern "C" {
#endif
#include <epicsAssert.h>
#include <epicsExport.h>
static int epidRecordSizeOffset(dbRecordType *pdbRecordType)
{
    epidRecord *prec = 0;
  assert(pdbRecordType->no_fields==94);
  pdbRecordType->papFldDes[0]->size=sizeof(prec->name);
  pdbRecordType->papFldDes[0]->offset=(short)((char *)&prec->name - (char *)prec);
  pdbRecordType->papFldDes[1]->size=sizeof(prec->desc);
  pdbRecordType->papFldDes[1]->offset=(short)((char *)&prec->desc - (char *)prec);
  pdbRecordType->papFldDes[2]->size=sizeof(prec->asg);
  pdbRecordType->papFldDes[2]->offset=(short)((char *)&prec->asg - (char *)prec);
  pdbRecordType->papFldDes[3]->size=sizeof(prec->scan);
  pdbRecordType->papFldDes[3]->offset=(short)((char *)&prec->scan - (char *)prec);
  pdbRecordType->papFldDes[4]->size=sizeof(prec->pini);
  pdbRecordType->papFldDes[4]->offset=(short)((char *)&prec->pini - (char *)prec);
  pdbRecordType->papFldDes[5]->size=sizeof(prec->phas);
  pdbRecordType->papFldDes[5]->offset=(short)((char *)&prec->phas - (char *)prec);
  pdbRecordType->papFldDes[6]->size=sizeof(prec->evnt);
  pdbRecordType->papFldDes[6]->offset=(short)((char *)&prec->evnt - (char *)prec);
  pdbRecordType->papFldDes[7]->size=sizeof(prec->tse);
  pdbRecordType->papFldDes[7]->offset=(short)((char *)&prec->tse - (char *)prec);
  pdbRecordType->papFldDes[8]->size=sizeof(prec->tsel);
  pdbRecordType->papFldDes[8]->offset=(short)((char *)&prec->tsel - (char *)prec);
  pdbRecordType->papFldDes[9]->size=sizeof(prec->dtyp);
  pdbRecordType->papFldDes[9]->offset=(short)((char *)&prec->dtyp - (char *)prec);
  pdbRecordType->papFldDes[10]->size=sizeof(prec->disv);
  pdbRecordType->papFldDes[10]->offset=(short)((char *)&prec->disv - (char *)prec);
  pdbRecordType->papFldDes[11]->size=sizeof(prec->disa);
  pdbRecordType->papFldDes[11]->offset=(short)((char *)&prec->disa - (char *)prec);
  pdbRecordType->papFldDes[12]->size=sizeof(prec->sdis);
  pdbRecordType->papFldDes[12]->offset=(short)((char *)&prec->sdis - (char *)prec);
  pdbRecordType->papFldDes[13]->size=sizeof(prec->mlok);
  pdbRecordType->papFldDes[13]->offset=(short)((char *)&prec->mlok - (char *)prec);
  pdbRecordType->papFldDes[14]->size=sizeof(prec->mlis);
  pdbRecordType->papFldDes[14]->offset=(short)((char *)&prec->mlis - (char *)prec);
  pdbRecordType->papFldDes[15]->size=sizeof(prec->disp);
  pdbRecordType->papFldDes[15]->offset=(short)((char *)&prec->disp - (char *)prec);
  pdbRecordType->papFldDes[16]->size=sizeof(prec->proc);
  pdbRecordType->papFldDes[16]->offset=(short)((char *)&prec->proc - (char *)prec);
  pdbRecordType->papFldDes[17]->size=sizeof(prec->stat);
  pdbRecordType->papFldDes[17]->offset=(short)((char *)&prec->stat - (char *)prec);
  pdbRecordType->papFldDes[18]->size=sizeof(prec->sevr);
  pdbRecordType->papFldDes[18]->offset=(short)((char *)&prec->sevr - (char *)prec);
  pdbRecordType->papFldDes[19]->size=sizeof(prec->nsta);
  pdbRecordType->papFldDes[19]->offset=(short)((char *)&prec->nsta - (char *)prec);
  pdbRecordType->papFldDes[20]->size=sizeof(prec->nsev);
  pdbRecordType->papFldDes[20]->offset=(short)((char *)&prec->nsev - (char *)prec);
  pdbRecordType->papFldDes[21]->size=sizeof(prec->acks);
  pdbRecordType->papFldDes[21]->offset=(short)((char *)&prec->acks - (char *)prec);
  pdbRecordType->papFldDes[22]->size=sizeof(prec->ackt);
  pdbRecordType->papFldDes[22]->offset=(short)((char *)&prec->ackt - (char *)prec);
  pdbRecordType->papFldDes[23]->size=sizeof(prec->diss);
  pdbRecordType->papFldDes[23]->offset=(short)((char *)&prec->diss - (char *)prec);
  pdbRecordType->papFldDes[24]->size=sizeof(prec->lcnt);
  pdbRecordType->papFldDes[24]->offset=(short)((char *)&prec->lcnt - (char *)prec);
  pdbRecordType->papFldDes[25]->size=sizeof(prec->pact);
  pdbRecordType->papFldDes[25]->offset=(short)((char *)&prec->pact - (char *)prec);
  pdbRecordType->papFldDes[26]->size=sizeof(prec->putf);
  pdbRecordType->papFldDes[26]->offset=(short)((char *)&prec->putf - (char *)prec);
  pdbRecordType->papFldDes[27]->size=sizeof(prec->rpro);
  pdbRecordType->papFldDes[27]->offset=(short)((char *)&prec->rpro - (char *)prec);
  pdbRecordType->papFldDes[28]->size=sizeof(prec->asp);
  pdbRecordType->papFldDes[28]->offset=(short)((char *)&prec->asp - (char *)prec);
  pdbRecordType->papFldDes[29]->size=sizeof(prec->ppn);
  pdbRecordType->papFldDes[29]->offset=(short)((char *)&prec->ppn - (char *)prec);
  pdbRecordType->papFldDes[30]->size=sizeof(prec->ppnr);
  pdbRecordType->papFldDes[30]->offset=(short)((char *)&prec->ppnr - (char *)prec);
  pdbRecordType->papFldDes[31]->size=sizeof(prec->spvt);
  pdbRecordType->papFldDes[31]->offset=(short)((char *)&prec->spvt - (char *)prec);
  pdbRecordType->papFldDes[32]->size=sizeof(prec->rset);
  pdbRecordType->papFldDes[32]->offset=(short)((char *)&prec->rset - (char *)prec);
  pdbRecordType->papFldDes[33]->size=sizeof(prec->dset);
  pdbRecordType->papFldDes[33]->offset=(short)((char *)&prec->dset - (char *)prec);
  pdbRecordType->papFldDes[34]->size=sizeof(prec->dpvt);
  pdbRecordType->papFldDes[34]->offset=(short)((char *)&prec->dpvt - (char *)prec);
  pdbRecordType->papFldDes[35]->size=sizeof(prec->rdes);
  pdbRecordType->papFldDes[35]->offset=(short)((char *)&prec->rdes - (char *)prec);
  pdbRecordType->papFldDes[36]->size=sizeof(prec->lset);
  pdbRecordType->papFldDes[36]->offset=(short)((char *)&prec->lset - (char *)prec);
  pdbRecordType->papFldDes[37]->size=sizeof(prec->prio);
  pdbRecordType->papFldDes[37]->offset=(short)((char *)&prec->prio - (char *)prec);
  pdbRecordType->papFldDes[38]->size=sizeof(prec->tpro);
  pdbRecordType->papFldDes[38]->offset=(short)((char *)&prec->tpro - (char *)prec);
  pdbRecordType->papFldDes[39]->size=sizeof(prec->bkpt);
  pdbRecordType->papFldDes[39]->offset=(short)((char *)&prec->bkpt - (char *)prec);
  pdbRecordType->papFldDes[40]->size=sizeof(prec->udf);
  pdbRecordType->papFldDes[40]->offset=(short)((char *)&prec->udf - (char *)prec);
  pdbRecordType->papFldDes[41]->size=sizeof(prec->time);
  pdbRecordType->papFldDes[41]->offset=(short)((char *)&prec->time - (char *)prec);
  pdbRecordType->papFldDes[42]->size=sizeof(prec->flnk);
  pdbRecordType->papFldDes[42]->offset=(short)((char *)&prec->flnk - (char *)prec);
  pdbRecordType->papFldDes[43]->size=sizeof(prec->val);
  pdbRecordType->papFldDes[43]->offset=(short)((char *)&prec->val - (char *)prec);
  pdbRecordType->papFldDes[44]->size=sizeof(prec->smsl);
  pdbRecordType->papFldDes[44]->offset=(short)((char *)&prec->smsl - (char *)prec);
  pdbRecordType->papFldDes[45]->size=sizeof(prec->stpl);
  pdbRecordType->papFldDes[45]->offset=(short)((char *)&prec->stpl - (char *)prec);
  pdbRecordType->papFldDes[46]->size=sizeof(prec->inp);
  pdbRecordType->papFldDes[46]->offset=(short)((char *)&prec->inp - (char *)prec);
  pdbRecordType->papFldDes[47]->size=sizeof(prec->outl);
  pdbRecordType->papFldDes[47]->offset=(short)((char *)&prec->outl - (char *)prec);
  pdbRecordType->papFldDes[48]->size=sizeof(prec->trig);
  pdbRecordType->papFldDes[48]->offset=(short)((char *)&prec->trig - (char *)prec);
  pdbRecordType->papFldDes[49]->size=sizeof(prec->tval);
  pdbRecordType->papFldDes[49]->offset=(short)((char *)&prec->tval - (char *)prec);
  pdbRecordType->papFldDes[50]->size=sizeof(prec->cval);
  pdbRecordType->papFldDes[50]->offset=(short)((char *)&prec->cval - (char *)prec);
  pdbRecordType->papFldDes[51]->size=sizeof(prec->cvlp);
  pdbRecordType->papFldDes[51]->offset=(short)((char *)&prec->cvlp - (char *)prec);
  pdbRecordType->papFldDes[52]->size=sizeof(prec->oval);
  pdbRecordType->papFldDes[52]->offset=(short)((char *)&prec->oval - (char *)prec);
  pdbRecordType->papFldDes[53]->size=sizeof(prec->ovlp);
  pdbRecordType->papFldDes[53]->offset=(short)((char *)&prec->ovlp - (char *)prec);
  pdbRecordType->papFldDes[54]->size=sizeof(prec->prec);
  pdbRecordType->papFldDes[54]->offset=(short)((char *)&prec->prec - (char *)prec);
  pdbRecordType->papFldDes[55]->size=sizeof(prec->mdt);
  pdbRecordType->papFldDes[55]->offset=(short)((char *)&prec->mdt - (char *)prec);
  pdbRecordType->papFldDes[56]->size=sizeof(prec->fmod);
  pdbRecordType->papFldDes[56]->offset=(short)((char *)&prec->fmod - (char *)prec);
  pdbRecordType->papFldDes[57]->size=sizeof(prec->fbon);
  pdbRecordType->papFldDes[57]->offset=(short)((char *)&prec->fbon - (char *)prec);
  pdbRecordType->papFldDes[58]->size=sizeof(prec->fbop);
  pdbRecordType->papFldDes[58]->offset=(short)((char *)&prec->fbop - (char *)prec);
  pdbRecordType->papFldDes[59]->size=sizeof(prec->kp);
  pdbRecordType->papFldDes[59]->offset=(short)((char *)&prec->kp - (char *)prec);
  pdbRecordType->papFldDes[60]->size=sizeof(prec->ki);
  pdbRecordType->papFldDes[60]->offset=(short)((char *)&prec->ki - (char *)prec);
  pdbRecordType->papFldDes[61]->size=sizeof(prec->kd);
  pdbRecordType->papFldDes[61]->offset=(short)((char *)&prec->kd - (char *)prec);
  pdbRecordType->papFldDes[62]->size=sizeof(prec->egu);
  pdbRecordType->papFldDes[62]->offset=(short)((char *)&prec->egu - (char *)prec);
  pdbRecordType->papFldDes[63]->size=sizeof(prec->hopr);
  pdbRecordType->papFldDes[63]->offset=(short)((char *)&prec->hopr - (char *)prec);
  pdbRecordType->papFldDes[64]->size=sizeof(prec->lopr);
  pdbRecordType->papFldDes[64]->offset=(short)((char *)&prec->lopr - (char *)prec);
  pdbRecordType->papFldDes[65]->size=sizeof(prec->drvh);
  pdbRecordType->papFldDes[65]->offset=(short)((char *)&prec->drvh - (char *)prec);
  pdbRecordType->papFldDes[66]->size=sizeof(prec->drvl);
  pdbRecordType->papFldDes[66]->offset=(short)((char *)&prec->drvl - (char *)prec);
  pdbRecordType->papFldDes[67]->size=sizeof(prec->hihi);
  pdbRecordType->papFldDes[67]->offset=(short)((char *)&prec->hihi - (char *)prec);
  pdbRecordType->papFldDes[68]->size=sizeof(prec->lolo);
  pdbRecordType->papFldDes[68]->offset=(short)((char *)&prec->lolo - (char *)prec);
  pdbRecordType->papFldDes[69]->size=sizeof(prec->high);
  pdbRecordType->papFldDes[69]->offset=(short)((char *)&prec->high - (char *)prec);
  pdbRecordType->papFldDes[70]->size=sizeof(prec->low);
  pdbRecordType->papFldDes[70]->offset=(short)((char *)&prec->low - (char *)prec);
  pdbRecordType->papFldDes[71]->size=sizeof(prec->hhsv);
  pdbRecordType->papFldDes[71]->offset=(short)((char *)&prec->hhsv - (char *)prec);
  pdbRecordType->papFldDes[72]->size=sizeof(prec->llsv);
  pdbRecordType->papFldDes[72]->offset=(short)((char *)&prec->llsv - (char *)prec);
  pdbRecordType->papFldDes[73]->size=sizeof(prec->hsv);
  pdbRecordType->papFldDes[73]->offset=(short)((char *)&prec->hsv - (char *)prec);
  pdbRecordType->papFldDes[74]->size=sizeof(prec->lsv);
  pdbRecordType->papFldDes[74]->offset=(short)((char *)&prec->lsv - (char *)prec);
  pdbRecordType->papFldDes[75]->size=sizeof(prec->hyst);
  pdbRecordType->papFldDes[75]->offset=(short)((char *)&prec->hyst - (char *)prec);
  pdbRecordType->papFldDes[76]->size=sizeof(prec->adel);
  pdbRecordType->papFldDes[76]->offset=(short)((char *)&prec->adel - (char *)prec);
  pdbRecordType->papFldDes[77]->size=sizeof(prec->mdel);
  pdbRecordType->papFldDes[77]->offset=(short)((char *)&prec->mdel - (char *)prec);
  pdbRecordType->papFldDes[78]->size=sizeof(prec->odel);
  pdbRecordType->papFldDes[78]->offset=(short)((char *)&prec->odel - (char *)prec);
  pdbRecordType->papFldDes[79]->size=sizeof(prec->p);
  pdbRecordType->papFldDes[79]->offset=(short)((char *)&prec->p - (char *)prec);
  pdbRecordType->papFldDes[80]->size=sizeof(prec->pp);
  pdbRecordType->papFldDes[80]->offset=(short)((char *)&prec->pp - (char *)prec);
  pdbRecordType->papFldDes[81]->size=sizeof(prec->i);
  pdbRecordType->papFldDes[81]->offset=(short)((char *)&prec->i - (char *)prec);
  pdbRecordType->papFldDes[82]->size=sizeof(prec->ip);
  pdbRecordType->papFldDes[82]->offset=(short)((char *)&prec->ip - (char *)prec);
  pdbRecordType->papFldDes[83]->size=sizeof(prec->d);
  pdbRecordType->papFldDes[83]->offset=(short)((char *)&prec->d - (char *)prec);
  pdbRecordType->papFldDes[84]->size=sizeof(prec->dp);
  pdbRecordType->papFldDes[84]->offset=(short)((char *)&prec->dp - (char *)prec);
  pdbRecordType->papFldDes[85]->size=sizeof(prec->ct);
  pdbRecordType->papFldDes[85]->offset=(short)((char *)&prec->ct - (char *)prec);
  pdbRecordType->papFldDes[86]->size=sizeof(prec->ctp);
  pdbRecordType->papFldDes[86]->offset=(short)((char *)&prec->ctp - (char *)prec);
  pdbRecordType->papFldDes[87]->size=sizeof(prec->dt);
  pdbRecordType->papFldDes[87]->offset=(short)((char *)&prec->dt - (char *)prec);
  pdbRecordType->papFldDes[88]->size=sizeof(prec->dtp);
  pdbRecordType->papFldDes[88]->offset=(short)((char *)&prec->dtp - (char *)prec);
  pdbRecordType->papFldDes[89]->size=sizeof(prec->err);
  pdbRecordType->papFldDes[89]->offset=(short)((char *)&prec->err - (char *)prec);
  pdbRecordType->papFldDes[90]->size=sizeof(prec->errp);
  pdbRecordType->papFldDes[90]->offset=(short)((char *)&prec->errp - (char *)prec);
  pdbRecordType->papFldDes[91]->size=sizeof(prec->lalm);
  pdbRecordType->papFldDes[91]->offset=(short)((char *)&prec->lalm - (char *)prec);
  pdbRecordType->papFldDes[92]->size=sizeof(prec->alst);
  pdbRecordType->papFldDes[92]->offset=(short)((char *)&prec->alst - (char *)prec);
  pdbRecordType->papFldDes[93]->size=sizeof(prec->mlst);
  pdbRecordType->papFldDes[93]->offset=(short)((char *)&prec->mlst - (char *)prec);
    pdbRecordType->rec_size = sizeof(*prec);
    return(0);
}
epicsExportRegistrar(epidRecordSizeOffset);
#ifdef __cplusplus
}
#endif
#endif /*GEN_SIZE_OFFSET*/
