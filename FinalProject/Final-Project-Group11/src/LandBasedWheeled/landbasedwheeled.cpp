#include "../LandBasedWheeled/landbasedwheeled.h"

#include <iostream>


//----Methods Definitions----

// The robot can increase its speed, which is translated by the number of cells in the maze that the robot can traverse in each step.
void fp::LandBasedWheeled::speedUp(int num_cells){
//    std::cout << "LandBasedWheeled::SpeedUp is called\n";
    LandBasedRobot::setSpeed(num_cells);
}

// Move the robot forward in the maze
void fp::LandBasedWheeled::moveForward(){
//    std::cout << "LandBasedWheeled::MoveForward is called\n";
    char direction = LandBasedRobot::getDirection();
    switch (direction){
        case 'N':
            LandBasedRobot::setY(y_);
//            std::cout << "case N" << std::endl;
            break;
        case 'E':
            LandBasedRobot::setX(x_);
//            std::cout << "case E" << std::endl;
            break;
        case 'S':
            LandBasedRobot::setY(y_);
//            std::cout << "case S" << std::endl;
            break;
        case 'W':
            LandBasedRobot::setY(x_);
//            std::cout << "case W" << std::endl;
            break;
        default:
            break;
    }
}

// Rotate the robot 90 degrees counter-clockwise
void fp::LandBasedWheeled::turnLeft(){
//    std::cout << "LandBasedWheeled::TurnLeft is called\n";
    char direction = LandBasedRobot::getDirection();
    switch (direction){
        case 'N':
            LandBasedRobot::setDirection('W');
//            std::cout << "Turning Left...North to West" << std::endl;
            break;
        case 'E':
            LandBasedRobot::setDirection('N');
//            std::cout << "Turning Left...East to North" << std::endl;
            break;
        case 'S':
            LandBasedRobot::setDirection('E');
//            std::cout << "Turning Left...South to East" << std::endl;
            break;
        case 'W':
            LandBasedRobot::setDirection('S');
//            std::cout << "Turning Left...West to South" << std::endl;
            break;
        default:
            break;
    }
}

// Rotate the robot 90 degrees clockwise
void fp::LandBasedWheeled::turnRight(){
//    std::cout << "LandBasedWheeled::TurnRight is called\n";
    char direction = LandBasedRobot::getDirection();
    switch (direction){
        case 'N':
            LandBasedRobot::setDirection('E');
//            std::cout << "Turning Right...North to East" << std::endl;
            break;
        case 'E':
            LandBasedRobot::setDirection('S');
//            std::cout << "Turning Right...East to South" << std::endl;
            break;
        case 'S':
            LandBasedRobot::setDirection('W');
//            std::cout << "Turning Right...South to West" << std::endl;
            break;
        case 'W':
            LandBasedRobot::setDirection('N');
//            std::cout << "Turning Right...West to North" << std::endl;
            break;
        default:
            break;
    }
}


//----Derived class constructor definition----
fp::LandBasedWheeled::LandBasedWheeled(std::string name, int x, int y, double speed, double width, double length, double height, double capacity, char direction)
    	: LandBasedRobot(name, x, y, speed, width, length, height, capacity, direction){
//        std::cout << "LandBasedWheeled::LandBasedWheeled() Derived class constructor is called" << std::endl;
//        wheel_type = new std::string;//dynamically allocate space on the heap for std::string data type
//        *wheel_type = "";//initialize pointer
}
    
//----Derived Class Copy Constructor definition----
fp::LandBasedWheeled::LandBasedWheeled(const LandBasedWheeled &source)
    	: LandBasedRobot(source){
//        std::cout << "LandBasedWheeled::LandBasedWheeled() copy constructor is called" << std::endl;
//        wheel_type = new std::string;//dynamically allocate space on the heap for std::string data type
//        *wheel_type = *source.wheel_type;//copy value of pointer attribute
        wheel_number = source.wheel_number;//copy value of wheel_number
}