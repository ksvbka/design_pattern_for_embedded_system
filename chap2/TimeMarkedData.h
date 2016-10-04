#ifndef __TIME_MAKED_DATA_H__
#define __TIME_MAKED_DATA_H__

#include "ECGPkg.h"

typedef struct TimeMarkedData TimeMarkedData;

struct TimeMarkedData {
    long timeInterval;
    int dataValue;
};

void TimeMarkedData_Init (TimeMarkedData* const me);
void TimeMarkedData_Cleanup (TimeMarkedData* const me);
void TimeMarkedData__setItsTMDQueue (const TimeMarkedData* const me, struct TMDQueue* p_TMDQueue);

#endif
