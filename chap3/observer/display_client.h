#ifndef __DISPLAY_CLIENT_H__
#define __DISPLAY_CLIENT_H__

#include "gas_data.h"
#include "gas_sensor.h"

typedef struct display_client {
    // private data of display hardware... here
    //

    gas_data_t data;
    callback_fn fn_handler;

} display_client_t;

void display_client_init(display_client_t* me);
void display_client_cleanup(display_client_t* me);
display_client_t* display_client_create();
void display_client_destroy(display_client_t* me);

void display_client_handle_new_data(void* me,gas_data_t data);
void display_client_subcribe(display_client_t* me, gas_sensor_t* const gas_sensor);
void display_client_unsubcribe(display_client_t* me, gas_sensor_t* const gas_sensor);

#endif
