/*********************************************************************
** Program name: Langston's Ant
** Author: Andrew Swaim
** Date: Janurary 16, 2018
** Description: inputValidation.hpp, specification file for the
	inputValidation functions.
*********************************************************************/

#ifndef INPUTVALIDATION_HPP
#define INPUTVALIDATION_HPP

#include <string>
using std::string;

// Function declarations.
char getMenuChoice(char maxChoice);
int getValidIntInRange(int min, int max);
char getValidChar(string opt1, string opt2); 
char getFirstLetterUpper(string str);
char getFirstLetterLower(string str);

#endif
