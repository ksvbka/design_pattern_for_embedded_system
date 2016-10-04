#include "sliding_joint.h"
#include <stdio.h>
#include <stdlib.h>

#define MOTOR1 1
#define MOTOR2 2
#define MOTOR3 3

int main(int argc, char const *argv[])
{
    sliding_joint_t* motor1 = sliding_joint_create();
    sliding_joint_t* motor2 = sliding_joint_create();
    sliding_joint_t* motor3 = sliding_joint_create();

    if(motor1 == NULL || motor2 == NULL || motor3 == NULL){
        printf("Can't create joint\n");
        return 0;
    }
    sliding_joint_config(motor1, MOTOR1);
    sliding_joint_config(motor2, MOTOR2);
    sliding_joint_config(motor3, MOTOR3);

    /* Action 1: get close*/
    sliding_joint_rotate(motor1, 30);
    sliding_joint_rotate(motor2, 60);
    sliding_joint_rotate(motor3, 90);

    /* Action 1: grap object*/
    sliding_joint_rotate(motor1, 10);
    sliding_joint_rotate(motor2, 40);
    sliding_joint_rotate(motor3, 20);


    printf("Check:\n");
    printf("Motor1:  %d\n", sliding_joint_get_angle(motor1));
    printf("Motor2:  %d\n", sliding_joint_get_angle(motor2));
    printf("Motor3:  %d\n", sliding_joint_get_angle(motor3));

    return 0;
}
