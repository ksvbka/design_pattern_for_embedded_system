#ifndef __QUEUE_H
#define __QUEUE_H

#define QUEUE_SIZE 10

typedef struct Queue Queue;
struct Queue {
    int buffer[QUEUE_SIZE];
    int head;
    int tail;
    int size;

    int  (*is_full)  (Queue* const me);
    int  (*is_empty) (Queue* const me);
    int  (*get_size) (Queue* const me);
    void (*insert)   (Queue* const me, int k);
    int  (*remove)   (Queue* const me);
};

/* Constructor and destructor */
void Queue_init( Queue* const me,
                 int  (*is_full)  (Queue* const me),
                 int  (*is_empty) (Queue* const me),
                 int  (*get_size) (Queue* const me),
                 void (*insert)   (Queue* const me, int k),
                 int  (*remove)   (Queue* const me)
               );
void Queue_cleanup(Queue* const me);

/* Operations */
int  Queue_is_full  (Queue* const me);
int  Queue_is_empty (Queue* const me);
int  Queue_get_size (Queue* const me);
void Queue_insert   (Queue* const me, int k);
int  Queue_remove   (Queue* const me);

/**/

Queue* Queue_create();
void   Queue_destroy(Queue* const me);

#endif
