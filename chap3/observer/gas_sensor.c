#include "gas_sensor.h"
#include <stdlib.h>
#include <stdio.h>

void gas_sensor_init(gas_sensor_t* const me)
{
    int i;
    for (i = 0; i < MAX_CLIENT; ++i) {
        me->clients[i].pObject = NULL;
        me->clients[i].fn_handler = NULL;
    }
}

void gas_sensor_cleanup(gas_sensor_t* const me )
{

}

gas_sensor_t* gas_sensor_create()
{
    gas_sensor_t* sensor = (gas_sensor_t*) malloc(sizeof(gas_sensor_t));
    if (sensor != NULL) {
        gas_sensor_init(sensor);
    }
    return sensor;
}

void gas_sensor_destroy(gas_sensor_t* const me)
{
    if (me != NULL)
        gas_sensor_cleanup(me);
    free(me);
}

void gas_sensor_get_data(gas_sensor_t* const me)
{
    // printf("%s\n", __func__);

    me->data.flow_rate  = (rand() % 10);
    me->data.n2_conc    = (rand() % 200);
    me->data.o2_conc    = (rand() % 300);

    gas_sensor_notify(me);
}

void gas_sensor_notify(gas_sensor_t* const me)
{
    /**
    TODO: FIXED ME: convert to list
    */
    // printf("%s\n", __func__);
    int i;
    for (i = 0; i < MAX_CLIENT; ++i) {
        if (me->clients[i].pObject != NULL && me->clients[i].fn_handler != NULL) {
            me->clients[i].fn_handler(me->clients[i].pObject, me->data);
        }
    }
}

void gas_sensor_dumplist(gas_sensor_t* const me)
{
    printf("Dumplist:\n \t number of client: %d \n", me->n_client);
    int i;
    for (i = 0; i < MAX_CLIENT; ++i) {
        if (me->clients[i].pObject != NULL && me->clients[i].fn_handler != NULL)
            printf("\t pObject: %p \t fn_handler: %p\n", me->clients[i].pObject, me->clients[i].fn_handler );
    }
}
