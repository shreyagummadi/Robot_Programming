#pragma once
#include <string>

namespace rwa3{

class LandBasedTracked : public LandBasedRobot{

//    public:
//    LandBasedTracked();
//    ~LandBasedTracked();



//----Methods Prototypes----(w/ virtual and override keywords)
    public:

        void SpeedUp(int);// The robot can increase its speed, which is translated by the number of cells in the maze that the robot can traverse in each step.



//----Methods Atributes----

    protected:

        int wheel_number;// Number of wheels mounted on the robot.
        std::string *wheel_type;// Type of wheels mounted on the robot.




};//--class LandBasedTracked

}//--name namespace rwa3

