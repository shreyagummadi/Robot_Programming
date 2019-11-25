#include "../Algorithm/algorithm.h"
#include "../API/api.h"
#include "../Maze/maze.h"
#include "../Byte/byte.h"
#include "../History/history.h"

#include <iostream>
#include <memory>


void fp::Algorithm::solve(std::shared_ptr<fp::LandBasedRobot> robot) {
    std::cerr << "solve method entered..." << std::endl;
    // Ensure that the maze size is sane
    if (!(
        1 <= fp::Maze::WIDTH &&
        1 <= fp::Maze::HEIGHT &&
        fp::Maze::WIDTH <= 16 &&
        fp::Maze::HEIGHT <= 16
    )) {
        std::cerr << "ERROR - Maze::WIDTH and Maze::HEIGHT must be in [1, 16]"
                  << std::endl;
        return;
    }
    
    // Ensure that the maze size is as expected
    if (!(
        fp::Maze::WIDTH == fp::API::mazeWidth() &&
        fp::Maze::HEIGHT == fp::API::mazeHeight()
    )) {
        std::cerr << "WARNING - configured for "
                  << static_cast<unsigned int>(fp::Maze::WIDTH) << " x "
                  << static_cast<unsigned int>(fp::Maze::HEIGHT)
                  << " maze, but actual maze size is "
                  << fp::API::mazeWidth() << " x "
                  << fp::API::mazeHeight() << std::endl;
    }
    std::cerr << "Initializing robot..." << std::endl;
    // Initialize the robot
    robot_x = robot->getX();
    robot_y = robot->getY();
    robot_d = Direction::NORTH;
    bool isWall = false;
    
    std::cerr << "clearing maze tile colors and setting goal color to green..." << std::endl;
    // Clear all tile color, and color the center
    fp::API::clearAllColor();
    colorCenter('G');
    
    std::cerr << "entering main while loop..." << std::endl;
    while (true) {
        std::cerr << "top of the main while loop reached..." << std::endl;
        std::cerr << "x: " << static_cast<unsigned int>(robot_x) << "   y: " << static_cast<unsigned int>(robot_y) << "   Direction: " << static_cast<unsigned int>(robot_d) << std::endl;
        std::cerr << "x: " << static_cast<unsigned int>(robot->getX()) << "   y: " << static_cast<unsigned int>(robot->getY()) << "   Direction: " << robot->getDirection() << std::endl;
        // If requested, reset the robot state and undo cell wall info
        if (fp::API::wasReset()) {
            reset(robot);
        }
        std::cerr << "checking if robot reached goal position..." << std::endl;
        // If current position equals any of the goal positions, SUCCESS
        if ( ( (robot_x==fp::Maze::CLLX && robot_y==fp::Maze::CLLY) || (robot_x==fp::Maze::CLLX && robot_y==fp::Maze::CURY)
        || (robot_x==fp::Maze::CURX && robot_y==fp::Maze::CURY) || (robot_x==fp::Maze::CURX && robot_y==fp::Maze::CLLY) ) ){
            std::cerr << "Success!" << std::endl;
            reset(robot);
            break;
        }
        std::cerr << "sorry not yet, beginning algorithm..." << std::endl;
        // Need to look for a southern wall first so need to make sure the robot is facing south
        switch ( robot->getDirection() ){
            case 'N':
                std::cerr << "turning from NORTH to SOUTH..." << std::endl;
                fp::API::turnRight();
                robot->turnRight();
                fp::API::turnRight();
                robot->turnRight();
                robot_d = Direction::SOUTH;
                break;
            case 'E':
                std::cerr << "turning from EAST to SOUTH..." << std::endl;
                fp::API::turnRight();
                robot->turnRight();
                robot_d = Direction::SOUTH;
                break;
            case 'W':
                std::cerr << "turning from WEST to SOUTH..." << std::endl;
                fp::API::turnLeft();
                robot->turnLeft();
                robot_d = Direction::SOUTH;
                break;
            default:
                break;
        }
        std::cerr << "isKnown: " << fp::Maze::isKnown(robot_x, robot_y, robot_d) << std::endl;
        std::cerr << "cell: " << static_cast<unsigned int>(fp::Maze::getCell(robot_x, robot_y)) << std::endl;
        std::cerr << "m_data at cell: " << static_cast<unsigned int>(fp::Maze::m_data[fp::Maze::getCell(robot_x, robot_y)]) << std::endl;
        //Go South if no walls and not previously travelled
        std::cerr << "checking for Southern wall (and that it hasn't been previously travelled)..." << std::endl;
        if ( !(fp::API::wallFront()) && !(fp::Maze::isKnown(robot_x, robot_y, robot_d)) && !(History::travelled(robot_d)) ) {
            // Commit to memory that the robot learned that no wall exists in this direction
            std::cerr << "no southern wall found... moving the robot one cell SOUTH" << std::endl;
            isWall = false;
            setCellWall(isWall);
            std::cerr << static_cast<unsigned int>(fp::Maze::getCell(robot_x, robot_y)) << std::endl;
            // Move robot forward
            fp::API::setColor(robot_x, robot_y, 'Y');
            fp::API::moveForward();
            robot->moveForward();
            robot_y -= 1;
            // Move the tail pointer to point to new cell in History after move to new cell in maze
            std::cerr << "moving the tail pointer to point to the next cell in History stack"<< std::endl;
            History::move();
            std::cerr << static_cast<unsigned int>(fp::Maze::getCell(robot_x, robot_y)) << std::endl;
            //reset known data (properly)
            fp::Maze::resetKnown(fp::Maze::getCell(robot_x, robot_y), robot_d);
            // Return back to the top of the while loop
            continue;
        }
        // Set wall if wall and not known
        std::cerr << "double checking for southern wall (and that it isn't known)" << std::endl;
        if ( fp::API::wallFront() && !(fp::Maze::isKnown(robot_x, robot_y, robot_d)) ) {
            std::cerr << "found a southern wall... setting wall..." << std::endl;
            isWall = true;
            setCellWall(isWall);
        }
        
        std::cerr << "turning EAST..." << std::endl;
        fp::API::turnLeft();
        robot->turnLeft();
        robot_d = Direction::EAST;
        std::cerr << "checking for Eastern wall (and that it hasn't been previously travelled)..." << std::endl;
        if ( !(fp::API::wallFront()) && !(fp::Maze::isKnown(robot_x, robot_y, robot_d)) && !(History::travelled(robot_d)) ) {
            // Commit to memory that the robot learned that no wall exists in this direction
            std::cerr << "no Eastern wall found... moving the robot one cell EAST" << std::endl;
            isWall = false;
            setCellWall(isWall);
            // Move robot forward
            fp::API::setColor(robot_x, robot_y, 'Y');
            fp::API::moveForward();
            robot->moveForward();
            robot_x += 1;
            // Update History after move
            std::cerr << "moving the tail pointer to point to the next cell in History stack"<< std::endl;
            History::move();
            //reset known data (properly)
            fp::Maze::resetKnown(fp::Maze::getCell(robot_x, robot_y), robot_d);
            // Return back to the top of the while loop
            continue;
        }
        // Set wall if wall and not known
        std::cerr << "double checking for eastern wall (and that it isn't known)" << std::endl;
        if ( fp::API::wallFront() && !(fp::Maze::isKnown(robot_x, robot_y, robot_d)) ) {
            std::cerr << "found an eastern wall... setting wall..." << std::endl;
            isWall = true;
            setCellWall(isWall);
        }
        
        std::cerr << "turning NORTH..." << std::endl;
        fp::API::turnLeft();
        robot->turnLeft();
        robot_d = Direction::NORTH;
        std::cerr << "checking for Northern wall (and that it hasn't been previously travelled)..." << std::endl;
        if ( !(fp::API::wallFront()) && !(fp::Maze::isKnown(robot_x, robot_y, robot_d)) && !(History::travelled(robot_d)) ) {
            // Commit to memory that the robot learned that no wall exists in this direction
            std::cerr << "no Northern wall found... moving the robot one cell NORTH" << std::endl;
            isWall = false;
            setCellWall(isWall);
            // Move robot forward
            fp::API::setColor(robot_x, robot_y, 'Y');
            fp::API::moveForward();
            robot->moveForward();
            robot_y += 1;
            // Update history after move
            std::cerr << "moving the tail pointer to point to the next cell in History stack"<< std::endl;
            History::move();
            //reset known data (properly)
            fp::Maze::resetKnown(fp::Maze::getCell(robot_x, robot_y), robot_d);
            // Return back to the top of the while loop
            continue;
        }
        // Set wall if wall and not known
        std::cerr << "double checking for northern wall (and that it isn't known)" << std::endl;
        if ( fp::API::wallFront() && !(fp::Maze::isKnown(robot_x, robot_y, robot_d)) ) {
            std::cerr << "found an northern wall... setting wall..." << std::endl;
            isWall = true;
            setCellWall(isWall);
        }
        
        std::cerr << "turning WEST..." << std::endl;
        fp::API::turnLeft();
        robot->turnLeft();
        robot_d = Direction::WEST;
        std::cerr << "checking for Western wall (and that it hasn't been previously travelled)..." << std::endl;
        if ( !(fp::API::wallFront()) && !(fp::Maze::isKnown(robot_x, robot_y, robot_d)) && !(History::travelled(robot_d)) ) {
            // Commit to memory that the robot learned that no wall exists in this direction
            std::cerr << "no Western wall found... moving the robot one cell WEST" << std::endl;
            isWall = false;
            setCellWall(isWall);
            // Move robot forward
            fp::API::setColor(robot_x, robot_y, 'Y');
            fp::API::moveForward();
            robot->moveForward();
            robot_x -= 1;
            // Update history after move
            std::cerr << "moving the tail pointer to point to the next cell in History stack"<< std::endl;
            History::move();
            //reset known data (properly)
            fp::Maze::resetKnown(fp::Maze::getCell(robot_x, robot_y), robot_d);
            // Return back to the top of the while loop
            continue;
        }
        // Set wall if wall and not known
        std::cerr << "double checking for western wall (and that it isn't known)" << std::endl;
        if ( fp::API::wallFront() && !(fp::Maze::isKnown(robot_x, robot_y, robot_d)) ) {
            std::cerr << "found a western wall... setting wall..." << std::endl;
            isWall = true;
            setCellWall(isWall);
        }
        
        std::cerr << "no path found at current cell... clearing cell color..." << std::endl;
        fp::API::clearColor(robot_x, robot_y);
        
        // Retreat robot one cell... to do this we have to compare the x and y coordinates of the current cell
        // with the previous cell (by popping it from History to give us access to the previous cell, which then needs to be popped), then
        // we need to set the robot in that direction (turning from West to "proper direction"), and finally move
        // the robot forward and return to the top of the while loop
        std::cerr << "getting current cell..." << std::endl;
        byte current_cell =fp::Maze::getCell(robot_x, robot_y);
        std::cerr << "popping previous cell from History stack..." << std::endl;
        twobyte previous_cell_and_data = History::pop();
        byte previous_cell = History::cell(previous_cell_and_data);
        std::cerr << "comparing current position with previous position to determine which way to retreat..." << std::endl;
        // Check if current x coordinate is less than previous x coordinate (current cell is WEST of previous cell)
        // and turn 180 degrees around (turn from WEST to EAST)
        if ( fp::Maze::getX(current_cell) < (previous_cell >> 4) ) {
            std::cerr << "current position is WEST of previous position... turning WEST to EAST..." << std::endl;
            fp::API::turnRight();
            robot->turnRight();
            fp::API::turnRight();
            robot->turnRight();
            robot_d = Direction::EAST;
        }
        // Check if current y coordinate is less than previous y coordinate (current cell is SOUTH of previous cell)
        // and turn -90 degrees around (turn from WEST to NORTH)
        if ( fp::Maze::getY(current_cell) < (previous_cell &= 15) ) {
            std::cerr << "current position is SOUTH of previous position... turning WEST to NORTH..." << std::endl;
            fp::API::turnRight();
            robot->turnRight();
            robot_d = Direction::NORTH;
        }
        // Check if current y coordinate is greater than previous y coordinate (current cell is NORTH of previous cell)
        // and turn 90 degrees around (turn from WEST to SOUTH)
        if ( fp::Maze::getY(current_cell) > (previous_cell &= 15) ) {
            std::cerr << "current position is NORTH of previous position... turning WEST to SOUTH..." << std::endl;
            fp::API::turnLeft();
            robot->turnLeft();
            robot_d = Direction::SOUTH;
        }
        // Move robot forward
        std::cerr << "(retreating) moving robot forward one cell..." << std::endl;
        fp::API::moveForward();
        robot->moveForward();
        robot_x = robot->getX();
        robot_y = robot->getY();
        // Return back to the top of the while loop
    }
}

void fp::Algorithm::colorCenter(char color) {
    for (byte x = fp::Maze::CLLX; x <= fp::Maze::CURX; x += 1) {
        for (byte y = fp::Maze::CLLY; y <= fp::Maze::CURY; y += 1) {
            fp::API::setColor(x, y, color);
        }
    }
}

void fp::Algorithm::setCellWall(bool isWall) {
    byte cell = fp::Maze::getCell(robot_x, robot_y);
    fp::Maze::setWall(robot_x, robot_y, robot_d, isWall);
    byte data = fp::Maze::m_data[cell];
    static char directionChars[] = {'n', 'e', 's', 'w'};
    if ( isWall ) {
        API::setWall(robot_x, robot_y, directionChars[robot_d]);
    }
    std::cerr << "adding cell and cell wall data to History" << std::endl;
    History::add(cell, data);
}

void fp::Algorithm::reset(std::shared_ptr<fp::LandBasedRobot> robot) {

    // Acknowledge that the button was pressed
    fp::API::ackReset();

    // Reset some state
    robot_x = 0;
    robot->setX(robot_x);
    robot_y = 0;
    robot->setY(robot_y);
    robot_d = Direction::NORTH;
    robot->setDirection('N');

    // Roll back some cell wall data
    while (0 < History::size()) {
        twobyte cellAndData = History::pop();
        byte cell = History::cell(cellAndData);
        byte data = History::data(cellAndData);
        for (byte direction = 0; direction < 4; direction += 1) {
            if ((data >> (direction + 4)) & 1) {
                fp::Maze::clearWall(cell, direction);
                static char directionChars[] = {'n', 'e', 's', 'w'};
                fp::API::clearWall(fp::Maze::getX(cell), fp::Maze::getY(cell), directionChars[direction]);
            }
        }
    }
}