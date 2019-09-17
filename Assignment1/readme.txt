ENPM 809Y: Introductory to Robot Programming 
Assignment 1: Arrays and Vectors
Group 11

Project Statement: To prompt the user to enter the the color of the missing peg in each row of the tray, insert the color in the right position to complete the given array and then display it on the console such that it matches the tray in the image. 

Files:
There is one file for this project:
	group11-rwa1.zip 
To run the file, extract and open the workspace in any C++ IDE and run the main.cpp file.

Implementation: 
We use the concepts of arrays and vectors to complete this project following the steps mentioned hereafter: 

Step 1: We initialize a 2D array (string type) with 3 rows and 2 columns in the following manner:
First row: blue, white
Second row: green, white
Third row: green, white

Step 2: Create row vectors to hold the contents of each row of the previously created 2D array

Step 3: Prompt the user to enter the colors of each of the three missing pegs from the tray

Step 4: Insert user entered missing peg colors into each of the row vectors at the appropriate place in the vector

Step 5: Display the contents of each of the row vectors to the terminal

Step 6: Build a 2D vector (3x3) from each of the previously defined row vectors representing the correct peg pattern in the tray

Step 7: Calculate and display the size of the 2D vector

Step 8: Print each element of the 2D vector to the console

The program has two helper functions:

load_color_vecs(): This function takes an array of two elements and stores it into a vector. 

print_2d_vector(): This function takes a 2D vector and prints each of the elements.  
