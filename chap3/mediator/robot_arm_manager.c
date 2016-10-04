#include "robot_arm_manager.h"
#include <stdio.h>
#include <stdlib.h>

void robot_arm_manager_init(robot_arm_manager_t* const me) {
    if(me == NULL)
        return;

    me->n_step = 0;
    me->current_step = 0;
    me->status = 0;

    /*TODO: memset all array to nullptr*/



    // ......

}

void robot_arm_manager_cleanup(robot_arm_manager_t* const me) {

}

void robot_arm_manager_destroy(robot_arm_manager_t* const me) {
    if(!me)
        robot_arm_manager_cleanup(me);
}

robot_arm_manager_t* robot_arm_manager_create() {
    robot_arm_manager_t* rb_manager = (robot_arm_manager_t*) malloc(sizeof(robot_arm_manager_t));
    if(!rb_manager){
        robot_arm_manager_init(rb_manager);
    }
    return rb_manager;
}

void robot_arm_manager_config_rotation_joints(robot_arm_manager_t* const me,
                                              rotating_joint_t* rot_joint) {
    me->rotating_joints = rot_joint;
}

void robot_arm_manager_config_sliding_joints(robot_arm_manager_t* const me,
                                              sliding_joint_t* sile_joint) {
        me->sliding_joints = sile_joint;
}

void robot_arm_manager_compute_path(robot_arm_manager_t* const me) {

}

void robot_arm_manager_execute(robot_action_t* const me) {

}
