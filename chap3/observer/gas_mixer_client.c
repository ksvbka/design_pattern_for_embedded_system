#include "gas_mixer_client.h"
#include <stdio.h>
#include <stdlib.h>


void gas_mixer_client_init(gas_mixer_client_t* me)
{
    me->fn_handler = gas_mixer_client_handle_new_data;
}

void gas_mixer_client_cleanup(gas_mixer_client_t* me)
{

}

gas_mixer_client_t* gas_mixer_client_create()
{
    gas_mixer_client_t* gas_mixer_module = (gas_mixer_client_t*) malloc(sizeof(gas_mixer_client_t));
    if (gas_mixer_module != NULL)
        gas_mixer_client_init(gas_mixer_module);
    return gas_mixer_module;
}
void gas_mixer_client_destroy(gas_mixer_client_t* me)
{
    if (!me)
        gas_mixer_client_cleanup(me);
    free(me);
}


void gas_mixer_client_handle_new_data(void* me, gas_data_t data)
{
    ((gas_mixer_client_t*)me)->data = data;
    /* Process data */
    printf("gas_mixer module :\n \t New data: %d %d %d \n",
           ((gas_mixer_client_t*)me)->data.flow_rate,
           ((gas_mixer_client_t*)me)->data.n2_conc,
           ((gas_mixer_client_t*)me)->data.o2_conc);
}

void gas_mixer_client_subcribe(gas_mixer_client_t* me, gas_sensor_t* const gas_sensor)
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


void gas_mixer_client_unsubcribe(gas_mixer_client_t* me, gas_sensor_t* const gas_sensor)
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
