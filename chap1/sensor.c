#include "sensor.h"

#include <stdio.h>
#include <stdlib.h>

void sensor_init(Sensor* sensor) {
    printf("%s\n",__func__ );
}

void sensor_cleanup() {
    printf("%s\n",__func__ );
}

Sensor* sensor_create() {
    Sensor* sensor = (Sensor*) malloc(sizeof(Sensor*));
    if (sensor != NULL)
        sensor_init(sensor);
    return sensor;
}

void sensor_destroy(Sensor* sensor ) {
    if (sensor != NULL)
        sensor_cleanup(sensor);
    free(sensor);
}

/**/
int sensor_get_filter_freq(const Sensor* constme) {
    return constme->filter_freq;
}

/**/
void sensor_set_filter_freq(Sensor* constme, int filter_freq) {
    constme->filter_freq = filter_freq;
}

/**/
int sensor_get_update_freq(const Sensor* constme) {
    return constme->update_freq;
}

/**/
void sensor_set_update_freq(Sensor* constme, int update_freq) {
    constme->update_freq = update_freq;
}

/**/
int sensor_get_value(const Sensor* constme) {
    return constme->value;
}
