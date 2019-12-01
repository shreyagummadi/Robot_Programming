#pragma once

#include "../Byte/byte.h"
#include "../Direction/direction.h"
#include "../Maze/maze.h"
#include "../LandBasedRobot/landbasedrobot.h"

#include <memory>
#include <vector>


namespace fp {
    
/**
* @brief Algorithm Class handles solving the maze using DFS algorithm, calling the appropriate methods that are responsible for drawing walls 
* in the maze as the robot encounters them, setting the appropriate attributes of the robot object, drawing the success path of the robot, etc...
*/    

class Algorithm {

    public:
        // Methods of the Algorithm class
        void solve(std::shared_ptr<LandBasedRobot> robot);
        void colorCenter(char color);
        void setCellWall(bool isWall);
        void reset(std::shared_ptr<LandBasedRobot> robot, std::vector<byte> path_vector);
        void drawPath(std::vector<byte> path_vector);
        
        // Attributes of the Algorithm class
        byte robot_x; // X position of the robot
        byte robot_y; // Y position of the robot
        byte robot_d; // Direction of the robot
        
};

}