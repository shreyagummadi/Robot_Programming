#include "algorithm.h"

#include <iostream>
#include <memory>

#include "API/api.h"
#include "Maze/maze.h"
#include "Byte/byte.h"


void fp::Algorithm::Solve(std::shared_ptr<fp::LandBasedRobot> robot) {
     // Ensure that the maze size is sane
    if (!(
        1 <= fp::Maze::getMazeWidth() &&
        1 <= fp::Maze::getMazeHeight() &&
        fp::Maze::getMazeWidth() <= 16 &&
        fp::Maze::getMazeHeight() <= 16
    )) {
        std::cerr << "ERROR - Maze::WIDTH and Maze::HEIGHT must be in [1, 16]"
                  << std::endl;
        return;
    }

    // Ensure that the maze size is as expected
    if (!(
        fp::Maze::getMazeWidth() == fp::API::mazeWidth() &&
        fp::Maze::getMazeHeight() == fp::API::mazeHeight()
    )) {
        std::cerr << "WARNING - configured for "
                  << static_cast<unsigned int>(fp::Maze::getMazeWidth()) << " x "
                  << static_cast<unsigned int>(fp::Maze::getMazeHeight())
                  << " maze, but actual maze size is "
                  << fp::API::mazeWidth() << " x "
                  << fp::API::mazeHeight() << std::endl;
    }

    // Initialize the robot
    robot_x = robot.getX();
    robot_y = robot.getY();
    robot_d = Direction::NORTH;
    bool isWall = false;
    
    while (true) {
        
        // Clear all tile color, and color the center
        fp::API::clearAllColor();
        fp::API::setColor(0, 0, 'G');
        colorCenter('G');
        
        // If requested, reset the robot state and undo cell wall info
        if (fp::API::wasReset()) {
            reset();
        }
        
        // If current position equals any of the goal positions, SUCCESS
        if ( ( (robot_x==fp::Maze::getCLLX() && robot_y==fp::Maze::getCLLY()) || (robot_x==fp::Maze::getCLLX() && robot_y==fp::Maze::getCURY()) 
                || (robot_x==fp::Maze::getCURX() && robot_y==fp::Maze::getCURY()) || (robot_x==fp::Maze::getCURX() && robot_y==fp::Maze::getCLLY()) ) {
            std::cerr << "Success!" << std::endl;
            reset();
            break;
        }
        
        // Need to look for a southern wall first so need to make sure the robot is facing south
        switch ( robot.getDirection() ){
            case 'N':
                fp::API::turnRight();
                robot.turnRight();
                fp::API::turnRight();
                robot.turnRight();
                robot_d = Direction::SOUTH;
                break;
            case 'E':
                fp::API::turnRight();
                robot.turnRight();
                robot_d = Direction::SOUTH;
                break;
            case 'W':
                fp::API::turnLeft();
                robot.turnLeft();
                robot_d = Direction::SOUTH;
                break;
            default:
                break;
        }
        
        //Go South if no walls and not previously travelled
        if ( !(fp::API::wallFront()) && !(fp::Maze::isKnown(robot_x, robot_y, robot_d)) ) {
            // Commit to memory that the robot learned that no wall exists in this direction
            isWall = false;
            setCellWall(isWall);
            // Move robot forward
            fp::API::setColor(robot_x, robot_y, 'Y');
            fp::API::moveForward();
            robot.moveForward();
            robot_y = robot.getY();
            // Update History after move
            History::move();
            continue;
        }
        // Set wall if wall and not known
        if ( fp::API::wallFront() && !(fp::Maze::isKnown(robot_x, robot_y, robot_d)) ) {
            isWall = true;
            setCellWall(isWall);
        }
        
        fp::API::turnLeft();
        robot.turnLeft();
        robot_d = Direction::EAST;
        if ( !(fp::API::wallFront()) && !(fp::Maze::isKnown(robot_x, robot_y, robot_d)) ) {
            // Commit to memory that the robot learned that no wall exists in this direction
            isWall = false;
            setCellWall(isWall);
            // Move robot forward
            fp::API::setColor(robot_x, robot_y, 'Y');
            fp::API::moveForward();
            robot.moveForward();
            robot_x = robot.getX();
            // Update History after move
            History::move();
            // Return back to the top of the while loop
            continue;
        }
        // Set wall if wall and not known
        if ( fp::API::wallFront() && !(fp::Maze::isKnown(robot_x, robot_y, robot_d)) ) {
            isWall = true;
            setCellWall(isWall);
        }
        
        fp::API::turnLeft();
        robot.turnLeft();
        robot_d = Direction::NORTH;
        if ( !(fp::API::wallFront()) && !(fp::Maze::isKnown(robot_x, robot_y, robot_d)) ) {
            // Commit to memory that the robot learned that no wall exists in this direction
            isWall = false;
            setCellWall(isWall);
            // Move robot forward
            fp::API::setColor(robot_x, robot_y, 'Y');
            fp::API::moveForward();
            robot.moveForward();
            robot_y = robot.getY();
            // Update history after move
            History::move();
            // Return back to the top of the while loop
            continue;
        }
        // Set wall if wall and not known
        if ( fp::API::wallFront() && !(fp::Maze::isKnown(robot_x, robot_y, robot_d)) ) {
            isWall = true;
            setCellWall(isWall);
        }
        
        fp::API::turnLeft();
        robot.turnLeft();
        robot_d = Direction::WEST;
        if ( !(fp::API::wallFront()) && !(fp::Maze::isKnown(robot_x, robot_y, robot_d)) ) {
            // Commit to memory that the robot learned that no wall exists in this direction
            isWall = false;
            setCellWall(isWall);
            // Move robot forward
            fp::API::setColor(robot_x, robot_y, 'Y');
            fp::API::moveForward();
            robot.moveForward();
            robot_y = robot.getY();
            // Update history after move
            History::move();
            // Return back to the top of the while loop
            continue;
        }
        // Set wall if wall and not known
        if ( fp::API::wallFront() && !(fp::Maze::isKnown(robot_x, robot_y, robot_d)) ) {
            isWall = true;
            setCellWall(isWall);
        }
        
        fp::API::setText( robot_x, robot_y, '0');
        clearColor(robot_x, robot_y);
        
        // Retreat robot one cell... to do this we have to compare the x and y coordinates of the current cell
        // with the previous cell (by popping it from History to give us access to the previous cell, which then needs to be popped), then
        // we need to set the robot in that direction (turning from West to "proper direction"), and finally move
        // the robot forward and return to the top of the while loop
        twobyte current_cell_and_data = History::pop();
        byte current_cell = current_cell_and_data >> 8;
        twobyte previous_cell_and_data = History::pop();
        byte previous_cell = History::cell(previous_cell_and_data);
        // Check if current x coordinate is less than previous x coordinate (current cell is WEST of previous cell)
        // and turn 180 degrees around (turn from WEST to EAST)
        if ( (current_cell >> 4) < (previous_cell >> 4) ) {
            fp::API::turnRight();
            robot.turnRight();
            fp::API::turnRight();
            robot.turnRight();
            robot_d = Direction::EAST;
        }
        // Check if current y coordinate is less than previous y coordinate (current cell is SOUTH of previous cell)
        // and turn -90 degrees around (turn from WEST to NORTH)
        if ( (current_cell &= 16) < (previous_cell &= 16) ) {
            fp::API::turnRight();
            robot.turnRight();
            robot_d = Direction::NORTH;
        }
        // Check if current y coordinate is greater than previous y coordinate (current cell is NORTH of previous cell)
        // and turn 90 degrees around (turn from WEST to SOUTH)
        if ( (current_cell &= 16) > (previous_cell &= 16) ) {
            fp::API::turnLeft();
            robot.turnLeft();
            robot_d = Direction::SOUTH;
        }
        // Don't need to check for case where current cell is EAST of previous cell because robot is already facing WEST in the algorithm
        
        // Move robot forward
        fp::API::moveForward();
        robot.moveForward();
        robot_x = robot.getX();
        robot_y = robot.getY();
        // Return back to the top of the while loop
}

void fp::Algorithm::colorCenter(char color) {
    for (byte x = fp::Maze::getCLLX(); x <= fp::Maze::getCURX(); x += 1) {
        for (byte y = fp::Maze::getCLLY(); y <= fp::Maze::getCURY(); y += 1) {
            fp::API::setColor(x, y, color);
        }
    }
}

void fp::Algorithm::setCellWall(bool isWall) {
    byte cell = fp::Maze::getCell(robot_x, robot_y);
    byte data = History::;
    fp::Maze::setWall(robot_x, robot_y, robot_d, isWall);
    static char directionChars[] = {'n', 'e', 's', 'w'};
    if ( isWall ) {
        API::setWall(robot_x, robot_y directionChars[robot_d]);
        data |= 1 << (robot_d + 4);
        data |= 1 << robot_d;
    }
    
    History::add(cell, data);
}

void fp::Algorithm::reset() {

    // Acknowledge that the button was pressed
    fp::API::ackReset();

    // Reset some state
    robot_x = 0;
    robot.setX(robot_x);
    robot_y = 0;
    robot.setY(robot_y);
    robot_d = Direction::NORTH;
    robot.setDirection('N');

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