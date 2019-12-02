#include "../Maze/maze.h"

using namespace fp;

/**
* @brief Maze struct stores robot representation of maze, contains functions for modifying, and reading maze variables
* borrowed heavily from mackorone's mackalgo program located here: https://github.com/mackorone/mackalgo
* @return returns and calls the various functions and variables of the maze struct
*/

// array that holds representation of maze
byte Maze::m_data[] = {0};

// Getter function for x coordinate of cell
byte Maze::getX(byte cell) {
    return cell / HEIGHT;
}

// Getter function for y coordinate of cell
byte Maze::getY(byte cell) {
    return cell % HEIGHT;
}

// Getter function for cell given x and y coordinate
byte Maze::getCell(byte x, byte y) {
    return x * HEIGHT + y;
}

// Method for checking whether direction in cell has been learned previously 
bool Maze::isKnown(byte x, byte y, byte direction) {
    return isKnown(getCell(x, y), direction);
}

// Method for checking whether direction in cell is a wall
bool Maze::isWall(byte x, byte y, byte direction) {
    return isWall(getCell(x, y), direction);
}

// Method for setting a wall in the specified direction of cell
void Maze::setWall(byte x, byte y, byte direction, bool isWall) {
    setWall(getCell(x, y), direction, isWall);
}

// Method for clearing a wall in the specified direction of cell
void Maze::clearWall(byte x, byte y, byte direction) {
    clearWall(getCell(x, y), direction);
}

// Method for checking whether direction in cell has been learned previously 
bool Maze::isKnown(byte cell, byte direction) {
    return (m_data[cell] >> (direction + 4)) & 1;
}

// Method for checking whether direction in cell is a wall
bool Maze::isWall(byte cell, byte direction) {
    return (m_data[cell] >> direction) & 1;
}

// Method for setting the direction of the new cell after a move so location the robot is entering is flagged as known 
void Maze::resetKnown(byte cell, byte direction) {
    m_data[cell] |= 1 << (((direction + 2) % 4)+4);
}

// Method for setting a wall in the specified direction of cell 
void Maze::setWall(byte cell, byte direction, bool isWall) {
    m_data[cell] |= 1 << (direction + 4);
    m_data[cell] =
        (m_data[cell] & ~(1 << direction)) | (isWall ? 1 << direction : 0);
}

// Method for clearing a wall in the specified direction of cell
void Maze::clearWall(byte cell, byte direction) {
    m_data[cell] &= ~(1 << (direction + 4));
    m_data[cell] &= ~(1 << direction);
}
