ENPM 809Y: Introduction to Robot Programming
Assignment 2: Recursive Function
Group 11


*Project Statement: 

To navigate a robot through a maze from a start point to a goal point. 


*Files: 

There is one file for this project:
	
	-group11-rwa2.zip


*User inputs:


	-The start point and goal point can be given as: x_coordinate y_coordinate. (Ex: start point: 29 1, goal point: 32 13)



*To run the file:

	-Step 1: Extract and open the workspace in any IDE, then build and run the main.cpp file. 
		~The zip file also contains a maze.txt file, make sure to that it is stored in the workspace for the code to run. Otherwise. specify the location address in the code.

	-Step 2: Enter starting coordinates (e.g. start_x start_y)
		~If user enter something other than an integer, the program will reprompt step 2.

	-Step 3: Enter goal coordinates (e.g. goal_x goal_y)
		~If user enter something other than an integer, the program will reprompt step 3.

	-Step 4: If the choosen coordinates fall at an empty space and inside the maze, the program will output graphycally the solution path.
		~If the choosem coordinates fall at an wall or outside the maze, the program will output out of range error



*Implementation:


	-The algorithm makes use of a recursive function to move the robot from one node to the next. It first checks north, then east, south and finally west. 


*The program has four helper functions:


	-The main function for this program calls ReadTextFile(), GetCoordinates(), FindPath(), and DisplayMaze() in order to accomplish the project objective:

	
		1. ReadTextFile(): This function takes the maze.txt file, reads it and stores its content into a vector.  
	
	
		2. GetCoordinates(): This function takes user input for the start and goal points and stores it into a vector. The function also makes sure that the given inputs are within the free space in the maze and are integers. 

	
		3. FindPath(): This is a recursive function called by main to find an unobstructed path from the starting position to the goal position. The function takes points as its input and checks to see if the robot can move north, east, south or west respectively. It also ensures that the point is within the maze. The function stops when the point is equal to the goal point.

		4. DisplayMaze(): This function displays the entire maze.
