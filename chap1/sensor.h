#ifndef __SENSOR_H__
#define __SENSOR_H__

/* Class sensor */

typedef struct Sensor Sensor;

struct Sensor {
    int filter_freq;
    int update_freq;
    int value;
};

Sensor* sensor_create();
void    sensor_destroy(Sensor* constme);

int  sensor_get_filter_freq(const Sensor* constme);
void sensor_set_filter_freq(Sensor* constme, int filter_freq);
int  sensor_get_update_freq(const Sensor* constme);
void sensor_set_update_freq(Sensor* constme, int update_freq);
int  sensor_get_value(const Sensor* constme);

#endif
