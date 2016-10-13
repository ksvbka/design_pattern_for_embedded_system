#ifndef __ROTATING_MOTOR_H__
#define __ROTATING_MOTOR_H__

#include <iostream>

class Motor;

class  Rotating_motor : public Motor
{
public:
    Rotating_motor() : Motor()
    {}
    Rotating_motor(char motor_id, int value) : Motor(motor_id, value)
    {}
    void move(int value) {
        value_ += value;
        std::cout << "ID: " << motor_id_ << " rotating value: " << value << " current value : " << value_ << std::endl;

    }

};
#endif //_ROTATINGG_MOTOR_H__
