#include "ECG_Module.h"
#include "TMDQueue.h"
#include <stdlib.h>

static void cleanUpRelations(ECG_Module* const me);

void ECG_Module_Init(ECG_Module* const me) {
    me->dataNum = 0;
    me->itsTMDQueue = NULL;
}
void ECG_Module_Cleanup(ECG_Module* const me) {
    cleanUpRelations(me);
}
/* operation acquireValue() */
void ECG_Module_acquireValue(ECG_Module* const me) {
// in actual implementation, this would return the
// measured voltage across the lead pair
    TimeMarkedData tmd;
    tmd.dataValue = rand();
    tmd.timeInterval = ++me->dataNum;
    TMDQueue_insert(me->itsTMDQueue, tmd);
}

/* operation setLeadPair(int,int) */
void ECG_Module_setLeadPair(ECG_Module* const me, int l1, int l2) {
    me->lead1 = l1;
    me->lead2 = l2;
}

struct TMDQueue* ECG_Module_getItsTMDQueue(const ECG_Module* const me) {
    return (struct TMDQueue*)me->itsTMDQueue;
}

void ECG_Module_setItsTMDQueue(ECG_Module* const me, struct TMDQueue* p_TMDQueue) {
    me->itsTMDQueue = p_TMDQueue;
}

ECG_Module * ECG_Module_Create(void) {
    ECG_Module* me = (ECG_Module *) malloc(sizeof(ECG_Module));
    if (me != NULL) {
        ECG_Module_Init(me);
    }
    return me;
}

void ECG_Module_Destroy(ECG_Module* const me) {
    if (me != NULL) {
        ECG_Module_Cleanup(me);
    }
    free(me);
}

static void cleanUpRelations(ECG_Module* const me) {
    if (me->itsTMDQueue != NULL){
        me->itsTMDQueue = NULL;
    }

}
