#ifndef __ROBOT_ACTION_H__
#define __ROBOT_ACTION_H__

#define MAX_MOTOR_ROTATING (5)
#define MAX_MOTOR_SLIDING  (5)

/*
    Movement of robot device by 2 layer:
    1. move_cmd_t: movement of each motor include device_ID and value (rotating, sliding)
    2. move_action_t: group of move_cmd_t to get some goal (geting close object, grap object...)

    eg: To grap an object at (x,y,z) on time t, robot caculate and give an robot_action_t
    include all step to get the goal.
    - geting close to object.
    - grap object
    - drop object ...
*/

typedef struct move_cmd {
    char device_id;
    int  value;
}move_cmd_t;


typedef struct move_action {
    move_cmd_t rotation_move[MAX_MOTOR_ROTATING];
    move_cmd_t sliding_move[MAX_MOTOR_SLIDING];
} move_action_t;

#endif //__ROBOT_ACTION_H__
