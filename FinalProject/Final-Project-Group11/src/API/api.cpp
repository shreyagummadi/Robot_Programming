#include "../API/api.h"

#include <cstdlib>
#include <iostream>

/**
* @brief The API class is used to interface with the mms in order to display the walls pof the maze along with the robot at it's current position.
* A more detailed description of these functions can be found from their source located here: https://github.com/mackorone/mms
*/

//----Methods Definitions----

// Method that returns maze's width
int fp::API::mazeWidth() {
    std::cout << "mazeWidth" << std::endl;
    std::string response;
    std::cin >> response; 
    return atoi(response.c_str());
}

// Method that returns maze's height
int fp::API::mazeHeight() {
    std::cout << "mazeHeight" << std::endl;
    std::string response;
    std::cin >> response;
    return atoi(response.c_str());
}

// Method that returns true if there is a wall in front of the robot's current position
bool fp::API::wallFront() {
    std::cout << "wallFront" << std::endl;
    std::string response;
    std::cin >> response;
    return response == "true";
}

// Method that returns true if there is a wall to the right of the robot's current position
bool fp::API::wallRight() {
    std::cout << "wallRight" << std::endl;
    std::string response;
    std::cin >> response;
    return response == "true";
}

// Method that returns true is there is a wall to the left of the robot's current position
bool fp::API::wallLeft() {
    std::cout << "wallLeft" << std::endl;
    std::string response;
    std::cin >> response;
    return response == "true";
}

// Method that moves the robot one cell forward
void fp::API::moveForward() {
    std::cout << "moveForward" << std::endl;
    std::string response;
    std::cin >> response;
    if (response != "ack") {
        std::cerr << response << std::endl;
        throw;
    }
}

// Method that turns the robot clockwise 90 degrees (right)
void fp::API::turnRight() {
    std::cout << "turnRight" << std::endl;
    std::string ack;std::cin >> ack;
}

// Method that turns the robot counter-clockwise 90 degrees (left)
void fp::API::turnLeft() {
    std::cout << "turnLeft" << std::endl;
    std::string ack;
    std::cin >> ack;
}

// Method that sets a wall at the specified x, y coordinates in the specified direction
void fp::API::setWall(int x, int y, char direction) {
    std::cout << "setWall " << x << " " << y << " " << direction << std::endl;
}

// Method that clears a wall at the specified x, y coordinates in the specified direction
void fp::API::clearWall(int x, int y, char direction) {
    std::cout << "clearWall " << x << " " << y << " " << direction << std::endl;
}

// Method that sets the color of the cell at the specified x, y coordinates
void fp::API::setColor(int x, int y, char color) {
    std::cout << "setColor " << x << " " << y << " " << color << std::endl;
}

// Method that clears the color of the cell at the specified x, y coordinates
void fp::API::clearColor(int x, int y) {
    std::cout << "clearColor " << x << " " << y << std::endl;
}

// Method that clears the color of all of the cells in the maze
void fp::API::clearAllColor() {
    std::cout << "clearAllColor" << std::endl;
}

// Method that sets the text of the cell at the specified x, y coordinates
void fp::API::setText(int x, int y, const std::string& text) {
    std::cout << "setText " << x << " " << y << " " << text << std::endl;
}

// Method that sets a wall at the specified x, y coordinates in the specified direction
void fp::API::clearText(int x, int y) {
    std::cout << "clearText " << x << " " << y << std::endl;
}

// Method that clears the text in all of the cells in the maze
void fp::API::clearAllText() {
    std::cout << "clearAllText" << std::endl;
}

// Method that returns true if the reset button was pressed in the mms 
bool fp::API::wasReset() {
    std::cout << "wasReset" << std::endl;
    std::string response;
    std::cin >> response;
    return response == "true";
}

// Method that acknowledges that the reset button was pressed in the mms
void fp::API::ackReset() {
    std::cout << "ackReset" << std::endl;
    std::string ack;
    std::cin >> ack;
}