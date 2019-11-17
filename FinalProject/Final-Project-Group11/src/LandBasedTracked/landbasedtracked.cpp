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
    char direction = LandBasedRobot::get_direction();
    double speed = LandBasedRobot::get_speed();
    switch (direction){
        case 'N':
            LandBasedRobot::set_y(y_ + 1*speed);
            std::cout << "case N" << std::endl;
            break;
        case 'E':
            LandBasedRobot::set_x(x_ + 1*speed);
            std::cout << "case E" << std::endl;
            break;
        case 'S':
            LandBasedRobot::set_y(y_ - 1*speed);
            std::cout << "case S" << std::endl;
            break;
        case 'W':
            LandBasedRobot::set_x(x_ - 1*speed);
            std::cout << "case W" << std::endl;
            break;
        default:
            break;
    }
}

// Rotate the robot 90 degrees counter-clockwise
void fp::LandBasedTracked::TurnLeft(){
    std::cout << "LandBasedTracked::TurnLeft is called\n";
    char direction = LandBasedRobot::get_direction();
    switch (direction){
        case 'N':
            LandBasedRobot::set_direction('W');
            std::cout << "Turning Left...North to West" << std::endl;
            break;
        case 'E':
            LandBasedRobot::set_direction('N');
            std::cout << "Turning Left...East to North" << std::endl;
            break;
        case 'S':
            LandBasedRobot::set_direction('E');
            std::cout << "Turning Left...South to East" << std::endl;
            break;
        case 'W':
            LandBasedRobot::set_direction('S');
            std::cout << "Turning Left...West to South" << std::endl;
            break;
        default:
            break;
    }
}

// Rotate the robot 90 degrees clockwise
void fp::LandBasedTracked::TurnRight(){
    std::cout << "LandBasedTracked::TurnRight is called\n";
    char direction = LandBasedRobot::get_direction();
    switch (direction){
        case 'N':
            LandBasedRobot::set_direction('E');
            std::cout << "Turning Right...North to East" << std::endl;
            break;
        case 'E':
            LandBasedRobot::set_direction('S');
            std::cout << "Turning Right...East to South" << std::endl;
            break;
        case 'S':
            LandBasedRobot::set_direction('W');
            std::cout << "Turning Right...South to West" << std::endl;
            break;
        case 'W':
            LandBasedRobot::set_direction('N');
            std::cout << "Turning Right...West to North" << std::endl;
            break;
        default:
            break;
    }
}


//----Derived class constructor definition----

fp::LandBasedTracked::LandBasedTracked(std::string name, int x, int y, double speed, double width, double length, double height, double capacity, char direction)
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