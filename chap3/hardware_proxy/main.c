#include <stdio.h>
#include "motor_data.h"
#include "motor_proxy.h"

int main(int argc, char const *argv[]) {
    motor_proxy_t* motor1 = motor_create();
    unsigned int data = 0;

    if (motor1 != NULL)
        motor_configure(motor1, 10, &data);

    motor_enable(motor1);
    motor_set_direction(motor1, FORWARD);
    motor_set_motor_speed(motor1, 100);

    printf("Motor: encoded data : %d\n", data);
    printf("Motor: speed: %d\n", motor_get_speed(motor1));
    printf("Motor: direction : %d\n", motor_get_direction(motor1));

    return 0;
}
