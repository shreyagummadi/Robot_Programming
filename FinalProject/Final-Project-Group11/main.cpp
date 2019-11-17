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


int main(){
    fp::LandBasedRobot *wheeled = new fp::LandBasedWheeled("Husky");
    std::cout << wheeled->GetDirection() << std::endl;
    std::cout << wheeled->get_name() << std::endl;
    std::cout << wheeled->get_x() << std::endl;
    std::cout << wheeled->get_y() << std::endl;
    wheeled->MoveForward();
    std::cout << wheeled->get_x() << std::endl;
    std::cout << wheeled->get_y() << std::endl;
    wheeled->TurnLeft();
    std::cout << wheeled->GetDirection() << std::endl;
    wheeled->TurnLeft();
    std::cout << wheeled->GetDirection() << std::endl;
    std::cout << wheeled->get_x() << std::endl;
    std::cout << wheeled->get_y() << std::endl;
    wheeled->MoveForward();
    std::cout << wheeled->get_x() << std::endl;
    std::cout << wheeled->get_y() << std::endl;
    wheeled->TurnLeft();
    std::cout << wheeled->GetDirection() << std::endl;
    std::cout << wheeled->get_x() << std::endl;
    std::cout << wheeled->get_y() << std::endl;
    wheeled->MoveForward();
    std::cout << wheeled->get_x() << std::endl;
    std::cout << wheeled->get_y() << std::endl;
    wheeled->TurnRight();
    std::cout << wheeled->GetDirection() << std::endl;
    delete wheeled;
    return 0;
}