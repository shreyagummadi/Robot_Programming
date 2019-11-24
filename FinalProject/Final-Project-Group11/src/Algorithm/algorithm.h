#pragma once

#include <memory>

#include "byte.h"
#include "direction.h"
#include "maze.h"
#include "landbasedrobot.h"


namespace fp {
    
class Algorithm {

    public:
        
        void solve(std::shared_ptr<LandBasedRobot> robot);
        
    protected:
        
        void colorCenter(char color);
        void setCellWall(bool isWall);
        void reset(std::shared_ptr<LandBasedRobot> robot);
        byte robot_x; // X position of the robot
        byte robot_y; // Y position of the robot
        byte robot_d; // Direction of the robot
        
};

}