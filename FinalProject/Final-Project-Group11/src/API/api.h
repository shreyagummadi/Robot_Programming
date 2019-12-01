#pragma once

#include <string>

namespace fp{

class API{
public:

/**
* @brief The API class is used to interface with the mms in order to display the walls pof the maze along with the robot at it's current position.
* A more detailed description of these functions can be found from their source located here: https://github.com/mackorone/mms 
*/

//----Methods Prototypes----

    static int mazeWidth();
    static int mazeHeight();
    
    static bool wallFront();
    static bool wallRight();
    static bool wallLeft();
    
    static void moveForward();
    static void turnRight();
    static void turnLeft();
    
    static void setWall(int x, int y, char direction);
    static void clearWall(int x, int y, char direction);
    
    static void setColor(int x, int y, char color);
    static void clearColor(int x, int y);
    static void clearAllColor();
    
    static void setText(int x, int y, const std::string& text);
    static void clearText(int x, int y);
    static void clearAllText();
    
    static bool wasReset();
    static void ackReset();

};//--class API

}//--namespace fp