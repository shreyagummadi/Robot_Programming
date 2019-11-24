#pragma once

#include "../LandBasedRobot/landbasedrobot.h"

namespace fp{
    
/**
* @brief Derived Class LandBasedTracked is of type concrete, which is single and public inherits from LandBasedRobot
* @return returns the attributes, methods, constructors/destructor, and accessors and mutators
*/

class LandBasedTracked : public LandBasedRobot{


    public:

//----constructor & destructor----

/**
* @brief Constructors and destructor in class LandBasedTracked are public, and are used to make/destroy objects using deep copy from base class LandBasedRobot
* @return creates/destroys LandBasedTracked objects from LandBasedRobot class
*/

    //---Derived class constructor initialize---
        LandBasedTracked(std::string name="LT2-F", int x=0, int y=0, double speed=1.0, double width=1.0, double length=1.0,double height=1.0, double capacity=1.0, char direction='N');

    //---Derived Class Copy Constructor initialize---
        LandBasedTracked(const LandBasedTracked &source);

    //---Derived Class Destructor---
        virtual ~LandBasedTracked(){
//       std::cout << "LandBasedTracked::~LandBasedTracked() is called" << std::endl;
//        delete track_type;//free allocated space on the heap created by new pointer
    }

/**
* @brief Methods are public, dynamic binding, virtual and override in class LandBasedTracked, and work like functions.
* @return return the function being called by the derived class.
*/

//----Methods Prototypes----

        virtual void moveForward() override;// Move the robot forward.
        virtual void turnLeft() override;// Rotate the robot 90 degrees counter-clockwise.
        virtual void turnRight() override;// Rotate the robot 90 degrees clockwise.

/**
 * @brief protected attributes that can be used only by class LandBasedTracked
 * @param track_type
 * @return this attribute is a string and it returns the type of track mounted on the robot.
 */



//----Attributes----

    protected:

        std::string track_type;// Type of track mounted on the robot.



};//--class LandBasedTracked

}//--namespace fp