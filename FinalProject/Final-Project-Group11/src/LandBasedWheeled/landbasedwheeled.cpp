#include "landbasedwheeled.h"
#include <iostream>


//----Methods Definitions----

// The robot can increase its speed, which is translated by the number of cells in the maze that the robot can traverse in each step.
void fp::LandBasedWheeled::SpeedUp(int num_cells){
    std::cout << "LandBasedWheeled::SpeedUp is called\n";
    fp::LandBasedRobot::set_speed(num_cells);
}
// Get the direction of the robot in the maze
char fp::LandBasedWheeled::GetDirection(){
    std::cout << "LandBasedWheeled::GetDirection is called\n";
    return fp::LandBasedRobot::get_direction();
}

// Move the robot forward in the maze
void fp::LandBasedWheeled::MoveForward(){
//    std::cout << "LandBasedWheeled::MoveForward is called\n";
    char direction = fp::LandBasedRobot::get_direction();
    double speed = fp::LandBasedRobot::get_speed();
    switch (direction){
        case 'N':
            fp::LandBasedRobot::set_y(y_ + 1*speed);
            break;
        case 'E':
            fp::LandBasedRobot::set_x(x_ + 1*speed);
            break;
        case 'S':
            fp::LandBasedRobot::set_y(y_ - 1*speed);
            break;
        case 'W':
            fp::LandBasedRobot::set_x(x_ - 1*speed);
            break;
        default:
            break;
    }
}

// Rotate the robot 90 degrees counter-clockwise
void fp::LandBasedWheeled::TurnLeft(){
//     std::cout << "LandBasedWheeled::TurnLeft is called\n";
    
}

// Rotate the robot 90 degrees clockwise
void fp::LandBasedWheeled::TurnRight(){
    std::cout << "LandBasedWheeled::TurnRight is called\n";
}


//----Derived class constructor definition----
fp::LandBasedWheeled::LandBasedWheeled(std::string name, int x, int y)
    	: LandBasedRobot(name, x, y){
        std::cout << "LandBasedWheeled::LandBasedWheeled() Derived class constructor is called" << std::endl;
//        wheel_type = new std::string;//dynamically allocate space on the heap for std::string data type
//        *wheel_type = "";//initialize pointer
    }
    
//----Derived Class Copy Constructor definition----
fp::LandBasedWheeled::LandBasedWheeled(const LandBasedWheeled &source)
    	: LandBasedRobot(source){
        std::cout << "LandBasedWheeled::LandBasedWheeled() copy constructor is called" << std::endl;
//        wheel_type = new std::string;//dynamically allocate space on the heap for std::string data type
//        *wheel_type = *source.wheel_type;//copy value of pointer attribute
        wheel_number = source.wheel_number;//copy value of wheel_number
    }