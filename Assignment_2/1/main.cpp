#include <iostream>
#include <fstream>
#include <string>
#include <vector>
 
bool validate_points(int x, int y, std::vector<std::string> maze);
// takes in a point and the maze and checks if the point is in free space in the maze


int main(){
    int rows = 31;
    int columns = 46;
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
        }
        myfile.close();
    }
    else{
        std::cout<<"Unable to open file";
    }
    //display the maze
    for(int r=0; r<rows; r++){
        for(int c=0;c<columns;c++){
            // each element can be accessed by accessing the row and then the corresponding column
            std::cout<<maze[r][c];
        }
           std::cout<<std::endl;
    }
    
    int start_x, start_y;
    int goal_x,goal_y;
    std::cout<<"Enter starting x and y coordinates: ";
    std::cin>>start_x>>start_y;
    std::cout<<"Enter goal x and y coordinates: ";
    std::cin>>goal_x>>goal_y;
    validate_points(start_x,start_y,maze);
    validate_points(goal_x,goal_y,maze);
}


bool validate_points(int x, int y, std::vector<std::string> maze){
    if(maze[x][y]=='#'){
        std::cout<<"The point is on an obstacle.";
        return 0;
    }
    else if (x<0 || x>31 || y<0 || y>46){
        std::cout<<"The point is outside the maze.";
        return 0;
    }
    return 1;
}
