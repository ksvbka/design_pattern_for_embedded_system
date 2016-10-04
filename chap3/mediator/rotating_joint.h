#ifndef __ROTATING_JOINT_H__
#define __ROTATING_JOINT_H__

typedef struct Rotating_joint_t Rotating_joint_t;
struct Rotating_joint_t {
    int angle;
    char devide_id;
};

void rotating_joint_init(Rotating_joint_t* const me);
void rotating_joint_cleanup(Rotating_joint_t* const me);

Rotating_joint_t* rotating_joint_create();
void rotating_joint_destroy(Rotating_joint_t* const me);

void rotating_joint_config(Rotating_joint_t* const me, char devide_id);

void rotating_joint_rotate ( Rotating_joint_t* const me, int angle);
int  rotating_joint_get_angle(Rotating_joint_t* const me);

#endif //__ROTATING_JOINT_H__
