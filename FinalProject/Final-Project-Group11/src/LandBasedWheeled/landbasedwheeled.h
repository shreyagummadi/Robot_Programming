#pragma once
#include "../LandBasedRobot/landbasedrobot.h"


namespace fp{

/**
* @brief Derived Class LandBasedWheeled is of type concrete, which is single and public inherits from LandBasedRobot
* @return returns the attributes, methods, constructor/destructors, and accessors and mutators
*/

class LandBasedWheeled : public LandBasedRobot{


    public:
    
//----constructor & destructor----

/**
* @brief Constructors and destructor in class LandBasedWheeled are public, and are used to make/destroy objects using deep copy from base class LandBasedRobot
* @return creates/destroys LandBasedWheeled objects from LandBasedWheeled class
*/

    //---Derived class constructor initialize---
    	LandBasedWheeled(std::string name="Husky", int x=0, int y=0, double speed=1.0, double width=1.0, double length=1.0,double height=1.0, double capacity=1.0, char direction='N');

    //---Derived Class Copy Constructor---
    	LandBasedWheeled(const LandBasedWheeled &source);

    //---Derived Class Destructor---
    	virtual ~LandBasedWheeled(){
            std::cout << "LandBasedWheeled::~LandBasedWheeled() Derived Class Destructor is called" << std::endl;
//            delete wheel_type;//free allocated space on the heap created by new
    }

/**
* @brief Methods are public, dynamic binding, virtual and override in class LandBasedWheeled, and work like functions.
* @return return the function veing called by the derived class.
*/

//----Methods Prototypes----

        void SpeedUp(int num_cells);// The robot can increase its speed, which is translated by the number of cells in the maze that the robot can traverse in each step.        
        virtual char GetDirection() override;// Get the direction of the robot in the maze.
        virtual void MoveForward() override;// Move the robot forward.
        virtual void TurnLeft() override;// Rotate the robot 90 degrees counter-clockwise.
        virtual void TurnRight() override;// Rotate the robot 90 degrees clockwise.

/**
 * @brief protected method atributes that can be used only by class LandBasedWheeled
 * @param wheel_number
 * @return returns an integer signifying the number of wheels mounted on the robot.
 */

//----Methods Atributes----

    protected:

        int wheel_number;// Number of wheels mounted on the robot.
//        std::string *wheel_type;// Type of wheels mounted on the robot.

};//--class LandBasedWheeled

}//--namespace fp