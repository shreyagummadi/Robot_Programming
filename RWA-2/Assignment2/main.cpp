/**
* @file main.cpp
* @author Raghav Agarwal <ragarwal@terpmail.umd.edu>
* Diego Camargo <camargo1@terpmail.umd.edu>
* Shreya Gummadi <shreyagummadi@gmail.com>
* Revati Naik <revatin@umd.edu>
* Akshitha Pothamshetty <apothams@terpmail.umd.edu>
* Thomas Sullivan <Tsulliv5@umd.edu>
* 
* @version 1.0
*
* @section LICENSE
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License as
* published by the Free Software Foundation; either version 2 of
* the License, or (at your option) any later version.
*
* @section DESCRIPTION
*
* This project is used to ask a robot to navigate a maze.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/**
* @brief A robot is asked to navigate a maze. It starts at a specific position in the maze (the starting position)and is asked to try to reach another position in the maze (the goal position).
* @author Raghav Agarwal <ragarwal@terpmail.umd.edu> Diego Camargo <camargo1@terpmail.umd.edu> Shreya Gummadi <shreyagummadi@gmail.com> Revati Naik <revatin@umd.edu> Akshitha Pothamshetty <apothams@terpmail.umd.edu> Thomas Sullivan <Tsulliv5@umd.edu>
* @param start_x starting position x-coordinate
* @param start_y starting position y-coordinate
* @param goal_x goal position x-coordinate
* @param goal_y goal position y-coordinate
* @return \f$DisplayMaze\f$  //If no path is found, display a message ”Path not found” and display the maze with the partial path (from S to where it stopped).if a path is found, display the maze with the solution path (from S to G)
*/


//create global variable that holds contents of maze.txt
std::vector<std::string> mazeVector;

//Function to read maze text file and store it to the global string vector variable, mazeVector
void ReadTextFile(){
    //read in maze.txt
    std::ifstream inFile;
    std::string textFile = "maze.txt";
    inFile.open(textFile);
    //throw error if unable to open file
    if (!inFile) {
        std::cout << "Unable to open file...make sure \"maze.txt\" is contained in debug folder" << std::endl;
        exit(1); // terminate with error
    }
    //if file can be opened then store each line of maze.txt to mazeVector
    else{
        std::string line;
        while (getline(inFile,line)){
            mazeVector.push_back(line);
        }
    }
    //close maze.txt
    inFile.close();
    return;
}

//Function to get and test user entered start and goal coordinates 
std::vector<unsigned int> GetCoordinates(){
    //create variables to store user entered coordinates
    unsigned int start_x, start_y, goal_x, goal_y;
    
    bool startBad = true;
    do {
        //prompts user to input start coordinates
        std::cout << "Enter starting coordinates (e.g. start_x start_y):"<<std::endl;
        //stores user inputs to variables
        std::cin >> start_x >> start_y;
        //correct coordinates to match indices of mazeVector
        start_y = 30 -start_y;
        //if input is entered successfully test input formatting
        if(!std::cin.fail()){
            //check to see if start position is within the boundaries of the maze
            if ( start_x>mazeVector[0].length() || start_y>mazeVector.size() ) {
            std::cout << "Starting coordinates out of maze boundary... try again" << std::endl;
            continue;
            }
            //check to see if there is an obstacle at starting position in maze
            if (mazeVector[start_y].at(start_x) == '#'){
                std::cout << "Start position is occupied by maze obstacle... try again" << std::endl;
                continue;
            }
            //if input is formatted properly leave do/while loop
            startBad = false;
        }
        //resets the input stream to allow user to try to input start coordinates again
        else{
            std::cin.clear(); //This corrects the stream.
            std::cin.ignore(); //This skips the left over stream data.
            std::cout << "Please enter an Integer only." << std::endl;
        }
    }
    while (startBad);
    
    bool goalBad = true;
    do {
        //prompts user to input start coordinates
        std::cout << "Enter goal coordinates (e.g. goal_x goal_y):"<<std::endl;
        std::cin >> goal_x >> goal_y;
        goal_y = 30 - goal_y;
        //if input is entered successfully test input formatting
        if(!std::cin.fail()){
            //check to see if goal position is within the boundaries of the maze
            if ( goal_x>mazeVector[0].length() || goal_y>mazeVector.size() ) {
            std::cout << "Goal coordinates out of maze boundary... try again" << std::endl;
            continue;
            }
            //check to see if there is an obstacle at goal position in maze
            if (mazeVector[goal_y].at(goal_x) == '#'){
                std::cout << "Goal position is occupied by maze obstacle... try again" << std::endl;
                continue;
            }
            //if input is formatted properly leave do/while loop
            goalBad = false;
        }
        //resets the input stream to allow user to try to input goal coordinates again
        else{
            std::cin.clear(); //This corrects the stream.
            std::cin.ignore(); //This skips the left over stream data.
            std::cout << "Please enter an Integer only." << std::endl;
        }
    }
    while (goalBad);
    
    //store user input start and goal coordinates to coordinates variables
    std::vector<unsigned int> coordinatesVector {start_x, start_y, goal_x, goal_y};
    return coordinatesVector;
}

//Function to recursively find an unobstructed path from the start postition to the goal position in the maze
bool FindPath(unsigned int x, unsigned int y) {
    //check to see whether the position is outside the boundaries of the maze, and if it is return false
    if ( x>mazeVector[0].length() || y>mazeVector.size() ) {
        return false;
    }
    //check to see if the position is the goal position marked by "G", and if so return true
    if ( mazeVector[y].at(x) == 'G' ) {
        return true;
    }
    //check to see if the position is occupied by an obstacle, and if so return false
    if ( mazeVector[y].at(x) == '#' ) {
        return false;
    }
    //check to see if the position is part of the solution path that has previously travelled, and if so return false
    if ( mazeVector[y].at(x) == '+' ) {
        return false;
    }
    //check to see if the position has been previously travelled and not part of the solution path, and if so return false
    if ( mazeVector[y].at(x) == 'X' ) {
        return false;
    }
    //check to see if the position is empty, and if so mark it with a "+" symbol
    if ( mazeVector[y].at(x) == ' ' ) {
        mazeVector[y].at(x) = '+';
    }
    
    //Look/Go North-recursively call FindPath and send coordinates that are "north" of the current x,y position to check for a free path
    if ( FindPath(x, (y-1)) ) {
        return true;
    }
    //Look/Go East-recursively call FindPath and send coordinates that are "east" of the current x,y position to check for a free path
    if ( FindPath((x+1), y) ) {
        return true;
    }
    //Look/Go South-recursively call FindPath and send coordinates that are "south" of the current x,y position to check for a free path
    if ( FindPath(x, (y+1)) ) {
        return true;
    }
    //Look/Go West-recursively call FindPath and send coordinates that are "west" of the current x,y position to check for a free path
    if ( FindPath((x-1), y) ) {
        return true;
    }
    //if this part of the function is reached then no available path was found and the position is marked by an "X" and returns false
    mazeVector[y].at(x) = 'X';
    return false;
}

//Function that loops through and prints the contents of mazeVector to the console
void DisplayMaze() {
    for (std::string line: mazeVector) {
        //find and clear all X symbols from the maze
        std::size_t location = line.find('X');
        while( location != std::string::npos ) {
            // Replace this occurrence of X
            line.replace(location, 1, " ");
            // Get the next occurrence of X from the current location
            location =line.find('X', location + 1);
        }
        std::cout << line << std::endl;
    }
}

int main()
{
    //Read in maze.txt and store to vector of strings
    ReadTextFile();
    
    //Prompt user to enter starting coordinates and goal coordinates
	std::vector<unsigned int> coordinatesVector {GetCoordinates()};
    
    //store start and goal coordinates
    unsigned int start_x {coordinatesVector[0]}, start_y {coordinatesVector[1]}, goal_x {coordinatesVector[2]}, goal_y {coordinatesVector[3]};
    
    //Draw S and G at start and goal coordinates in maze.txt
    mazeVector[goal_y].at(goal_x) = 'G';
    mazeVector[start_y].at(start_x) = 'S';
    
    
    //call FindPath() function to find a path in the maze from start position "S" to goal position "G"
    //if path can be found from start to finish then display maze
    if (FindPath(start_x, start_y)){
        //Display maze with solution path drawn on it
        DisplayMaze();
    }
    else{
        std::cout << "Path cannot be found. Only the partial path is displayed below." << std::endl;
        DisplayMaze();
    }
    
    
	return 0;