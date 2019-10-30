# ENPM809Y_Group11: Introduction to Robot Programming 
# Assignment 2: Recursive Function


Project Statement
========
This source code provides a framework to navigate a robot through a maze from a start point to a goal point. 


Files
========
 
There is one file for this project:
	group11-rwa2.zip

To run the file:
========

	-Step 1: Extract and open the workspace in any IDE, then build and run the main.cpp file. 
		~The zip file also contains a maze.txt file, make sure to that it is stored in the workspace for the code to run. Otherwise. specify the location address in the code.

	-Step 2: Enter starting coordinates (e.g. start_x start_y)
		~If user enter something other than an integer, the program will reprompt step 2.

	-Step 3: Enter goal coordinates (e.g. goal_x goal_y)
		~If user enter something other than an integer, the program will reprompt step 3.

	-Step 4: If the choosen coordinates fall at an empty space and inside the maze, the program will output graphycally the solution path.
		~If the choosem coordinates fall at an wall or outside the maze, the program will output out of range error


Overview
========


 * A robot is asked to navigate a maze. It starts at a specific position in the maze (the starting position)
and is asked to try to reach another position in the maze (the goal position).

 * Positions in the maze will either be open or blocked with an obstacle.
 * Positions are identified by (x, y) coordinates.



Rules for the Robot
-----

 * Robot can only move 1 step in one of the 4 directions.
 * Valid moves are:
 	– Move North
	– Move East
	– Move South
	– Move West
 * Robot can only move to positions without obstacles
 * Robot must stay within the maze
 * Robot should search for a path from the start position to the goal position, until it exhausts all possibilities.
 * Robot should mark the path it finds in the maze (if possible)




User Inputs
-----

The starting point and goal point can be given as: x_coordinate y_coordinate.
Ex: start point: 29 1   goal point: 32 13

Program Output
------

* If path is not found diplay "Path not found" and display partial path at the end
* If path is found diplay solution path at the end
* Re-promt user if invalid enter

Implementation
-----

The algorithm makes use of a recursive function to move the robot from one node to the next. It first checks north, then east, south and west. 




The program has four helper functions
-----

The main function for this program calls ReadTextFile(), GetCoordinates(), FindPath(), and DisplayMaze() in order to accomplish the project objective: 

1. ReadTextFile(): This function takes the maze.txt file, reads it and stores its content into a vector. 
	
2. GetCoordinates(): This function takes user input for the start and goal points and stores it into a vector. The function also makes sure that the given inputs are within the free space in the maze and are integers. 

3. FindPath(): This is a recursive function called by main to find an unobstructed path from the starting position to the goal position. The function takes points as its input and checks to see if the robot can move north, east, south or west respectively. It also ensures that the point is within the maze. The function stops when the point is equal to the goal point.

4. DisplayMaze(): This function displays the entire maze. 

 
	


Definition of Maze
-----


The maze used has a predefined size and a predefined design. The maze is represented by a matrix of characters, and can be found in the text file
(maze.txt).


![The Maze](/home/controls/ENPM809Y/Workspace/RWA-2/Assignment2/Documentation/TheMaze.png?raw=true)


Representation
-----


1.  Coordinates are represented in the Cartesian coordinate system.

	– The character S is Start positioned

	– The character G is the Goal positioned

2. The ASCII character # represents a wall
3. Empty characters represent an open position allow to the robot
4. A solution or partial path in the maze is marked by the "+" symbol.


Algorithm
-----
Problem solve use finding and marking a solution with recursion algorithm:


 * Base case(s) that determine when to stop.

		* Determine when FindPath must stop.
		* The recursive part of the algorithm stops when any of the following statement are made:
			– When the goal is reached.
			– FindPath returns false if the computed position is outside the boundaries of the maze.
			– FindPath returns false if the computed position is an obstacle.


 * Recursive part that calls the same function (i.e., itself) to help solving the problem.

        • From the start position S, move in one of the four directions (North, East,South, West).
        • From the new position, move into one of the four directions.
        • Repeat this behavior until one of the base cases is reached.
        • The prototype of the recursive function is: bool FindPath(int x, int y);
        • To find a path from the start position S(x = 29, y = 1) to the goal position G(x = 32, y = 13), we can just ask FindPath to try to find a path from the North, East, South, and West (in this order) of (x = 29, y = 1):
            1. FindPath(x1,y1);//--(x1,y1):north coordinates of (x,y)
            2. FindPath(x2,y2);//--(x2,y2):east coordinates of (x,y)
            3. FindPath(x3,y3);//--(x3,y3):south coordinates of (x,y)
            4. FindPath(x4,y4);//--(x4,y4):west coordinates of (x,y)
		• Backtracking
			– Provides the avility to go back to previous position when encounter a wall or when the robot goes out of bounce the maze. The way it work is by moving to one of the valid moves and check if the new location is a wall or out of reach. if that condition is made, the robot will go back to the previous posiion, and repeat the process.

























