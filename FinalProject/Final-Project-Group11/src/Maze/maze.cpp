#include "../Maze/maze.h"

using namespace fp;

byte Maze::m_data[] = {0};

byte Maze::getX(byte cell) {
    return cell / HEIGHT;
}

byte Maze::getY(byte cell) {
    return cell % HEIGHT;
}

byte Maze::getCell(byte x, byte y) {
    return x * HEIGHT + y;
}

bool Maze::isKnown(byte x, byte y, byte direction) {
    return isKnown(getCell(x, y), direction);
}

bool Maze::isWall(byte x, byte y, byte direction) {
    return isWall(getCell(x, y), direction);
}

void Maze::setWall(byte x, byte y, byte direction, bool isWall) {
    setWall(getCell(x, y), direction, isWall);
}

void Maze::clearWall(byte x, byte y, byte direction) {
    clearWall(getCell(x, y), direction);
}

bool Maze::isKnown(byte cell, byte direction) {
    return (m_data[cell] >> (direction + 4)) & 1;
}

bool Maze::isWall(byte cell, byte direction) {
    return (m_data[cell] >> direction) & 1;
}

void Maze::resetKnown(byte cell, byte direction) {
    m_data[cell] |= 1 << (((direction + 2) % 4)+4);
}

void Maze::setWall(byte cell, byte direction, bool isWall) {
    m_data[cell] |= 1 << (direction + 4);
    m_data[cell] =
        (m_data[cell] & ~(1 << direction)) | (isWall ? 1 << direction : 0);
}

void Maze::clearWall(byte cell, byte direction) {
    m_data[cell] &= ~(1 << (direction + 4));
    m_data[cell] &= ~(1 << direction);
}