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
    me->angle = 0;
}

void sliding_joint_rotate ( sliding_joint_t* const me, int angle) {
    /* demo */

    /* Update current angle*/
    me->angle += angle;
    printf("sliding joint: ID %d \t %d \n",me->devide_id, me->angle);
}

void sliding_joint_set_angle(sliding_joint_t* const me, int angle) {
    me->angle = angle;
}

int  sliding_joint_get_angle(sliding_joint_t* const me) {
        return me->angle;
}
