#pragma once

#include <memory>

#include "Byte/byte.h"
#include "Direction/direction.h"
#include "Maze/maze.h"

namespace fp {
class Algorithm {

    public:
    
    void Solve(std::shared_ptr<fp::LandBasedRobot> robot);

    protected:

    void colorCenter(char color);
    void setCellWall(bool isWall);
    void reset(std::shared_ptr<fp::LandBasedRobot> robot);
    
    byte robot_x; // X position of the mouse
    byte robot_y; // Y position of the mouse
    byte robot_d; // Direction of the mouse

};

}