/**********************************************************************
 *  ps2-readme template                                                   
 *  Recursive Graphics (Pythagoras tree)                       
 **********************************************************************/

Your name: Kyle Savoie

Hours to complete assignment: 17.5

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
In this assignment I created a class call PTree which stored the side length of a square, the depth of recursion, and a vector of rectangle shape elements. From there, I created a function called drawPTree which, if ran before the first shape was created, will create the first shape and call an overloaded version of itself which will recurively fill the vector of rectangle shapes with squares of different size, transformation, and color. Once the vector is filled with the desired number of squares which is decided by the recursion depth, the main program will call the overloaded draw function to iterate through the vector of rectangle shapes, printing them to a window.

/**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
Algorithms:
	I had to brush up on my trig to figure out how to manipulate the squares. For the 45/45/90 triangle I was able to scale the size of the new shapes equally between left and right children, but when implementing the recursive algorithm for a 30/60/90 triangle I had to do some paper calculations to figure out that the left child was going to be scaled by sqrt(3)/2 and the right child would be scaled by half.

Data Structures:
	My class PTree used a vector of convex shapes to store the shapes generated from the recursive drawPTree function. Once all of the shaes were generated and stored, they were printed out by iterating through the vector.

/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
I added a feature where a music file will be opened and will play in the background until the window is closed.

 /**********************************************************************
 *  Briefly explain what you learned in the assignment.
 **********************************************************************/
In this assignment I learned how to use recursion in an efficient and elegant way. Before this, I had always avoided it. I also learned how to approach a project that takes a large amount of math and equations and break down what I found in a way that could be easily implemented into a program. Not to mention, I learned how to use the transformable class in SFML for object manipulation.

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
N/A


/**********************************************************************
 *  Describe any serious problems you encountered.  
 *  If you didn't complete any part of any assignment, 
 *  the things that you didn't do, or didn't get working.                  
 **********************************************************************/
I had some troubles getting the window to fit after I changed the angle of the tree. I struggled to find a way to resize the window elegantly, without forcing the size to just be "larger".


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

