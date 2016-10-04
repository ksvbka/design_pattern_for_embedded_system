#ifndef __ROBOT_ACTION_H__
#define __ROBOT_ACTION_H__

#define MOTOR_OF_ARM (7) // 4 rotation and 2 sliding

struct move_cmd_t move_cmd_t;
struct move_cmd_t{
    char device_id;
    int  value;
};

typedef struct robot_action_t robot_action_t;
struct robot_action_t {
    move_cmd_t device_list[MOTOR_OF_ARM];
}

#endif //__ROBOT_ACTION_H__
