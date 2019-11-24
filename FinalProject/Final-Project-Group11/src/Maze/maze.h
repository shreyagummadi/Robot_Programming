#pragma once

#include "byte.h"
#include "direction.h"

namespace fp {
    
class Maze {

    public:
    // Helper methods for converting between xy coordinates
    // and the maze index of the cell in the data array
    byte getX(byte cell);
    byte getY(byte cell);
    byte getCell(byte x, byte y);

    // Helper methods for querying and updating maze data
    bool isKnown(byte x, byte y, byte direction);
    bool isWall(byte x, byte y, byte direction);
    void setWall(byte x, byte y, byte direction, bool isWall);
    void clearWall(byte x, byte y, byte direction);
    bool isKnown(byte cell, byte direction);
    bool isWall(byte cell, byte direction);
    void setWall(byte cell, byte direction, bool isWall);
    void clearWall(byte cell, byte direction);
    
        // The width and height of the maze, as understood
    // by the algorithm, both of which must be in [1, 16]
    const byte WIDTH  = 16;
    const byte HEIGHT = 16;

    // The x and y positions of the lower left and upper right center cells
    const byte CLLX = (WIDTH  - 1) / 2;
    const byte CLLY = (HEIGHT - 1) / 2;
    const byte CURX = (WIDTH     ) / 2;
    const byte CURY = (HEIGHT    ) / 2;

    // For each cell, we store only eight bits of information: four bits for
    // whether we know the value of a wall, and four bits for the actual value
    //
    //    info |  known  |  walls  |
    //         |---------|---------|
    //     dir | w s e n | w s e n |
    //         |---------|---------|
    //    bits | 7 6 5 4 | 3 2 1 0 |
    //
    // Furthermore, each cell can be indexed by just eight bits: at most
    // four bits for the x position, and at most four bits for the y position
    //      
    byte m_data[WIDTH * HEIGHT];
    
    protected:



};

}