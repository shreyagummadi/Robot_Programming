#include "../LandBasedRobot/landbasedrobot.h"
#include "../API/api.h"

#include <iostream>
#include <memory>

/**
* @brief Class LandBasedRobot is the base class which is an abstract type
* @return returns only the methods that are being called by the derived classes.
*/

//----Methods Definitions----

//Function for moving the robot forward
void fp::LandBasedRobot::moveForward(){
//    std::cout << "LandBasedRobot::MoveForward is called\n";
}

//Function for rotate the robot 90 degrees Counter-Clockwise
void fp::LandBasedRobot::turnLeft(){
//    std::cout << "LandBasedRobot::TurnLeft is called\n";
}

//Function for rotate the robot 90 degrees Clockwise
void fp::LandBasedRobot::turnRight(){
//    std::cout << "LandBasedRobot::TurnRight is called\n";
}

//----constructor definition----

fp::LandBasedRobot::LandBasedRobot(std::string name, int x, int y, double speed, double width, double length, double height, double capacity, char direction)
: name_{name}, x_{x}, y_{y}, speed_{speed}, width_{width}, length_{length}, height_{height}, capacity_{capacity}, direction_{direction}{
        std::cerr << "LandBasedRobot::LandBasedRobot() constructor is called" << std::endl;
}
    

//----copy constructor definition----
fp::LandBasedRobot::LandBasedRobot(const LandBasedRobot &source)
: name_{source.name_}, x_{source.x_}, y_{source.y_}, speed_{source.speed_}, width_{source.width_}, length_{source.length_}, height_{source.height_}, capacity_{source.capacity_}, direction_{source.direction_}{
        std::cerr << "LandBasedRobot::LandBasedRobot() copy constructor is called" << std::endl;
} 