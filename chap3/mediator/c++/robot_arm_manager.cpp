#include "robot_arm_manager.h"
#include <iostream>

Position Robot_arm_manager::get_current_pos() {
    return curr_position_;
}

Robot_arm_manager::~Robot_arm_manager() {
    for(int i = 0; i < joints_.size(); ++i) {
        if(joints_[i] != nullptr)
            delete joints_[i];
    }
    goto_origin();
}
void Robot_arm_manager::compute_path(Position goal) {
    /* Create data for testing, not implement algorithm compute path ^^*/
    /* Assume to go to position goal need 2 step:
        get_close_object;
        grap_object;
     each step is an move_action.
    */

    Move_action get_close_object {
        {
            Move_cmd{1/*ID*/, 10/*value*/},
            Move_cmd{2/*ID*/, 12/*value*/},
            Move_cmd{3/*ID*/, 15/*value*/},
            Move_cmd{4/*ID*/, 18/*value*/},
            Move_cmd{5/*ID*/, 30/*value*/},
            Move_cmd{6/*ID*/, 40/*value*/},
            Move_cmd{7/*ID*/, 10/*value*/},
        }
    };


    Move_action grap_object{
        {
            Move_cmd{1/*ID*/, 34/*value*/},
            Move_cmd{2/*ID*/, 13/*value*/},
            Move_cmd{3/*ID*/, 35/*value*/},
            Move_cmd{4/*ID*/, 48/*value*/},
            Move_cmd{5/*ID*/, 35/*value*/},
            Move_cmd{6/*ID*/, 42/*value*/},
            Move_cmd{7/*ID*/, 10/*value*/},
        }
    };

    path_.push_back(get_close_object);
    path_.push_back(grap_object);
}
void Robot_arm_manager::goto_origin() {
    std::cout << "Goto origin: " << std::endl;
    for (auto motor : joints_) {
        motor->move(-motor->get_value());
    }
}


void Robot_arm_manager::goto_position(Position goal) {
    this->compute_path(goal);
    std::cout << "Number of step: " << path_.size() << std::endl;
    int step_index = 0;
    for (auto step : path_) {
        std::cout << "Step " << ++step_index << std::endl;
        for (auto move_cmd : step.get_action()) {
            joints_[move_cmd.get_device_id() - 1]->move(move_cmd.get_value());
        }
    }
}
