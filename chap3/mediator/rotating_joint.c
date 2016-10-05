#include "rotating_joint.h"
#include <stdlib.h>
#include <stdio.h>

void rotating_joint_init(rotating_joint_t* const me) {

}
void rotating_joint_cleanup(rotating_joint_t* const me) {

}

rotating_joint_t* rotating_joint_create() {
    rotating_joint_t* joint = (rotating_joint_t*) malloc(sizeof(rotating_joint_t));
    if(!joint)
        rotating_joint_init(joint);
    return joint;
}

void rotating_joint_destroy(rotating_joint_t* const me) {
    if(!me)
        rotating_joint_cleanup(me);
}

void rotating_joint_config(rotating_joint_t* const me, char devide_id) {
    me->devide_id = devide_id;
    me->value = 0;
}

void rotating_joint_move ( rotating_joint_t* const me, int value) {
    /* demo */

    /* Update current value*/
    me->value += value;
    printf("Rotating joint: ID %d \t %d \n",me->devide_id, me->value);
}

void rotating_joint_set_value(rotating_joint_t* const me, int value) {
    me->value = value;
}

int  rotating_joint_get_value(rotating_joint_t* const me) {
        return me->value;
}
