#include "../Algorithm/algorithm.h"
#include "../API/api.h"
#include "../Maze/maze.h"
#include "../Byte/byte.h"

#include <iostream>
#include <memory>
#include <vector>

// Function that handles solving the maze using DFS algorithm, calling the appropriate methods that are responsible for drawing walls 
// in the maze as the robot encounters them, setting the appropriate attributes of the robot object, drawing the success path of the robot, etc...
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
    // Initialize the robot and isWall boolean
    robot_x = 0;
    robot_y = 0;
    robot_d = Direction::NORTH;
    bool isWall = false;
    
    std::cerr << "clearing maze tile colors and setting goal color to green..." << std::endl;
    // Clear all tile color, and color the center
    fp::API::clearAllColor();
    colorCenter('G');
    
    // Create path_vector which acts as the robot's memory as it navigates the maze and learns the success path 
    std::vector<byte> path_vector;
    // cell_to_add will be used to hold the cell data to be added to path_vector
    byte cell_to_add{0};
    
    // Add the starting cell to the path_vector (will always be cell 0
    path_vector.push_back(0);
    
    // Main while loop which will loop indefinitely until success condition is satisfied or reset button in the mms is hit
    std::cerr << "entering main while loop..." << std::endl;
    while (true) {
        
        std::cerr << "top of the main while loop reached..." << std::endl;
        std::cerr << "x: " << static_cast<unsigned int>(robot_x) << "   y: " << static_cast<unsigned int>(robot_y) << "   Direction: " << static_cast<unsigned int>(robot_d) << std::endl;
        std::cerr << "class x: " << robot->getX() << "   class y: " << robot->getY() << "   class Direction: " << robot->getDirection() << std::endl;
        std::cerr << "cell: " << static_cast<unsigned int>(fp::Maze::getCell(robot_x, robot_y)) << std::endl;
        std::cerr << "m_data at cell: " << static_cast<unsigned int>(fp::Maze::m_data[fp::Maze::getCell(robot_x, robot_y)]) << std::endl;;
        std::cerr << "vector size: " << path_vector.size() << std::endl;
        
        // If requested, reset the robot state and undo cell wall info
        if (fp::API::wasReset()) {
            reset(robot, path_vector);
        }
        
        // If current position equals any of the goal positions, SUCCESS
        std::cerr << "checking if robot reached goal position..." << std::endl;
        if ( ( (robot_x==fp::Maze::CLLX && robot_y==fp::Maze::CLLY) || (robot_x==fp::Maze::CLLX && robot_y==fp::Maze::CURY)
        || (robot_x==fp::Maze::CURX && robot_y==fp::Maze::CURY) || (robot_x==fp::Maze::CURX && robot_y==fp::Maze::CLLY) ) ){
            std::cerr << "Success!" << std::endl;
            reset(robot, path_vector);
            drawPath(path_vector);
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
        
        //Go South if no walls and not previously travelled
        std::cerr << "checking for Southern wall (and that it hasn't been previously travelled)..." << std::endl;
        if ( !(fp::API::wallFront()) && !(fp::Maze::isKnown(robot_x, robot_y, robot_d)) ) {
            // Commit to memory that the robot learned that no wall exists in this direction
            std::cerr << "no southern wall found... moving the robot one cell SOUTH" << std::endl;
            isWall = false;
            setCellWall(isWall);            
            // Move robot forward one cell
            fp::API::moveForward();
            robot->moveForward();
            // Decrease robot y coordinate because robot moved one cell SOUTH
            robot_y -= 1;
            //reset known data so that location robot is travelling from is recorded as known in the new cell
            fp::Maze::resetKnown(fp::Maze::getCell(robot_x, robot_y), robot_d);
            // Add new cell to path_vector
            cell_to_add = fp::Maze::getCell(robot_x, robot_y);
            path_vector.push_back(cell_to_add);
            // Return back to the top of the while loop
            continue;
        }
        // Set wall if wall and not known
        std::cerr << "double checking for southern wall (and that it isn't known)" << std::endl;
        if ( fp::API::wallFront() && !(fp::Maze::isKnown(robot_x, robot_y, robot_d)) ) {
            // Commit to memory that the robot learned that a wall exists in this direction
            std::cerr << "found a southern wall... setting wall..." << std::endl;
            isWall = true;
            setCellWall(isWall);
        }
        
        // Turn the robot left (rotate robot 90 degrees counter-clockwise-from facing SOUTH to facing EAST)
        std::cerr << "turning EAST..." << std::endl;
        fp::API::turnLeft();
        robot->turnLeft();
        robot_d = Direction::EAST;
        
        //Go East if no walls and not previously travelled 
        std::cerr << "checking for Eastern wall (and that it hasn't been previously travelled)..." << std::endl;
        if ( !(fp::API::wallFront()) && !(fp::Maze::isKnown(robot_x, robot_y, robot_d)) ) {
            // Commit to memory that the robot learned that no wall exists in this direction
            std::cerr << "no Eastern wall found... moving the robot one cell EAST" << std::endl;
            isWall = false;
            setCellWall(isWall);
            // Move robot forward one cell
            fp::API::moveForward();
            robot->moveForward();
            // Increase robot x coordinate because robot moved one cell EAST
            robot_x += 1;
            //reset known data so that location robot is travelling from is recorded as known in the new cell
            fp::Maze::resetKnown(fp::Maze::getCell(robot_x, robot_y), robot_d);
            // Add new cell to path_vector
            cell_to_add = fp::Maze::getCell(robot_x, robot_y);
            path_vector.push_back(cell_to_add);
            // Return back to the top of the while loop
            continue;
        }
        // Set wall if wall and not known
        std::cerr << "double checking for eastern wall (and that it isn't known)" << std::endl;
        if ( fp::API::wallFront() && !(fp::Maze::isKnown(robot_x, robot_y, robot_d)) ) {
            // Commit to memory that the robot learned that a wall exists in this direction
            std::cerr << "found an eastern wall... setting wall..." << std::endl;
            isWall = true;
            setCellWall(isWall);
        }
        
        std::cerr << "turning NORTH..." << std::endl;
        fp::API::turnLeft();
        robot->turnLeft();
        robot_d = Direction::NORTH;
        std::cerr << "checking for Northern wall (and that it hasn't been previously travelled)..." << std::endl;
        if ( !(fp::API::wallFront()) && !(fp::Maze::isKnown(robot_x, robot_y, robot_d)) ) {
            // Commit to memory that the robot learned that no wall exists in this direction
            std::cerr << "no Northern wall found... moving the robot one cell NORTH" << std::endl;
            isWall = false;
            setCellWall(isWall);
            // Move robot forward one cell
            fp::API::moveForward();
            robot->moveForward();
            // Increase robot y coordinate because robot moved one cell NORTH
            robot_y += 1;
            //reset known data so that location robot is travelling from is recorded as known in the new cell
            fp::Maze::resetKnown(fp::Maze::getCell(robot_x, robot_y), robot_d);
            // Add new cell to path_vector
            cell_to_add = fp::Maze::getCell(robot_x, robot_y);
            path_vector.push_back(cell_to_add);
            // Return back to the top of the while loop
            continue;
        }
        // Set wall if wall and not known
        std::cerr << "double checking for northern wall" << std::endl;
        if ( fp::API::wallFront() && !(fp::Maze::isKnown(robot_x, robot_y, robot_d)) ) {
            // Commit to memory that the robot learned that a wall exists in this direction
            std::cerr << "found an northern wall... setting wall..." << std::endl;
            isWall = true;
            setCellWall(isWall);
        }
                
        std::cerr << "turning WEST..." << std::endl;
        fp::API::turnLeft();
        robot->turnLeft();
        robot_d = Direction::WEST;
        std::cerr << "isKnown: " << fp::Maze::isKnown(robot_x, robot_y, robot_d) << std::endl;
        std::cerr << "cell: " << static_cast<unsigned int>(fp::Maze::getCell(robot_x, robot_y)) << std::endl;
        std::cerr << "m_data at cell: " << static_cast<unsigned int>(fp::Maze::m_data[fp::Maze::getCell(robot_x, robot_y)]) << std::endl;
        std::cerr << "checking for Western wall (and that it hasn't been previously travelled)..." << std::endl;
        if ( !(fp::API::wallFront()) && !(fp::Maze::isKnown(robot_x, robot_y, robot_d)) ) {
            // Commit to memory that the robot learned that no wall exists in this direction
            std::cerr << "no Western wall found... moving the robot one cell WEST" << std::endl;
            isWall = false;
            setCellWall(isWall);
            // Move robot forward one cell
            fp::API::moveForward();
            robot->moveForward();
            // Decrease robot x coordinate because robot moved one cell WEST
            robot_x -= 1;
            // Reset known data so that location robot is travelling from is recorded as known in the new cell
            fp::Maze::resetKnown(fp::Maze::getCell(robot_x, robot_y), robot_d);
            // Add new cell to path_vector
            cell_to_add = fp::Maze::getCell(robot_x, robot_y);
            path_vector.push_back(cell_to_add);
            // Return back to the top of the while loop
            continue;
        }
        // Set wall if wall and not known
        std::cerr << "double checking for western wall" << std::endl;
        if ( fp::API::wallFront() ) {
            // Commit to memory that the robot learned that a wall exists in this direction
            std::cerr << "found a western wall... setting wall..." << std::endl;
            isWall = true;
            setCellWall(isWall);
        }
        
        std::cerr << "no path found at current cell..." << std::endl;
        
        // Retreat robot one cell... to do this we have to compare the x and y coordinates of the current cell
        // with the previous cell, then we need to set the robot in that direction (turning from West to "proper" direction)
        //, and finally move the robot forward and return to the top of the while loop
        std::cerr << "comparing current position with previous position to determine which way to retreat..." << std::endl;
        byte current_cell = fp::Maze::getCell(robot_x, robot_y);
        int vec_size = path_vector.size(); 
        // Check if current x coordinate is less than previous x coordinate (current cell is WEST of previous cell)
        // and turn 180 degrees around (turn from WEST to EAST)
        std::cerr << "current x: " << static_cast<unsigned int>(robot_x) << "   prev x: "<< static_cast<unsigned int>(path_vector.at(vec_size-2)>>4) << std::endl;
        if ( robot_x < ((path_vector.at(vec_size-2)>>4)) ) {
            std::cerr << "current position is WEST of previous position... turning WEST to EAST..." << std::endl;
            fp::API::turnRight();
            robot->turnRight();
            fp::API::turnRight();
            robot->turnRight();
            robot_d = Direction::EAST;
            // Move robot forward one cell
            std::cerr << "(retreating) moving robot forward one cell..." << std::endl;
            fp::API::moveForward();
            robot->moveForward();
            // Increase robot x coordinate because robot moved one cell EAST
            robot_x += 1;
            // Remove incorrect cell from success path
            path_vector.pop_back();
            /// Reset known data so that location robot is travelling from is recorded as known in the new cell
            fp::Maze::resetKnown(current_cell, robot_d);
            // Return back to the top of the while loop
            continue;
        }
        // Check if current y coordinate is less than previous y coordinate (current cell is SOUTH of previous cell)
        // and turn -90 degrees around (turn from WEST to NORTH)
        std::cerr << "current y: " << static_cast<unsigned int>(robot_y) << "   prev y: "<< static_cast<unsigned int>(path_vector.at(vec_size-2) & 15) << std::endl;
        if ( robot_y < (path_vector.at(vec_size-2) & 15) ) {
            std::cerr << "current position is SOUTH of previous position... turning WEST to NORTH..." << std::endl;
            fp::API::turnRight();
            robot->turnRight();
            robot_d = Direction::NORTH;
            // Move robot forward one cell
            std::cerr << "(retreating) moving robot forward one cell..." << std::endl;
            fp::API::moveForward();
            robot->moveForward();
            // Increase robot y coordinate because robot moved one cell NORTH
            robot_y += 1;
            // Remove incorrect cell from success path
            path_vector.pop_back();
            // Reset known data so that location robot is travelling from is recorded as known in the new cell
            fp::Maze::resetKnown(current_cell, robot_d);
            // Return back to the top of the while loop
            continue;
        }
        // Check if current y coordinate is greater than previous y coordinate (current cell is NORTH of previous cell)
        // and turn 90 degrees around (turn from WEST to SOUTH)
        if ( robot_y > (path_vector.at(vec_size-2) & 15) ) {
            std::cerr << "current position is NORTH of previous position... turning WEST to SOUTH..." << std::endl;
            fp::API::turnLeft();
            robot->turnLeft();
            robot_d = Direction::SOUTH;
            // Move robot forward one cell
            std::cerr << "(retreating) moving robot forward one cell..." << std::endl;
            fp::API::moveForward();
            robot->moveForward();
            // Decrease robot y coordinate because robot moved one cell SOUTH
            robot_y -= 1;
            // Remove incorrect cell from success path
            path_vector.pop_back();
            // Reset known data so that location robot is travelling from is recorded as known in the new cell
            fp::Maze::resetKnown(current_cell, robot_d);
            // Return back to the top of the while loop
            continue;
        }
        
        std::cerr << "(retreating) moving robot forward one cell..." << std::endl;
        // Move robot forward one cell
        fp::API::moveForward();
        robot->moveForward();
        // Decrease robot x coordinate because robot moved one cell WEST
        robot_x -= 1;
        // Remove incorrect cell from success path
        path_vector.pop_back();
        // Reset known data so that location robot is travelling from is recorded as known in the new cell
        fp::Maze::resetKnown(current_cell, robot_d);
        // Return back to the top of the while loop
    }
}

// Function that colors the goal cells green
void fp::Algorithm::colorCenter(char color) {
    for (byte x = fp::Maze::CLLX; x <= fp::Maze::CURX; x += 1) {
        for (byte y = fp::Maze::CLLY; y <= fp::Maze::CURY; y += 1) {
            fp::API::setColor(x, y, color);
        }
    }
}

// Function that calls Maze setCellWall and API setWall in order to update representation of maze and draw walls in mms maze
void fp::Algorithm::setCellWall(bool isWall) {
    fp::Maze::setWall(robot_x, robot_y, robot_d, isWall);
    static char directionChars[] = {'n', 'e', 's', 'w'};
    if ( isWall ) {
        API::setWall(robot_x, robot_y, directionChars[robot_d]);
    }
}

// Function called when reset button in mms is pressed, and clears robot data, cell wall data and colors from maze class and mms, and clears robot memory (path_vector)
void fp::Algorithm::reset(std::shared_ptr<fp::LandBasedRobot> robot, std::vector<byte> path_vector) {

    // Acknowledge that the button was pressed
    fp::API::ackReset();

    // Reset robot attributes 
    robot_x = 0;
    robot->setX(0);
    robot_y = 0;
    robot->setY(0);
    robot_d = Direction::NORTH;
    robot->setDirection('N');
    byte cell = 0;
    
    // Clear path vector
    path_vector.clear();
    
    // Delete all cell wall data
    while (true) {
        for (byte direction = 0; direction < 4; direction += 1) {
            fp::Maze::clearWall(cell, direction);
            static char directionChars[] = {'n', 'e', 's', 'w'};
            fp::API::clearWall(fp::Maze::getX(cell), fp::Maze::getY(cell), directionChars[direction]);
        }
        if (cell ==255){
            break;
        }
        cell++;
    }
    // Clears color of all cells in maze
    fp::API::clearAllColor();
}


// Draw Success path in maze as stored in path_vector
void fp::Algorithm::drawPath(std::vector<byte> path_vector){
    for (int i = 0; i<path_vector.size(); i++) {
        byte x = path_vector.at(i)>>4;
        byte y = path_vector.at(i) & 15;
        fp::API::setColor(x, y, 'Y');
    }
}