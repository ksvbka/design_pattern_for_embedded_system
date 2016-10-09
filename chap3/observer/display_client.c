#include "display_client.h"
#include <stdio.h>
#include <stdlib.h>


void display_client_init(display_client_t* me)
{
    me->fn_handler = display_client_handle_new_data;
}

void display_client_cleanup(display_client_t* me)
{

}

display_client_t* display_client_create()
{
    display_client_t* display_module = (display_client_t*) malloc(sizeof(display_client_t));
    if (display_module != NULL)
        display_client_init(display_module);
    return display_module;
}
void display_client_destroy(display_client_t* me)
{
    if (!me)
        display_client_cleanup(me);
    free(me);
}


void display_client_handle_new_data(void* me, gas_data_t data)
{
    ((display_client_t*)me)->data = data;
    /* Process data */
    printf("Display module :\n \t New data: %d %d %d \n",
           ((display_client_t*)me)->data.flow_rate,
           ((display_client_t*)me)->data.n2_conc,
           ((display_client_t*)me)->data.o2_conc);
}

void display_client_subcribe(display_client_t* me, gas_sensor_t* const gas_sensor)
{
    /**
        TODO:
        - client: Using list instead of array
     */

    int i;
    for (i = 0; i < MAX_CLIENT; ++i) {
        /* Already subcribe */
        if (gas_sensor->clients[i].pObject == me)
            return;
        /* Add new subcribe */
        if (gas_sensor->clients[i].pObject == NULL) {
            gas_sensor->n_client++;
            gas_sensor->clients[i].pObject = me;
            gas_sensor->clients[i].fn_handler = me->fn_handler;
            /* remove duplicate */
            int j;
            for (j = i + 1; j < MAX_CLIENT; ++j) {
                if (gas_sensor->clients[j].pObject == me) {
                    gas_sensor->clients[j].pObject = NULL;
                    gas_sensor->clients[j].fn_handler = NULL;
                }
            }
            return;
        }
    }
}


void display_client_unsubcribe(display_client_t* me, gas_sensor_t* const gas_sensor)
{
    int i;
    for ( i = 0; i < MAX_CLIENT; ++i) {
        if (gas_sensor->clients[i].pObject == me) {
            gas_sensor->clients[i].pObject = NULL;
            gas_sensor->clients[i].fn_handler = NULL;
            gas_sensor->n_client--;
            return
        }
    }
}
