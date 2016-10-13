#ifndef __SLIDING_MOTOR_H__
#define __SLIDING_MOTOR_H__

#include <iostream>

class Motor;

class Sliding_motor : public Motor {
  public:
    Sliding_motor() : Motor()
    {}
    Sliding_motor(char motor_id, int value) : Motor(motor_id, value)
    {}
    void move(int value) {
        value_ += value;
        std::cout << "ID: " << motor_id_ << " sliding value: " << value << " current value : " << value_ << std::endl;
    }

};
#endif //__SLIDING_MOTOR_H__
