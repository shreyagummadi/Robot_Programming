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

#include <memory>
#include "Algorithm/algorithm.h"
#include "LandBasedTracked/landbasedtracked.h"
#include "LandBasedWheeled/landbasedwheeled.h"
#include <vector>
#include <iostream>
#include <string>

/**
* @brief The program will run methods to solve the maze, generate a path from strat to goal, and drive one of the two robot to follow the path and navigate a maze from an specific position in the maze (the starting position) to reach another position in the maze (the goal position).
* @author Raghav Agarwal <ragarwal@terpmail.umd.edu> Diego Camargo <camargo1@terpmail.umd.edu> Shreya Gummadi <shreyagummadi@gmail.com> Revati Naik <revatin@umd.edu> Akshitha Pothamshetty <apothams@terpmail.umd.edu> Thomas Sullivan <Tsulliv5@umd.edu>
*/


int main(){
    std::shared_ptr<fp::LandBasedRobot> wheeled = std::make_shared<fp::LandBasedWheeled>("Husky");
    fp::Algorithm algo;
    algo.Solve(wheeled);
    return 0;
}