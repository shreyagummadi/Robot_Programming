#include "landbasedrobot.h"
#include <iostream>


//----Methods Definitions----



//----constructor definition----

fp::LandBasedRobot::LandBasedRobot(std::string name, int x, int y, double speed, double width, double length, double height, double capacity, char direction)
: name_{name}, x_{x}, y_{y}, speed_{speed}, width_{width}, length_{length}, height_{height}, capacity_{capacity}, direction_{direction}{};
//        std::cout << "LandBasedRobot::LandBasedRobot() constructor is called" << std::endl;
    

//----copy constructor definition----
fp::LandBasedRobot::LandBasedRobot(const LandBasedRobot &source)
: name_{source.name_}, x_{source.x_}, y_{source.y_}{};
//        std::cout << "LandBasedRobot::LandBasedRobot() copy constructor is called" << std::endl; 