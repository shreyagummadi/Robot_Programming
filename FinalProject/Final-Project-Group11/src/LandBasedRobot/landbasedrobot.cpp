#include "landbasedrobot.h"
#include "../API/api.h"
#include <iostream>


//----Methods Definitions----

//Function for getting the current direction of the robot forward
void fp::LandBasedRobot::GetDirection(){
//    std::cout << "LandBasedRobot::GetDirection is called\n";
    Maze::getNextDirection();
    /*
     */
}

//Function for moving the robot forward
void fp::LandBasedRobot::MoveForward(){
//    std::cout << "LandBasedRobot::MoveForward is called\n";
    API::moveForward();
    /*
     */
}

//Function for rotate the robot 90 degrees Counter-Clockwise
void fp::LandBasedRobot::TurnLeft(){
//    std::cout << "LandBasedRobot::TurnLeft is called\n";
    API::turnLeft();
    /*
     */
}

//Function for rotate the robot 90 degrees Clockwise
void fp::LandBasedRobot::TurnRight(){
//    std::cout << "LandBasedRobot::TurnRight is called\n";
    API::turnRight();
    /*
     */
}

//----constructor definition----

fp::LandBasedRobot::LandBasedRobot(std::string name, int x, int y, double speed, double width, double length, double height, double capacity, char direction)
: name_{name}, x_{x}, y_{y}, speed_{speed}, width_{width}, length_{length}, height_{height}, capacity_{capacity}, direction_{direction}{
        std::cout << "LandBasedRobot::LandBasedRobot() constructor is called" << std::endl;
}
    

//----copy constructor definition----
fp::LandBasedRobot::LandBasedRobot(const LandBasedRobot &source)
: name_{source.name_}, x_{source.x_}, y_{source.y_}, speed_{source.speed_}, width_{source.width_}, length_{source.length_}, height_{source.height_}, capacity_{source.capacity_}, direction_{source.direction_}{
        std::cout << "LandBasedRobot::LandBasedRobot() copy constructor is called" << std::endl;
} 