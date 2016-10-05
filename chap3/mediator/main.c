/*
The Robot Arm Manager receives requests to grasp objects at specific points in
space (x, y, z) and time (t). It first computes an arm trajectory via the and
produces a set of nSteps actions (up to 100). Each action is composed of a set
of commands to each of the seven servos. If the goal is achievable, then Robot
Arm Manager calls executeStep() function nSteps times to step through the computed
action sequence. At each step, any command can return an error code (non-zero)
which causes the graspAt() function to abort with an error code. Note that the
computation of the arm path via the sum of the movements of the various arm joints
is a complex exercise in geometry which, while interesting, is outside the scope
of concern for this book.
*/

#include "robot_arm_manager.h"
#include <stdio.h>
#include <stdlib.h>

#define NUM_ROTATINT_JOINT (4)
#define NUM_SLIDING_JOINT (3)


#define R_MOTOR_1 (0)
#define R_MOTOR_2 (1)
#define R_MOTOR_3 (2)
#define R_MOTOR_4 (3)

#define S_MOTOR_1 (0)
#define S_MOTOR_2 (1)
#define S_MOTOR_3 (2)

int main(int argc, char const *argv[]) {

    /*Create and config motor arm */
    rotating_joint_t motor_rotating_joints[NUM_ROTATINT_JOINT] = {
        {R_MOTOR_1, 0}, // Motor ID 0, value 0
        {R_MOTOR_2, 0}, // Motor ID 1, value 0
        {R_MOTOR_3, 0}, // Motor ID 2, value 0
        {R_MOTOR_4, 0}, // Motor ID 3, value 0
    };

    sliding_joint_t  motor_sliding_joints[NUM_SLIDING_JOINT] = {
        {S_MOTOR_1, 0}, // Motor ID 0, value 0
        {S_MOTOR_2, 0}, // Motor ID 1, value 0
        {S_MOTOR_3, 0}, // Motor ID 2, value 0
    };

    /* Crate and config left_arm */
    robot_arm_manager_t* left_arm = robot_arm_manager_create();
    if (left_arm == NULL)
        return -1;

    robot_arm_manager_config_rotation_joints(left_arm, motor_rotating_joints, 4);
    robot_arm_manager_config_sliding_joints(left_arm, motor_sliding_joints, 3);

    robot_arm_manager_compute_path(left_arm);
    robot_arm_manager_execute(left_arm);
    robot_arm_manager_goto_origin(left_arm);
    return 0;
}
