#ifndef __SLIDING_JOINT_H__
#define __SLIDING_JOINT_H__

typedef struct sliding_joint_t sliding_joint_t;
struct sliding_joint_t {
    int angle;
    char devide_id;
};

void sliding_joint_init(sliding_joint_t* const me);
void sliding_joint_cleanup(sliding_joint_t* const me);

sliding_joint_t* sliding_joint_create();
void sliding_joint_destroy(sliding_joint_t* const me);

void sliding_joint_config(sliding_joint_t* const me, char devide_id);

void sliding_joint_rotate ( sliding_joint_t* const me, int angle);
int  sliding_joint_get_angle(sliding_joint_t* const me);

#endif //__SLIDING_JOINT_H__
