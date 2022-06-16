/**********************************************************************
 *  Linear Feedback Shift Register (part B) ps1b-readme.txt template
 **********************************************************************/

Name: Kyle Savoie
OS: Ubuntu 18.04.3 LTS
Machine (e.g., Dell Latitude, MacBook Pro): Lab Computer
Text editor: Vi
Hours to complete assignment: 7
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
In this assignment I had to create a program called PhotoMagic.cpp that 
can encrypt and decrypt pictures. To do this I had to implement a transsform
function and a main function. In the transform function, I passed in an
image and a seed. I then pulled colors from each pixel in the picture
and XORed the rgb values, reinserting the pixels into an output file.
In my main program I created textures, sprites, and windows for both
of the images.

/**********************************************************************
 *  If you did any implementation for extra credit, describe it
 *  here and why it is interesting.
 **********************************************************************/




/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
I spoke with a grader in the lab who helped me to identify my errors


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
I encountered a problem with my FibLFSR implementation because of it's
lack of efficiency. I had to re-write the constructor to use shorts,
remove the creation of a temp string from the step function, and change
the functionality of my generate function.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

