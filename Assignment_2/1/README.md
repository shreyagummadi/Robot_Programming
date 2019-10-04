# ENPM809Y_Group11


This source code provides a framework to find the correct path to complete the maze

It is currently hosted on GitHub at https://https://github.com/sully892/Cu_Ag_Au/tree/master/Assignment_2

Overview
========

![Overview of Project Modules](/Diagrams/overview.png?raw=true)


It is composed of the following modules each with its own directory and .JInternalFrame.

 * A robot is asked to navigate a maze. It starts at a specific position in the maze (the starting position)
and is asked to try to reach another position in the maze (the goal position).

 * Positions in the maze will either be open or blocked with an obstacle.
 * Positions are identified by (x, y) coordinates.


Rules for the Robot
-----

 * At any given moment, the robot can only move 1 step in one of 4 directions.
 * Valid moves are:
 	– Go North
	– Go East
	– Go South
	– Go West
 * The robot can only move to positions without obstacles and must stay within the maze.
 * The robot should search for a path from the start position to the goal position (a solution path) until it finds one or until it exhausts all possibilities.
 * In addition, it should mark the path it finds (if any) in the maze.

![Supervisor of two systems](/Diagrams/supervisor_over_fanuc_motoman.png?raw=true)



Definition of Maze
-----


![The Maze](/Assignment_2/1/Documentation/TheMaze.png?raw=true)

The maze used in the assignment has a predefined size and a predefined design. The maze is represented by a matrix of characters, as depicted below, and can be found in the text file
(maze.txt).



Representation
-----


1.  Coordinates for the maze are represented in the Cartesian coordinate system.
	– The character S is positioned at (29, 1).
	– The character G is positioned at (32, 13).
2.  The ASCII character # represents a wall (forbidden position for the robot).
3.  Empty characters represent a position where the robot can be.
4. The character S is the start position of the robot.
5. The character G is the goal position the robot must reach (if a valid path is available).
6. A solution or partial path in the maze can be marked by the + symbol.

Algorithm
-----
This problem must be solved (finding and marking a solution) with recursion.
Remember that a recursive algorithm has at least two parts:
 * Base case(s) that determine when to stop.
 * Recursive part that calls the same function (i.e., itself) to assist in solving the problem.

        • From the start position S, move in one of the four directions (North, East,South, West).
        • From the new position, move into one of the four directions.
        • Repeat this behavior until one of the base cases is reached.
        • The prototype of the recursive function is: bool FindPath(int x, int y);
        • To find a path from the start position S(x = 29, y = 1) to the goal position G(x = 32, y = 13), we can just ask FindPath to try to find a path from the North, East, South, and West (in this order) of (x = 29, y = 1):
            1. FindPath(x1,y1);//--(x1,y1):north coordinates of (x,y)
            2. FindPath(x2,y2);//--(x2,y2):east coordinates of (x,y)
            3. FindPath(x3,y3);//--(x3,y3):south coordinates of (x,y)
            4. FindPath(x4,y4);//--(x4,y4):west coordinates of (x,y)
            

Base Case
-----
 * It is not enough to know how to use FindPath recursively to advance through
the maze.
 * We also need to determine when FindPath must stop.
 * The algorithm stops when any of the following conditions is encountered:
	– The algorithm stops when the goal is reached.
	– FindPath returns false if the computed position is outside the boundaries of the maze.
	– FindPath returns false if the computed position is an obstacle.

	src/main/java/aprs/framework/logdisplay/  






















