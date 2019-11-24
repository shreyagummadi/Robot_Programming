#include "Algorithm.h"

#include <iostream>
#include <memory>

#include "API.h"
#include "Maze.h"


void fp::Algorithm::Solve(std::shared_ptr<fp::LandBasedRobot> robot) {
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

    // Initialize the robot
    robot_x = 0;
    robot_y = 0;
    robot_d = Direction::NORTH;
    
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
        if ( ( (robot_x==fp::Maze::CLLX && robot_y==fp::Maze::CLLY) || (robot_x==fp::Maze::CLLX && robot_y==fp::Maze::CURY) 
                || (robot_x==fp::Maze::CURX && robot_y==fp::Maze::CURY) || (robot_x==fp::Maze::CURX && robot_y==fp::Maze::CLLY) ) {
            std::cerr << "Success!" << std::endl;
            reset();
            break;
        }
        
        //check to see if the position is part of the solution path that has previously travelled, and if so return false
        if ( fp::Maze::isKnown(robot_x, robot_y, robot_d)) {
//        if ( fp::API::getText( robot_x, robot_y) ) == '1' ) {
//            return false;
        }
        
        //check to see if the position has been previously travelled and not part of the solution path, and if so return false
        if ( fp::API::getText( robot_x, robot_y ) == '0' ) {
            return false;
        }
        
        //check to see if the position is empty, and if so mark it with "1"
        if ( fp::API::getText( robot_x, robot_y ) == ' ' ) {
            fp::API::setText( robot_x, robot_y, '1');
        }
        
        // Need to look for a southern wall first so need to make sure the robot is facing south
        switch ( robot.GetDirection() ){
            case 'N':
                fp::API::turnRight();
                robot.TurnRight();
                fp::API::turnRight();
                robot.TurnRight();
                robot_d = Direction::SOUTH;
                break;
            case 'E':
                fp::API::turnRight();
                robot.TurnRight();
                robot_d = Direction::SOUTH;
                break;
            case 'W':
                fp::API::turnLeft();
                robot.TurnLeft();
                robot_d = Direction::SOUTH;
                break;
            default:
                break;
        }
        
        //Go South if no walls
        if ( !fp::API::wallFront() ) {
            fp::API::setColor(robot_x, robot_y, 'Y');
            fp::API::moveForward();
            robot.MoveForward();
            robot_y = robot.get_y();
            
            History::move();
            continue;
        }
        setCellWall();
        
        fp::API::turnLeft();
        robot.TurnLeft();
        robot_d = Direction::EAST;
        if ( !fp::API::wallFront() ) {
            fp::API::setColor(robot_x, robot_y, 'Y');
            fp::API::moveForward();
            robot.MoveForward();
            robot_x = robot.get_x();
            
            History::move();
            continue;
        }
        setCellWall();
        
        fp::API::turnLeft();
        robot.TurnLeft();
        robot_d = Direction::NORTH;
        if ( !fp::API::wallFront() ) {
            fp::API::setColor(robot_x, robot_y, 'Y');
            fp::API::moveForward();
            robot.MoveForward();
            robot_y = robot.get_y();
            
            History::move();
            continue;
        }
        setCellWall();
        
        fp::API::turnLeft();
        robot.TurnLeft();
        robot_d = Direction::WEST;
        if ( !fp::API::wallFront() ) {
            fp::API::setColor(robot_x, robot_y, 'Y');
            fp::API::moveForward();
            robot.MoveForward();
            robot_x = robot.get_x();
            
            History::move();
            continue;
        }
        setCellWall();
        
        fp::API::setText( robot_x, robot_y, '0');
        clearColor(robot_x, robot_y);
        //try previous cell
    }
    
//    if ( FindPath(std::shared_ptr<fp::LandBasedRobot> robot) ) {
//        //SUCCESS
//    }
//    else {
//        //FAILURE
//    }
    
}



//bool fp::Algorithm::FindPath(std::shared_ptr<fp::LandBasedRobot> robot) {
//    switch ( robot.GetDirection() ){
//        case 'N':
//            robot.TurnRight();
//            robot.TurnRight();
//            robot_d = Direction::SOUTH;
//            break;
//        case 'E':
//            robot.TurnRight();
//            robot_d = Direction::SOUTH;
//            break;
//        case 'W':
//            robot.TurnLeft();
//            robot_d = Direction::SOUTH;
//            break;
//        default:
//            break;
//    }
//    
//    // Clear all tile color, and color the center
//    fp::API::clearAllColor();
//    fp::API::setColor(0, 0, 'G');
//    colorCenter('G');
//    
//    //check to see whether the position is outside the boundaries of the maze, and if it is return false
//    if ( (robot_x>15||robot_x<0) || (robot_y>15||robot_y<0) )  {
//        return false;
//    } 
//    //check to see if the position is the goal position marked by "G", and if so return true
//    if ( fp::API::getText( static_cast<int>(x), static_cast<int>(y) ) == 'G' ) {
//        return true;
//    }
//    //check to see if the position is part of the solution path that has previously travelled, and if so return false
////    if ( fp::Maze::isKnown(robot_x, robot_y, robot_d)) {
//    if ( fp::API::getText( static_cast<int>(x), static_cast<int>(y) ) == 'path' ) {
//        return false;
//    }
//    //check to see if the position has been previously travelled and not part of the solution path, and if so return false
//    if ( fp::API::getText( static_cast<int>(x), static_cast<int>(y) ) == 'notpath' ) {
//        return false;
//    }
//    //check to see if the position is empty, and if so mark it with a "+" symbol
//    if ( fp::API::getText( static_cast<int>(x), static_cast<int>(y) ) == ' ' ) {
//        fp::API::setText( static_cast<int>(x), static_cast<int>(y), 'path');
//    }
//    //Look/Go South-recursively call FindPath and send coordinates that are "south" of the current x,y position to check for a free path
//    if ( !fp::API::wallFront() ) {
//        
//        robot.MoveForward();
//        robot_y = y;
//        if(FindPath(x, y)){
//            return true;
//        }
//    }
//    
//    robot.TurnLeft();
//    robot_d = Direction::EAST;
//    
//    //Look/Go East-recursively call FindPath and send coordinates that are "east" of the current x,y position to check for a free path
//    if ( FindPath((x+1), y) ) {
//        return true;
//    }
//    //Look/Go North-recursively call FindPath and send coordinates that are "north" of the current x,y position to check for a free path
//    if ( FindPath(x, (y+1)) ) {
//        return true;
//    }
//
//    //Look/Go West-recursively call FindPath and send coordinates that are "west" of the current x,y position to check for a free path
//    if ( FindPath((x-1), y) ) {
//        return true;
//    }
//    //if this part of the function is reached then no available path was found and the position is marked by an "X" and returns false
//    mazeVector[y].at(x) = 'X';
//    return false;
//}

void fp::Algorithm::colorCenter(char color) {
    for (byte x = fp::Maze::CLLX; x <= fp::Maze::CURX; x += 1) {
        for (byte y = fp::Maze::CLLY; y <= fp::Maze::CURY; y += 1) {
            fp::API::setColor(x, y, color);
        }
    }
}

void fp::Algorithm::setCellWall() {
    byte cell = fp::Maze::getCell(robot_x, robot_y);
    byte data = 0;
    fp::Maze::setWall(robot_x, robot_y, robot_d, true);
    static char directionChars[] = {'n', 'e', 's', 'w'};
    if (!fp::Maze::isKnown(robot_x, robot_y, robot_d)) {
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
    robot.set_x(robot_x);
    robot_y = 0;
    robot.set_y(robot_y);
    robot_d = Direction::NORTH;
    robot.set_direction('N');

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