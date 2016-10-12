#include "robot_arm_manager.h"
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LENGTH(array) (sizeof((array))/sizeof((array)[0]))

void robot_arm_manager_init(robot_arm_manager_t* const me) {
    if (me == NULL)
        return;

    me->n_step = 0;
    me->current_step = 0;
    me->status = 0;

    me->action = NULL;

    me->n_rotating_joint = 0;
    me->n_sliding_joint = 0;

    me->rotating_joints = NULL;
    me->sliding_joints  = NULL;

    /*TODO: memset all array of action to 0*/

    // ......
}

void robot_arm_manager_cleanup(robot_arm_manager_t* const me) {
    me->rotating_joints = NULL;
    me->sliding_joints = NULL;
}

void robot_arm_manager_destroy(robot_arm_manager_t* const me) {
    if (me != NULL) {
        robot_arm_manager_cleanup(me);
        free(me);
    }
}

robot_arm_manager_t* robot_arm_manager_create() {
    robot_arm_manager_t* rb_manager = (robot_arm_manager_t*) malloc(sizeof(robot_arm_manager_t));
    if (rb_manager != NULL) {
        robot_arm_manager_init(rb_manager);
    }
    return rb_manager;
}

void robot_arm_manager_config_rotation_joints(robot_arm_manager_t* const me,
        rotating_joint_t* rot_joint, int n_joint) {
    me->rotating_joints = rot_joint;
    me->n_rotating_joint = n_joint;
}

void robot_arm_manager_config_sliding_joints(robot_arm_manager_t* const me,
        sliding_joint_t* sile_joint, int n_joint) {
    me->sliding_joints = sile_joint;
    me->n_sliding_joint = n_joint;
}

void robot_arm_manager_compute_path(robot_arm_manager_t* const me) {
    /* Fake a path to demo :D */
    me->n_step = 2;
    me->current_step = 0;

    me->action = (move_action_t*) malloc(me->n_step * sizeof(move_action_t));
    /*Action 1: Getting close to the object */
    move_action_t getting_close = {
        /* rotating move*/
        {
            {0, 20}, {1, 10}, {2, 5}, {3, 4},
        },
        /* sliding move*/
        {
            {0, 40}, {1, 30}, {2, 10},
        }
    };

    /*Action 3: Grap object */
    move_action_t grap_object = {
        /* rotating move*/
        {
            {0, 30}, {1, 30}, {2, 0}, {3, 0},
        },
        /* sliding move*/
        {
            {0, 0}, {1, 0}, {2, 10},
        }
    };

    me->action[0] = getting_close;
    me->action[1] = grap_object;
}

int robot_arm_manager_execute(robot_arm_manager_t* const me) {
    me->status = 0;

    if (me->n_step == 0)
        return 0;

    int i, r, s;
    while (me->current_step < me->n_step && me->status == 0) {
        /* excetute step i*/
        printf("Excetute step %d: \n ", me->current_step);

        /* rotating move */
        printf("\tRotate movement\n");
        for (r = 0; r < me->n_rotating_joint; ++r) {
            // printf("Roatting motor ID: %d, value: %d\n", (int)(me->rotating_joints[r].devide_id), me->rotating_joints[r].value);
            rotating_joint_move(&me->rotating_joints[r], me->action[me->current_step].rotation_move[r].value);
        }

        /* sliding move*/
        printf("\tslide movement\n");
        for (s = 0; s <  me->n_sliding_joint; ++s) {
            // printf("sliding motor ID: %d, value: %d\n", (int)(me->sliding_joints[s].devide_id), me->sliding_joints[s].value );
            sliding_joint_move(&me->sliding_joints[s], me->action[me->current_step].sliding_move[s].value);
        }
        me->current_step++;
    }
    free(me->action);
    return me->status;
}

int robot_arm_manager_goto_origin(robot_arm_manager_t* const me) {
    printf("\nGoto origin\n");
    int i;
    for (i = 0; i < me->n_rotating_joint; ++i)
        rotating_joint_move(&me->rotating_joints[i], -(me->rotating_joints[i].value));
    for (i = 0; i < me->n_sliding_joint; ++i)
        sliding_joint_move(&me->sliding_joints[i], -(me->sliding_joints[i].value));
}
