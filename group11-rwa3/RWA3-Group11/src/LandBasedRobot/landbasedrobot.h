#pragma once
#include <string>

namespace rwa3{
class LandBasedRobot{//allow dynamic binding, abstract class

//----constructor & desctructor----
    public:
    //---constructor---
        LandBasedRobot(std::string name="none", int x=0, int y=0);//name is used to initialize the name_ attribute, x is used to initialize the x_ attribute, and y is used to initialize the y_ attribute.

    //---destructor---
        ~LandBasedRobot();


//----Methods Prototypes----(w/ virtual and override keywords)
    public:

        void GoUp(x_,y_);// Move the robot up in the maze.
        void GoDown(x_,y_);// Move the robot down in the maze.
        void TurnLeft(x_,y_);// Move the robot left in the maze.
        void TurnRight(x_,y_);// Move the robot right in the maze.
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

