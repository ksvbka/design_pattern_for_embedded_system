#include "motor.h"
#include "rotating_motor.h"
#include "sliding_motor.h"
#include "robot_action.h"
#include "robot_arm_manager.h"

#include <iostream>
#include <stdexcept>

void robot_arm_app() {
    std::vector<Motor*> joints {new Sliding_motor{1,0},
                               new Sliding_motor{2,0},
                               new Sliding_motor{3,0},
                               new Sliding_motor{4,0},
                               new Rotating_motor{5,0},
                               new Rotating_motor{6,0},
                               new Rotating_motor{7,0},
                           };

    Robot_arm_manager left_arm({0,0,0}, joints);

    left_arm.goto_position({1,1,1});
}

int main(int argc, char const *argv[])
{
    /* code */
    try{
        robot_arm_app();
    }catch(std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
