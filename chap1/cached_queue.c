#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cached_queue.h"

void CachedQueue_Init(CachedQueue* const me, char* fName,
                      int (*is_fullfunction)(CachedQueue* const me),
                      int (*is_emptyfunction)(CachedQueue* const me),
                      int (*get_sizefunction)(CachedQueue* const me),
                      void (*insertfunction)(CachedQueue* const me, int k),
                      int (*removefunction)(CachedQueue* const me),
                      void (*flushfunction)(CachedQueue* const me),
                      void (*loadfunction)(CachedQueue* const me)) {
    /* initialize base class */
    me->queue = Queue_create(); /* queue member must use its original functions */
    /* initialize subclass attributes */
    me->numberElementsOnDisk = 0;
    strcpy(me->filename, fName);

    /* initialize aggregates */
    me->outputQueue = Queue_create();

    /* initialize subclass virtual operations ptrs */
    me->is_full  = is_fullfunction;
    me->is_empty = is_emptyfunction;
    me->get_size = get_sizefunction;
    me->insert  = insertfunction;
    me->remove  = removefunction;
    me->flush   = flushfunction;
    me->load    = loadfunction;

}
/* operation Cleanup() */
void CachedQueue_Cleanup(CachedQueue* const me) {
    Queue_cleanup(me->queue);
}
/* operation is_full() */
int CachedQueue_is_full(CachedQueue* const me) {
    return
        me->queue->is_full(me->queue) &&
        me->outputQueue->is_full(me->outputQueue);
}
/* operation is_empty() */
int CachedQueue_is_empty(CachedQueue* const me) {
    return
        me->queue->is_empty(me->queue) &&
        me->outputQueue->is_empty(me->outputQueue) &&
        (me->numberElementsOnDisk == 0);
}
/* operation get_size() */
int CachedQueue_get_size(CachedQueue* const me) {
    return
        me->queue->get_size(me->queue) +
        me->outputQueue->get_size(me->outputQueue) +
        me->numberElementsOnDisk;
}
/* operation insert(int) */
// Imsert Algorithm:
// if the queue is full,
// call flush to write out the queue to disk and reset the queue
// end if
// insert the data into the queue
void CachedQueue_insert(CachedQueue* const me, int k) {
    if (me->queue->is_full(me->queue)) me->flush(me);
    me->queue->insert(me->queue, k);
}

/* operation remove */

// remove algorithm
// if there is data in the outputQueue,
// remove it from the outputQueue
// else if there is data on disk
// call load to bring it into the outputQueue
// remove it from the outputQueue
// else if there is data in the queue
// remove it from there
// (if there is no data to remove then return sentinel value)
int CachedQueue_remove(CachedQueue* const me) {
    if (!me->outputQueue->is_empty(me->outputQueue))

        return me->outputQueue->remove(me->outputQueue);

    else if (me->numberElementsOnDisk > 0) {

        me->load(me);

        return me->queue->remove(me->queue);

    } else
        return me->queue->remove(me->queue);
}
/* operation flush */
// Precondition: this is called only when queue is full
// and filename is valid
// flush algorithm
// if file is not open, then open file
// while not queue->is_empty()
// queue->remove()
// write data to disk
// numberElementsOnDisk++
// end while
void CachedQueue_flush(CachedQueue* const me) {
// write file I/O statements here . . .
}

/* operation load */

// Precondition: this is called only when outputQueue is empty
// and filename is valid
// load algorithm
// while (!outputQueue->is_full() && (numberElementsOnDisk>0)
//
//read from start of file (i.e., oldest datum)
//numberElementsOnDisk--;
//outputQueue->insert()
// end while

void CachedQueue_load(CachedQueue* const me) {

// write file I/O statements here . . .
}
CachedQueue * CachedQueue_Create(void) {
    CachedQueue* me = (CachedQueue*) malloc(sizeof(CachedQueue));
    if (me != NULL) {
        CachedQueue_Init(me, "C:\\queuebuffer.dat",
                         CachedQueue_is_full, CachedQueue_is_empty,
                         CachedQueue_get_size, CachedQueue_insert, CachedQueue_remove,
                         CachedQueue_flush, CachedQueue_load);
    }
    return me;

}

void CachedQueue_Destroy(CachedQueue* const me) {
    if (me != NULL) {
        CachedQueue_Cleanup(me);
    }
    free(me);
}
