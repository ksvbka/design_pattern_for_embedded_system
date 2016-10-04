#include "rotating_joint.h"
#include <stdlib.h>
#include <stdio.h>

void rotating_joint_init(Rotating_joint_t* const me) {

}
void rotating_joint_cleanup(Rotating_joint_t* const me) {

}

Rotating_joint_t* rotating_joint_create() {
    Rotating_joint_t* joint = (Rotating_joint_t*) malloc(sizeof(Rotating_joint_t));
    if(!joint)
        rotating_joint_init(joint);
    return joint;
}

void rotating_joint_destroy(Rotating_joint_t* const me) {
    if(!me)
        rotating_joint_cleanup(me);
}

void rotating_joint_config(Rotating_joint_t* const me, char devide_id) {
    me->devide_id = devide_id;
    me->angle = 0;
}

void rotating_joint_rotate ( Rotating_joint_t* const me, int angle) {
    /* demo */

    /* Update current angle*/
    me->angle += angle;
    printf("Rotating joint: ID %d \t %d \n",me->devide_id, me->angle);
}

void rotating_joint_set_angle(Rotating_joint_t* const me, int angle) {
    me->angle = angle;
}

int  rotating_joint_get_angle(Rotating_joint_t* const me) {
        return me->angle;
}
