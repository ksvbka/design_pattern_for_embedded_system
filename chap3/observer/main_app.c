#include "gas_sensor.h"
#include "display_client.h"
#include "gas_mixer_client.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    gas_sensor_t* sensor = gas_sensor_create();

    display_client_t* lcd_display = display_client_create();
    display_client_subcribe(lcd_display, sensor);

    gas_mixer_client_t* gas_mixer = gas_mixer_client_create();
    gas_mixer_client_subcribe(gas_mixer, sensor);

    srand(NULL);
    gas_sensor_get_data(sensor);
    gas_sensor_get_data(sensor);
    gas_sensor_get_data(sensor);

    display_client_unsubcribe(lcd_display, sensor);

    gas_sensor_get_data(sensor);
    gas_sensor_get_data(sensor);

    gas_sensor_dumplist(sensor);

    gas_sensor_destroy(sensor);
    display_client_destroy(lcd_display);

    return 0;
}
