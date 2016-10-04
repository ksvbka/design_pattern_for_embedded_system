#include <stdio.h>
#include "sensor.h"
#include "queue.h"

void Test_Sensor();
void Test_Queue();

int main(int argc, char const *argv[]) {
    Test_Queue();
    return 0;
}

void Test_Sensor() {
    Sensor* pSensor1 = sensor_create();
    sensor_set_filter_freq(pSensor1, 100);
    sensor_set_update_freq(pSensor1, 10);

    printf("fillter freq: %d\n", sensor_get_filter_freq(pSensor1));
    printf("update freq: %d\n", sensor_get_update_freq(pSensor1));

    sensor_destroy(pSensor1);
}

void Test_Queue() {
    int j, k, h, t;
    /* test normal queue */
    Queue * myQ;
    myQ = Queue_create();
    k = 1000;

    for (j = 0; j < QUEUE_SIZE; j++) {
        h = myQ->head;
        myQ->insert(myQ, k);
        printf("inserting %d at position %d, size =%d\n", k--, h, myQ->get_size(myQ));
    }
    printf("Inserted %d elements\n", myQ->get_size(myQ));

    for (j = 0; j < QUEUE_SIZE; j++) {
        t = myQ->tail;
        k = myQ->remove(myQ);
        printf("REMOVING %d at position %d, size =%d\n", k, t, myQ->get_size(myQ));
    }

    printf("Last item removed = %d\n", k);

    printf("Current queue size %d\n", myQ->get_size(myQ));

    puts("Queue test program");
}


