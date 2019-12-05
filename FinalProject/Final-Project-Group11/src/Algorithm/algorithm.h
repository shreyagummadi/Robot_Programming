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
/**
* @brief Methods are public and return is void
* @return returns the function being called by the object from the LandBasedRobot.
*/
// Methods of the Algorithm class 
    public:

        void solve(std::shared_ptr<LandBasedRobot> robot);//solve the maze with the object robot
        void colorCenter(char color);//select color of the center (goal of the maze)
        void setCellWall(bool isWall);//method to assign a wall into maze
        void reset(std::shared_ptr<LandBasedRobot> robot, std::vector<byte> path_vector);//reset bottom will stop program
        void drawPath(std::vector<byte> path_vector);//draw path that will solve the maze
    
/**
 * @brief Protected method atributes that can be used by any function by use only by the methods of this class.
 * @param byte robot_x
 * @param byte robot_y
 * @param byte robot_d
 * @return the specific attributed called by the mothods of this class) 
 */
 
// Attributes of the Algorithm class    
    protected:
        
        byte robot_x; // X position of the robot
        byte robot_y; // Y position of the robot
        byte robot_d; // Direction of the robot
        
};

}