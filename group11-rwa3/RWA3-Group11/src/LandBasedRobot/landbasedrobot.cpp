#include "landbasedrobot.h"
#include <iostream>

//rwa3::LandBasedRobot::LandBasedRobot()
//{
//}
//
//rwa3::LandBasedRobot::~LandBasedRobot()
//{
//}


//----Methods Definitions----

void rwa3::LandBasedRobot::GoUp(int x, int y){
    std::cout << "LandBasedRobot::GoUp is called\n";
}

void rwa3::LandBasedRobot::GoDown(int x, int y){
    std::cout << "LandBasedRobot::GoDown is called\n";
}

void rwa3::LandBasedRobot::TurnLeft(int x, int y){
    std::cout << "LandBasedRobot::TunLeft is called\n";
}

void rwa3::LandBasedRobot::TurnRight(int x, int y){
    std::cout << "LandBasedRobot::TurnRight is called\n";
}

void rwa3::LandBasedRobot::PickUp(std::string){
    std::cout << "LandBasedRobot::PickUp is called\n";
}

void rwa3::LandBasedRobot::Release(std::string){
    std::cout << "LandBasedRobot::Release is called\n";
}

//----constructor definition----

rwa3::LandBasedRobot::LandBasedRobot(std::string name,int x, int y)
: name_{name},x_{x},y_{y}{};

