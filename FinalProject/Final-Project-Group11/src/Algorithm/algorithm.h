#pragma once

#include "../Byte/byte.h"
#include "../Direction/direction.h"
#include "../Maze/maze.h"
#include "../LandBasedRobot/landbasedrobot.h"

#include <memory>
#include <vector>


namespace fp {
    
class Algorithm {

    public:
        
        void solve(std::shared_ptr<LandBasedRobot> robot);
        
        void colorCenter(char color);
        void setCellWall(bool isWall);
        void reset(std::shared_ptr<LandBasedRobot> robot, std::vector<byte> path_vector);
        void drawPath(std::vector<byte> path_vector);
        byte robot_x; // X position of the robot
        byte robot_y; // Y position of the robot
        byte robot_d; // Direction of the robot
        
};

}