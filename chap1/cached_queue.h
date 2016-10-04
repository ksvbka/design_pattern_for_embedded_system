#ifndef CACHEDQUEUE_H_

#define CACHEDQUEUE_H_

#include "queue.h"
typedef struct CachedQueue CachedQueue;
struct CachedQueue {
    Queue* queue;    /* base class */

    /* new attributes */
    char filename[80];
    int numberElementsOnDisk;

    /* aggregation in subclass */
    Queue* outputQueue;

    /* inherited virtual functions */
    int  (*is_full) (CachedQueue* const me);
    int  (*is_empty)(CachedQueue* const me);
    int  (*get_size)(CachedQueue* const me);
    void (*insert) (CachedQueue* const me, int k);
    int  (*remove) (CachedQueue* const me);

    /* new virtual functions */
    void (*flush)(CachedQueue* const me);
    void (*load)(CachedQueue* const me);
};
/* Constructors and destructors:*/
void CachedQueue_Init(CachedQueue* const me, char* fName,
                      int (*isFullfunction)(CachedQueue* const me),
                      int (*isEmptyfunction)(CachedQueue* const me),
                      int (*getSizefunction)(CachedQueue* const me),
                      void (*insertfunction)(CachedQueue* const me, int k),
                      int (*removefunction)(CachedQueue* const me),
                      void (*flushfunction)(CachedQueue* const me),
                      void (*loadfunction)(CachedQueue* const me));

void CachedQueue_Cleanup(CachedQueue* const me);

/* Operations */
int CachedQueue_is_full(CachedQueue* const me);
int CachedQueue_is_empty(CachedQueue* const me);
int CachedQueue_get_size(CachedQueue* const me);
void CachedQueue_insert(CachedQueue* const me, int k);
int CachedQueue_remove(CachedQueue* const me);
void CachedQueue_flush(CachedQueue* const me);
void CachedQueue_load(CachedQueue* const me);

CachedQueue * CachedQueue_Create(void);
void CachedQueue_Destroy(CachedQueue* const me);

#endif /*CACHEDQUEUE_H_*/
