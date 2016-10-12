
#include "motor_proxy.h"
#include <stdlib.h>

/* Private function */

/*Encode data and wite to motor*/
static void motor_marshal(motor_proxy_t* const me, motor_data_t data);

/*Read data from motor and convert to motor_data_t*/
static motor_data_t motor_unmarshal(motor_proxy_t* const me);

void motor_init(motor_proxy_t* const me) {

}
void motor_cleanup(motor_proxy_t* const me) {

}

motor_proxy_t* motor_create() {
    motor_proxy_t* new_motor = (motor_proxy_t*) malloc(sizeof(motor_proxy_t));
    if (new_motor != NULL)
        motor_init(new_motor);
    return new_motor;
}

void motor_destroy(motor_proxy_t* const me) {
    if (me != NULL)
        motor_cleanup(me);
    free(me);
}

void motor_configure(motor_proxy_t* const me, unsigned int leng, unsigned int * addr) {
    me->motor_addr = addr;
    me->rotary_arm_length = leng;
}

direction_type_t motor_get_direction(motor_proxy_t* const me) {
    motor_data_t data;
    if (me->motor_addr == NULL)
        return ERROR;

    data = motor_unmarshal(me);
    return data.bit.direction;
}

unsigned int motor_get_speed(motor_proxy_t* const me) {
    motor_data_t data;
    if (me->motor_addr == NULL)
        return 0;

    data = motor_unmarshal(me);
    return data.bit.speed;
}
unsigned int motor_get_status(motor_proxy_t* const me) {
    motor_data_t data;
    if (me->motor_addr == NULL)
        return 0;

    data = motor_unmarshal(me);
    return data.bit.error_status;
}

void motor_set_motor_speed(motor_proxy_t* const me, unsigned int speed) {
    motor_data_t data;
    // Get current data
    data = motor_unmarshal(me);

    data.bit.speed = speed;
    motor_marshal(me, data);
}

unsigned int motor_set_direction(motor_proxy_t* const me, direction_type_t dir) {
    motor_data_t data;
    // Get current data
    data = motor_unmarshal(me);

    data.bit.direction = dir;
    motor_marshal(me, data);
}

void motor_clear_error_status(motor_proxy_t* const me) {
    motor_data_t data;
    // Get current data
    data = motor_unmarshal(me);

    data.bit.error_status = 0;
    motor_marshal(me, data);
}

void motor_disable(motor_proxy_t* const me) {
    motor_data_t data;
    data = motor_unmarshal(me);
    data.bit.on_off = 0;
    motor_marshal(me, data);

}
void motor_enable(motor_proxy_t* const me) {
    motor_data_t data;
    data = motor_unmarshal(me);
    data.bit.on_off = 1;
    motor_marshal(me, data);
}

/*Encode data and wite to motor*/
void motor_marshal(motor_proxy_t* const me, motor_data_t data) {
    /* Write to hardware*/
    *(me->motor_addr) = data.reg;
}

/*Read data from motor and convert to motor_data_t*/
motor_data_t  motor_unmarshal(motor_proxy_t* const me) {
    motor_data_t data;
    data.reg = *(me->motor_addr);
    return data;
}
