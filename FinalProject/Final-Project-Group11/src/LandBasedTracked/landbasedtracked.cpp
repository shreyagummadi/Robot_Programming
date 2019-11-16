#include "landbasedtracked.h"
#include <iostream>


//----Methods Definitions----
// Get the direction of the robot in the maze
char fp::LandBasedTracked::GetDirection(){
    std::cout << "LandBasedTracked::GetDirection is called\n";
    return LandBasedRobot::get_direction();
}

// Move the robot forward in the maze
void fp::LandBasedTracked::MoveForward(){
    std::cout << "LandBasedTracked::MoveForward is called\n";
}

// Rotate the robot 90 degrees counter-clockwise
void fp::LandBasedTracked::TurnLeft(){
    std::cout << "LandBasedTracked::TurnLeft is called\n";
}

// Rotate the robot 90 degrees clockwise
void fp::LandBasedTracked::TurnRight(){
    std::cout << "LandBasedTracked::TurnRight is called\n";
}


//----Derived class constructor definition----

fp::LandBasedTracked::LandBasedTracked(std::string name="Anonymous Tracked Robot", int x=0, int y=0, double speed=1.0, double width=1.0, double length=1.0,double height=1.0, double capacity=1.0, char direction='N')
    : LandBasedRobot(name, x, y, speed, width, length, height, capacity, direction){
//        std::cout << "LandBasedTracked()::LandBasedTacked() Derived class constructor is called" << std::endl;
//        track_type = new std::string;//dynamically allocate space on the heap for std::string data type
//        *track_type = "";//initialize pointer
    } 
//----Derived Class Copy Constructor definition----
   
fp::LandBasedTracked::LandBasedTracked(const LandBasedTracked &source)
    : LandBasedRobot(source){
//        std::cout << "LandBasedTracked() copy constructor is called" << std::endl;
//        track_type = new std::string;//dynamically allocate space on the heap for std::string data type
//        *track_type = *source.track_type;//copy value of pointer
    }