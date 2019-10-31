#pragma once
#include <string>

namespace rwa3{
class LandBasedRobot{//allow dynamic binding, abstract class


/**
* @brief LandBaseRobot is the base class
* @return return the atributes, methods, constructor/destructors, and accesors and mutators
*/

//----constructor & destructor----
    public:
    //---constructor---
        LandBasedRobot(std::string name="none", int x=0, int y=0);//name is used to initialize the name_ attribute, x is used to initialize the x_ attribute, and y is used to initialize the y_ attribute.

    //---destructor---
        ~LandBasedRobot();


//----Methods Prototypes----
    public:

        void GoUp(int x_,int y_);// Move the robot up in the maze.
        void GoDown(int x_,int y_);// Move the robot down in the maze.
        void TurnLeft(int x_,int y_);// Move the robot left in the maze.
        void TurnRight(int x_,int y_);// Move the robot right in the maze.
        void PickUp(std::string);// Arm picks up an object.
        void Release(std::string);// Arm releases an object.

//----accessors & mutators----

    public:
    //---accessors---
        int get_x() const{
            return x_;
        }
        int get_y() const{
            return y_;
        }
        
    //---mutators---
        void set_x(int x){
            x_= x;
        }
        void set_y(int y){
            y_= y;
        }

//----Methods Atributes----

    protected:

/**
 * @brief protected method atributes.
 * @param name_
 * @param speed_
 * @param width_
 * @param length_
 * @param capacity_
 * @param x_
 * @param y_
 * @return string, double, int 
 */

        std::string name_;// Name of the robot.
        double speed_;// Driving speed of the robot.
        double width_;// Width of the base of the robot.
        double length_;// Length of the base of the robot.
        double height_;// Height of the base of the robot.
        double capacity_;// Payload of the arm.
        int x_;// X coordinate of the robot in the maze.
        int y_;// Y coordinate of the robot in the maze.



};//--class LandBasedRobot

}//--name namespace rwa3

