#pragma once

#include "../Byte/byte.h"

// Used by the maze and algorithm classes in order to encode each cardinal direction to a value
// borrowed from mackorone's mackalgo program: https://github.com/mackorone/mackalgo
struct Direction {

    static const byte NORTH = 0;
    static const byte EAST  = 1;
    static const byte SOUTH = 2;
    static const byte WEST  = 3;

};