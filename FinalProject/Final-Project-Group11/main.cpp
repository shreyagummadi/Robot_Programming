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
* This project is to develop the program for two kind of robots which navigates through a maze to reach the goal location 
* which is the center of the maze, using object-oriented-programming, inheritance and dynamic polymorphism.
*/


#include "src/Algorithm/algorithm.h"
#include "src/LandBasedTracked/landbasedtracked.h"
#include "src/LandBasedWheeled/landbasedwheeled.h"

#include <memory>
#include <vector>
#include <iostream>
#include <string>

/**
* @brief The program will run methods to create a shared pointer to a LandBasedRobot object (LandBasedWheeled or LandBasedTracked type robot), which
* will be sent to the solve method in order to navigate one of the two robot types through the maze from the starting position to the goal position
* using the DFS (Depth First Search) algorithm. This program is intended to be compiled and ran inside the mms (micro mouse simulator) created by mackorone
* For instructions on how to run and build see the README.md associated with this program along with the instructions contained on mackorone's github
* page at https://github.com/mackorone/mms/blob/master/README.md .
* @author Raghav Agarwal <ragarwal@terpmail.umd.edu> Diego Camargo <camargo1@terpmail.umd.edu> Shreya Gummadi <shreyagummadi@gmail.com> Revati Naik <revatin@umd.edu> Akshitha Pothamshetty <apothams@terpmail.umd.edu> Thomas Sullivan <Tsulliv5@umd.edu>
*/


int main(){
    // Create the shared pointer, "wheeled", which points to a LandBasedWheeled type robot initialized with the name parameter, "Husky".
    std::shared_ptr<fp::LandBasedRobot> wheeled = std::make_shared<fp::LandBasedWheeled>("Husky");
    std::cerr << "Shared Pointer to LandBasedRobot object created" << std::endl;
    // Create Algorithm type object, "algo".
    fp::Algorithm algo;
    std::cerr << "calling solve method" << std::endl;
    // Call the solve method on algo with the pointer to robot object parameter, "wheeled", which will handle navigating the robot through the maze
    // using the DFS algorithm, drawing the appropriate attributes of the maze using the API 
    algo.solve(wheeled);
    return 0;
}