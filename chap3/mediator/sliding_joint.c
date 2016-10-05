#include "sliding_joint.h"
#include <stdlib.h>
#include <stdio.h>

void sliding_joint_init(sliding_joint_t* const me) {

}
void sliding_joint_cleanup(sliding_joint_t* const me) {

}

sliding_joint_t* sliding_joint_create() {
    sliding_joint_t* joint = (sliding_joint_t*) malloc(sizeof(sliding_joint_t));
    if(!joint)
        sliding_joint_init(joint);
    return joint;
}

void sliding_joint_destroy(sliding_joint_t* const me) {
    if(!me)
        sliding_joint_cleanup(me);
}

void sliding_joint_config(sliding_joint_t* const me, char devide_id) {
    me->devide_id = devide_id;
    me->value = 0;
}

void sliding_joint_move ( sliding_joint_t* const me, int value) {
    /* demo */

    /* Update current value*/
    me->value += value;
    printf("Sliding joint: ID %d \t %d \n",me->devide_id, me->value);
}

void sliding_joint_set_value(sliding_joint_t* const me, int value) {
    me->value = value;
}

int  sliding_joint_get_value(sliding_joint_t* const me) {
        return me->value;
}
