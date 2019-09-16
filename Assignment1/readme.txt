ENPM 809Y: Introductory to Robot Programming 
Assignment 1: Arrays and Vectors

Project Statement: To prompt the user to enter the the color of the missing peg in each row of the tray, insert the color in the right position to complete the given array and then display it on the console such that it matches the tray in the image. 

Files:
There is one file for this project:
	group11-rwa1.zip 
To run the file, extract and open the workspace in any IDE and run the main.cpp file.

Implementation: 
We use the concept of array and vectors to complete this project. 
Step 1: We initialize a 2D array (string type) with 3 rows and 2 columns in the following manner: 
First row: blue, white
Second row: green, white
Third row: green, white

Step 2: Prompt the user to enter the color of the missing peg from the tray

Step 4: Build a 2D vector (3x3) with all the elements collected from the above user input and predefined elements.

Step 3: Calculate and display the size of the new vector

Step 4: Display the new vector on the console

The program has two helper functions:

load_color_vecs(): This function takes an array of two elements and stores it into another array. 

print_2d_vector(): This function takes a 2D vector and prints the elements.  
