#pragma once 
#include <string>

namespace fp{

class API{
public:

/**
* @brief Methods are public and static in class API, and work like functions.
* @return returns the function being called by the derived class which overrides them.
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