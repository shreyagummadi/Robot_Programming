#pragma once
#include "landbasedrobot.h"


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
* @return creates/destroys LandBasedTracked objects from LandBasedTracked class
*/

    //---Derived class constructor initialize---
        LandBasedTracked(std::string name, int x, int y, double speed, double width, double length, double height, double capacity, char direction);

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


        virtual char GetDirection() override;// Get the direction of the robot in the maze.
        virtual void MoveForward() override;// Move the robot forward.
        virtual void TurnLeft() override;// Rotate the robot 90 degrees counter-clockwise.
        virtual void TurnRight() override;// Rotate the robot 90 degrees clockwise.

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