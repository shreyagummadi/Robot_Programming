#pragma once

#include <string>
#include <iostream>
#include <memory>

namespace fp{
    
/**
* @brief Class LandBasedRobot is the base class which is an abstract type
* @return returns only the methods that are being called by the derived classes.
*/
    
class LandBasedRobot{

    public:

/**
* @brief Constructors and destructor in class LandBasedRobot are public, and are used to make or destruct other objects from derived classes
* @return Objects from other derived classes
*/

    //---constructor initialize---
        LandBasedRobot(std::string name, int x, int y, double speed, double width, double length, double height, double capacity, char direction);

    
    //---Copy Constructor initialize---
    	LandBasedRobot(const LandBasedRobot &source);//used to construct other objects from the same class

    
    //---Destructor---	
    	virtual ~LandBasedRobot(){
        std::cerr << "LandBasedRobot::~LandBasedRobot() is called" << std::endl;
        }

/**
* @brief Methods are public and virtual in class LandBasedRobot, and work like functions.
* @return returns the function being called by the derived class which overrides them.
*/

//----Methods Prototypes----
        virtual void moveForward() = 0;// Move the robot forward.
        virtual void turnLeft() = 0;// Rotate the robot 90 degrees counter-clockwise.
        virtual void turnRight() = 0;// Rotate the robot 90 degrees clockwise.

//----accessors & mutators----

/**
* @brief accessors are constant and mutators void in class LandBasedRobot, both are public
* @return return the option to set new values in the varibles or to read the current variable of private or protected attributes.
*/

    //---accessors---
        std::string get_name() const{
            return name_;
        }
        int getX() const{
//            std::cout << "LandBasedRobot::getX() called" << std::endl;
            return x_;
        }
        int getY() const{
//            std::cout << "LandBasedRobot::getY() called" << std::endl;
            return y_;
        }
        double getSpeed() const{
            return speed_;
        }
        double getWidth() const{
            return width_;
        }
        double getLength() const{
            return length_;
        }
        double getHeight() const{
            return height_;
        }
        double getCapacity() const{
            return capacity_;
        }
        char getDirection() const{
//            std::cout << "LandBasedRobot::getDirection() called" << std::endl;
            return direction_;
        }
        
    //---mutators---
        void set_name(std::string name){
            name_= name;
        }
        void setX(int x){
//            std::cout << "LandBasedRobot::setX() called" << std::endl;
            x_= x;
        }
        void setY(int y){
//            std::cout << "LandBasedRobot::setY() called" << std::endl;
            y_= y;
        }
        void setSpeed(double speed){
            speed_= speed;
        }
        void setWidth(double width){
            width_= width;
        }
        void setLength(double length){
            length_= length;
        }
        void setHeight(double height){
            height_= height;
        }
        void setCapacity(double capacity){
            capacity_= capacity;
        }
        void setDirection(char direction){
//            std::cout << "LandBasedRobot::setDirection() called" << std::endl;
            direction_= direction;
        }

//----Attributes----

    protected:

/**
 * @brief protected method atributes that can be used by any function by using the available accesors and mutators.
 * @param name_
 * @param speed_
 * @param width_
 * @param length_
 * @param capacity_
 * @param x_
 * @param y_
 * @param direction_:robot always start facing North
 * @return the specific attributed called from an accesor or mutator (string, double, int, char) 
 */

        std::string name_;// Name of the robot.
        int x_;// X coordinate of the robot in the maze.
        int y_;// Y coordinate of the robot in the maze.
        double speed_;// Driving speed of the robot.
        double width_;// Width of the base of the robot.
        double length_;// Length of the base of the robot.
        double height_;// Height of the base of the robot.
        double capacity_;// Payload of the arm.
        char direction_;// Direction that the robot is facing in the maze. The diﬀerent possibilities are 'N' (north), 'E' (east), 'W' (west), 'S' (south).


};//--class LandBasedRobot

}//--namespace fp