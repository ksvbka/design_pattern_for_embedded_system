#ifndef __ROBOT_ARM_MANAGER_H__
#define __ROBOT_ARM_MANAGER_H__

#include "sliding_joint.h"
#include "rotating_joint.h"
#include "robot_action.h"

typedef struct robot_arm_manager {
    int n_step;
    int current_step;
    int status;
    move_action_t* action;

    rotating_joint_t* rotating_joints;
    int n_rotating_joint;

    sliding_joint_t* sliding_joints;
    int n_sliding_joint;

} robot_arm_manager_t;

void robot_arm_manager_init(robot_arm_manager_t* const me);
void robot_arm_manager_cleanup(robot_arm_manager_t* const me);

void robot_arm_manager_destroy(robot_arm_manager_t* const me);
robot_arm_manager_t* robot_arm_manager_create();

void robot_arm_manager_config_rotation_joints(robot_arm_manager_t* const me,
        rotating_joint_t* rot_joint, int n_joint);

void robot_arm_manager_config_sliding_joints(robot_arm_manager_t* const me,
        sliding_joint_t* sile_joint, int n_joint);

void robot_arm_manager_compute_path(robot_arm_manager_t* const me);
int robot_arm_manager_execute(robot_arm_manager_t* const me);
int robot_arm_manager_goto_origin(robot_arm_manager_t* const me);
#endif //__ROBOT_ARM_MANAGER_H__
