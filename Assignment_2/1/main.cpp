
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
* This project is just used to ask a robot to naigate a maze.
*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/**
* @brief A robot is asked to navigate a maze. It starts at a specific position in the maze (the starting position)
and is asked to try to reach another position in the maze (the goal position).

* @author Raghav Agarwal <ragarwal@terpmail.umd.edu>
* Diego Camargo <camargo1@terpmail.umd.edu>
* Shreya Gummadi <shreyagummadi@gmail.com>
* Revati Naik <revatin@umd.edu>
* Akshitha Pothamshetty <apothams@terpmail.umd.edu>
* Thomas Sullivan <Tsulliv5@umd.edu>
* @param starting position
* @param goal position
* @return \f$If no path is found, display a message ”Path not found” and display the
maze with the partial path (from S to where it stopped).
 \f$If a path is found, display the maze with the solution path (from S to G)\f$     
*/


bool validate_points(int x, int y, std::vector<std::string> maze);
// takes in a point and the maze and checks if the point is in free space in the maze




int main(){
    int rows{0};
    int columns{0};
    // read file
    std::ifstream myfile("/home/shreya/Desktop/Workspace/Assignment_2/maze.txt"); //customize this
    // reads from top so origin at top left corner
    // create a vector to store the elements of the file
    std::vector<std::string> maze;
    std::string file_line;
    if(myfile.is_open()){
        //read each line of the text file
        while (std::getline(myfile, file_line)) {
            // save each line as a row in the vector
            maze.push_back(file_line);
            rows +=1;
        }
        myfile.close();
        columns = maze.at(0).size();
    }
    else{
        std::cout<<"Unable to open file";
    }
    
    
    int start_x, start_y;
    int goal_x,goal_y;
    std::cout<<"Enter starting x and y coordinates: ";
    std::cin>>start_x>>start_y;
    std::cout<<"Enter goal x and y coordinates: ";
    std::cin>>goal_x>>goal_y;
    while (validate_points(start_x,start_y,maze)==0){
        std::cout<<"Enter new start points: ";
        std::cin>>start_x>>start_y;
    }
    maze[start_y][start_x]='S';
    while(validate_points(goal_x,goal_y,maze)==0){
        std::cout<<"Enter new goal points: "<<std::endl;
        std::cin>>goal_x>>goal_y;
    }
    maze[goal_y][goal_x]='G';
    //display the maze
    for(int r=0; r<rows; r++){
        for(int c=0;c<columns;c++){
            // each element can be accessed by accessing the row and then the corresponding column
            std::cout<<maze[r][c];
        }
           std::cout<<std::endl;
    }
}


bool validate_points(int x, int y, std::vector<std::string> maze){
    if(maze[y][x]=='#'){  //y-rows, x-columns
        std::cout<<"The point is on an obstacle."<<std::endl;
        return 0;
    }
    else if (x<0 || x>46 || y<0 || y>31){
        std::cout<<"The point is outside the maze."<<std::endl;
        return 0;
    }
    return 1;
}
