#include "TMDQueue.h"
static void initRelations(TMDQueue* const me);
static void cleanUpRelations(TMDQueue* const me);
void TMDQueue_Init(TMDQueue* const me) {
    me->head = 0;
    me->size = 0;
    initRelations(me);
}
void TMDQueue_Cleanup(TMDQueue* const me) {
    cleanUpRelations(me);
}
/* operation getNextIndex(int) */
int TMDQueue_getNextIndex(TMDQueue* const me, int index) {
    /* this operation computes the next index from the first using modulo arithmetic
    */
    return (index + 1) % QUEUE_SIZE;
}
/* operation insert(TimeMarkedData) */
void TMDQueue_insert(TMDQueue* const me, const struct TimeMarkedData tmd) {
    /* note that because we never ’remove’ data from this leaky queue, size only increases to
    the queue size and then stops increasing. Insertion always takes place at the head.
    */
    printf("Inserting at: %d Data #: %d", me->head, tmd.timeInterval);
    me->buffer[me->head] = tmd;
    me->head = TMDQueue_getNextIndex(me, me->head);
    if (me->size < QUEUE_SIZE) ++me->size;
    printf(" Storing data value: %d\n", tmd.dataValue);
}
/* operation isEmpty() */
int TMDQueue_isEmpty(TMDQueue* const me) {
    return (int)(me->size == 0);
}
/* operation remove(int) */
struct TimeMarkedData TMDQueue_remove(TMDQueue* const me, int index) {
    TimeMarkedData tmd;
    tmd.timeInterval = -1; /* sentinel values */
    tmd.dataValue = -9999;
    if (!TMDQueue_isEmpty(me) &&
            (index >= 0) && (index < QUEUE_SIZE)
            && (index < me->size)) {
        tmd = me->buffer[index];
    }
    return tmd;
}

int TMDQueue_getBuffer(const TMDQueue* const me) {
    int iter = 0;
    return iter;
}
TMDQueue * TMDQueue_Create(void) {
    TMDQueue* me = (TMDQueue *) malloc(sizeof(TMDQueue));
    if (me != NULL){
        TMDQueue_Init(me);
    }
    return me;
}

void TMDQueue_Destroy(TMDQueue* const me) {
    if (me != NULL){
        TMDQueue_Cleanup(me);
    }
    free(me);
}

static void initRelations(TMDQueue* const me) {
        int iter = 0;
        while (iter < QUEUE_SIZE) {
            TimeMarkedData_Init(&((me->buffer)[iter]));
            TimeMarkedData__setItsTMDQueue(&((me->buffer)[iter]), me);
            iter++;
        }
}


static void cleanUpRelations(TMDQueue* const me) {
    {
        int iter = 0;
        while (iter < QUEUE_SIZE) {
            TimeMarkedData_Cleanup(&((me->buffer)[iter]));
            iter++;
        }
    }
}
