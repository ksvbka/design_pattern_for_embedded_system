#ifndef __MOTOR_H__
#define __MOTOR_H__

#include <iostream>

class Motor {
  public:
    Motor() : motor_id_(0), value_(0)
    {}
    Motor(int motor_id, int value) : motor_id_(motor_id), value_(value)
    {}
    virtual ~Motor() {};
    virtual void move(int value) {std::cout << "move" <<std::endl;};

    int get_value() { return value_;}
  protected:
    int motor_id_;
    int   value_;

};
#endif
