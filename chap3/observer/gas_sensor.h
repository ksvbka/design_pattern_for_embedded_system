#ifndef __GAS_SENSOR_H__
#define __GAS_SENSOR_H__

#include "gas_data.h"

#define MAX_CLIENT 10

/* Callback function for handle notifycation */
typedef void (*callback_fn) (void* pObject, gas_data_t data);


typedef struct notify_handler {
    void* pObject;              /*Pointer to client object*/
    callback_fn fn_handler;     /*Callback fn when notify*/
} notify_handler_t;

/**
 * gas_sensor implement as Observer Pattern.
 * It include an array contain notify handler and will calling callback_fn of all client
 *  when get new data.
 */
typedef struct gas_sensor {
    gas_data_t data;
    unsigned int n_client;
    notify_handler_t clients[MAX_CLIENT];
} gas_sensor_t;


void gas_sensor_init(gas_sensor_t* const me);
void gas_sensor_cleanup(gas_sensor_t* const me);
gas_sensor_t* gas_sensor_create();
void gas_sensor_destroy(gas_sensor_t* const me);

void gas_sensor_get_data(gas_sensor_t* const me);
void gas_sensor_notify(gas_sensor_t* const me);
void gas_sensor_dumplist(gas_sensor_t* const me);

#endif //__GAS_SENSOR_H__
