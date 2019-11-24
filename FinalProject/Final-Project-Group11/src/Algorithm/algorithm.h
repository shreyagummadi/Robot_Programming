#pragma once

#include <memory>

#include "byte.h"
#include "direction.h"
#include "maze.h"

namespace fp {
class Algorithm {

    public:
    
    void Solve(std::shared_ptr<fp::LandBasedRobot> robot);

    private:


//    static const bool FAST_STRAIGHT_AWAYS = true;

    byte robot_x; // X position of the mouse
    byte robot_y; // Y position of the mouse
    byte robot_d; // Direction of the mouse

};

}