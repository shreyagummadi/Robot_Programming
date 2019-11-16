#pragma once
#include <string>


namespace fp{
    
/**
* @brief Class LandBasedRobot is the base class which is an abstract type
* @return return the only the methods that are being called by the derived classes.
*/
    
class LandBasedRobot{

// attributes, methods, constructor/destructors, and accessors and mutators
    public:
//----constructor & destructor----

/**
* @brief Costructors and destructor in class LandBasedRobot are public, and are used to make other obects from derived classes
* @return return the attribute from other classes
*/

    //---constructor initialize---
        LandBasedRobot(std::string name, int x, int y, double speed, double width, double length, height, double capacity, char direction);

    
    //---Copy Constructor initialize---
    	LandBasedRobot(const LandBasedRobot &source);//used to construct other objects from the same class

    
    //---Destructor---	
    	virtual ~LandBasedRobot(){
//        std::cout << "LandBasedRobot::~LandBasedRobot() is called" << std::endl;
    }

/**
* @brief Methods are public and virtual in class LandBasedRobot, and work like functions.
* @return return the function being called by the derived class.
*/

//----Methods Prototypes----

        virtual char GetDirection() = 0;// Get the direction of the robot in the maze.
        virtual void MoveForward() = 0;// Move the robot forward.
        virtual void TurnLeft() = 0;// Rotate the robot 90 degrees counter-clockwise.
        virtual void TurnRight() = 0;// Rotate the robot 90 degrees clockwise.

//----accessors & mutators----

/**
* @brief accessors are constant and mutators void in class LandBasedRobot, both are public
* @return return the option to set new values in the varibles or to read the current variable of private or protected attributes.
*/

    //---accessors---
        int get_x() const{
            return x_;
        }
        int get_y() const{
            return y_;
        }
        double get_speed() const{
            return speed_;
        }
        double get_width() const{
            return width_;
        }
        double get_length() const{
            return length_;
        }
        double get_height() const{
            return height_;
        }
        double get_capacity() const{
            return capacity_;
        }
        char get_direction() const{
            return direction_;
        }
        
    //---mutators---
        void set_x(int x){
            x_= x;
        }
        void set_y(int y){
            y_= y;
        }
        void set_speed(double speed){
            speed_= speed;
        }
        void set_width(double width){
            width_= width;
        }
        void set_length(double length){
            length_= length;
        }
        void set_height(double height){
            height_= height;
        }
        void set_capacity(double capacity){
            capacity_= capacity;
        }
        void set_direction(char direction){
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
 * @param direction_
 * @return the specific attributed called from an accesor or mutator (string, double, int, char) 
 */

        std::string name_;// Name of the robot.
        double speed_;// Driving speed of the robot.
        double width_;// Width of the base of the robot.
        double length_;// Length of the base of the robot.
        double height_;// Height of the base of the robot.
        double capacity_;// Payload of the arm.
        int x_;// X coordinate of the robot in the maze.
        int y_;// Y coordinate of the robot in the maze.
        char direction_;// Direction that the robot is facing in the maze. The diﬀerent possibilities are 'N' (north), 'E' (east), 'W' (west), 'S' (south).


};//--class LandBasedRobot

}//--namespace fp
