#ifndef __ROTATING_JOINT_H__
#define __ROTATING_JOINT_H__

typedef struct rotating_joint_t rotating_joint_t;
struct rotating_joint_t {
    char devide_id;
    int value;
};

void rotating_joint_init(rotating_joint_t* const me);
void rotating_joint_cleanup(rotating_joint_t* const me);

rotating_joint_t* rotating_joint_create();
void rotating_joint_destroy(rotating_joint_t* const me);

void rotating_joint_config(rotating_joint_t* const me, char devide_id);

void rotating_joint_move ( rotating_joint_t* const me, int value);
int  rotating_joint_get_value(rotating_joint_t* const me);

#endif //__ROTATING_JOINT_H__
