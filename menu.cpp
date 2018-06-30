/*********************************************************************
** Program name: Langston's Ant
** Author: Andrew Swaim
** Date: Janurary 16, 2018
** Description: menu.cpp, implementation file the menu functions.
*********************************************************************/

#include "menu.hpp"
#include <iostream>
using std::cout;

/**
* Display the intro to the program. This is used when the program first
* starts to give an introduction and description of the program. 
*/
void displayIntro() {

	cout << "\n\nWELCOME!\n\n"
		<< "This program will simulate the "
		<< "Langston's Ant Turing Machine.";
}

/**
* Display the first menu prompt. This is used at the start of the program
* after the introduction in order to prompt the user for their first selection.
*/
void displayMenu1() {

	cout << "\n\nMENU\n\n"
		<< "1) Start Langston's Ant simulation\n"
		<< "2) Quit\n\n";
}

/**
* Display the second menu prompt. This is used after a step in the simulation
* has been executed in order to give the user options to continue or end 
* the simulation.
*/
void displayMenu2() {

	cout << "\n\nMENU\n"
		<< "1) Next step\n"
		<< "2) Execute all steps (CAUTION: may take awhile for large number of steps)\n"
		<< "3) Cancel simulation\n\n";
}

/**
* Display the third menu prompt. This is used after the simulation has ended to
* give the user the option to run the simulation again or end the program.
*/
void displayMenu3() {

	cout << "\n\nMENU\n\n"
		<< "1) Play again\n"
		<< "2) Quit\n\n";
}

/**
* Display the outro to the program. This is used when the program is about to end
* to indicate so to the user.
*/
void displayOutro() {

	cout << "\nProgram is ending."
		<< "\n\nTHANK YOU!\n\n";
}