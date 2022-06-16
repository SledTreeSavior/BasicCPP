/**********************************************************************
 *  Linear Feedback Shift Register (part A) ps1a-readme.txt template
 **********************************************************************/

Name: Kyle Savoie
Hours to complete assignment: 2
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
In this assignment I was tasked with creating a Linear Feedback Shift Register which would be used to shift the bits of an input string a specified number of times. To do so, I implemented two functions, step and generate. The step function created a temporary string which was filled with the shifted bits from the previous instantiation and the result of the XOR. This prepared the input for the next step before returning the result of the XOR. The generate function keeps track of the value of the k bits that are obtained by simulating k steps of the LFSR and outputs it as an integer. This program lacked a main file because I used Boost Libraries to test the functions that I implemented. To compile, I created a Makefile.

To represent the register bits I created the temp string. The bits themselves were generated and temporarily stored in an int called XorResult. This was calculated by XOR-ing data[0] (the MSB) and data[2], data[3] and data[5] (the three tap bits). It is important to note that one cannot xor char data types, so in every calculation I made sure to add teh char '0' (+ '0'). I then used push_back() to put the xorResult bit on the end of the shifted register and set data equal to the temp string. I did this because I wanted to be able to manipulate a temp string and set data to the correctly changed string after the case.

/**********************************************************************
 *  If you did any implementation for extra credit, describe it
 *  here and why it is interesting.
 **********************************************************************/
N/A

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
Kevin Tran: We spoke about similar issues we had i.e. the test file being wrong.

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
I noticed that test.cpp had some incorrect information which I promtly changed.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
N/A


