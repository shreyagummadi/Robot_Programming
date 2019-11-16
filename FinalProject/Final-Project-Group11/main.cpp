/**
* @file main.cpp
* @author Raghav Agarwal <ragarwal@terpmail.umd.edu>
* Diego Camargo <camargo1@terpmail.umd.edu>
* Shreya Gummadi <shreyagummadi@gmail.com>
* Revati Naik <revatin@umd.edu>
* Akshitha Pothamshetty <apothams@terpmail.umd.edu>
* Thomas Sullivan <Tsulliv5@umd.edu>
* 
* @version 1.0
*
* @section LICENSE
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License as
* published by the Free Software Foundation; either version 2 of
* the License, or (at your option) any later version.
*
* @section DESCRIPTION
*
* This project is to develop the structure of two robots navigating and picking up 
* object in a maze, using object-oriented-programming, inheritance and polymorphism.
*/

#include "landbasedwheeled.h"
#include "landbasedtracked.h"
#include <vector>
#include <iostream>
#include <string>

/**
* @brief Two robot are asked to navigate a maze and pick up objects. It starts at a specific position in the maze (the starting position)and is asked to try to reach another position in the maze (the goal position).
* @author Raghav Agarwal <ragarwal@terpmail.umd.edu> Diego Camargo <camargo1@terpmail.umd.edu> Shreya Gummadi <shreyagummadi@gmail.com> Revati Naik <revatin@umd.edu> Akshitha Pothamshetty <apothams@terpmail.umd.edu> Thomas Sullivan <Tsulliv5@umd.edu>
*/


//--prototype
void FollowActionPath(fp::LandBasedRobot *robot, const std::vector<std::string> &vec, std::string obj);

void FollowActionPath(fp::LandBasedRobot *robot, const std::vector<std::string> &vec, std::string obj){
    int x{robot->get_x()};//--should be 1 for wheeled and 2 for tracked
    int y{robot->get_y()};//--should be 4 for wheeled and 3 for tracked
    for (auto s: vec){
        if (s.compare("up")==0)
            robot->GoUp(x,y);
        else if (s.compare("down")==0)
            robot->GoDown(x,y);
        else if (s.compare("right")==0)
            robot->TurnRight(x,y);
        else if (s.compare("left")==0)
            robot->TurnLeft(x,y);
        else if (s.compare("pickup")==0)
            robot->PickUp(obj);
        else if (s.compare("release")==0)
            robot->Release(obj);
    }
}

int main(){
    //--the following should throw an error since LandBasedRobot is an abstract class
    //fp::LandBasedRobot base_robot("none",1,2);
    
    fp::LandBasedRobot *wheeled = new fp::LandBasedWheeled("Husky",1,4);
    std::vector<std::string> action_path_wheeled {"up","right","pickup","left","down", "release"};
    FollowActionPath(wheeled,action_path_wheeled,"book");
    std::cout << "--------------------------------------------------------------------\n";
    fp::LandBasedRobot *tracked = new fp::LandBasedTracked("LT2-F",2,3);
    std::vector<std::string> action_path_tracked {"up","left","pickup","down","right", "release"};
    FollowActionPath(tracked,action_path_tracked,"cube");
    
    delete wheeled;
    delete tracked;
    return 0;
}