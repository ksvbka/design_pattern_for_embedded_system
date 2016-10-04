#ifndef __MOTOR_PROXY_H__
#define __MOTOR_PROXY_H__

#include "motor_data.h"

typedef struct motor_proxy_t motor_proxy_t;
struct motor_proxy_t {
    unsigned int rotary_arm_length;
    unsigned int *motor_addr;
};
void motor_init(motor_proxy_t* const me);
void motor_cleanup(motor_proxy_t* const me);

motor_proxy_t* motor_create();
void motor_destroy(motor_proxy_t* const me);

direction_type_t motor_get_direction(motor_proxy_t* const me);
unsigned int motor_get_speed(motor_proxy_t* const me);
unsigned int motor_get_status(motor_proxy_t* const me);
unsigned int motor_set_direction(motor_proxy_t* const me, direction_type_t dir);
void motor_set_motor_speed(motor_proxy_t* const me, unsigned int speed);
void motor_clear_error_status(motor_proxy_t* const me);
void motor_configure(motor_proxy_t* const me, unsigned int leng, unsigned int * addr);
void motor_disable(motor_proxy_t* const me);
void motor_enable(motor_proxy_t* const me);



#endif //__MOTOR_PROXY_H__
