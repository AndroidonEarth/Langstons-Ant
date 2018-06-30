/*********************************************************************
** Program name: Langston's Ant
** Author: Andrew Swaim
** Date: Janurary 16, 2018
** Description: Ant.cpp, implementation file for the Ant class.
*********************************************************************/

#include "Ant.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::endl;

/**
* Overloaded constructor for the Ant class.
* Is used when the user specifies to use a randomly generated
* starting location for the ant.
*/
Ant::Ant(int pNumOfRows, int pNumOfCols) {

	// Allocate memory for the 2D array and fill the board.
	allocAndFillBoard(pNumOfRows, pNumOfCols);
	// No starting location specified so set random location.
	setRandLocation(pNumOfRows, pNumOfCols);
	// Row numbers are adjusted by 1 for use internally as subscripts.
	board.maxRow = pNumOfRows - 1;
	board.maxCol = pNumOfCols - 1;
	orientation = UP;	// Default orientation.
}

/**
* Second overloaded constructor for the Ant class.
* Is used when the user wants to specifically choose the starting
* location of the ant.
*/
Ant::Ant(int pNumOfRows, int pNumOfCols, int pStartRow, int pStartCol) {

	// Allocate memory for the 2D array and fill the board.
	allocAndFillBoard(pNumOfRows, pNumOfCols);
	// Row numbers are adjusted by 1 for use internally as subscripts.
	location.antRow = pStartRow - 1;
	location.antCol = pStartCol - 1;
	board.maxRow = pNumOfRows - 1;
	board.maxCol = pNumOfCols - 1;
	orientation = UP;	// Default orientation.
}

/**
* Destructor for the Ant class.
* Deallocates memory for the board member variable before 
* destroying the class object.
*/
Ant::~Ant() {

	// Deallocate the memory for the board when the
	// the ant object is destroyed.
	deallocBoard();
}

/**
* Private helper function to allocate memory for the 2D array
* and fill every space in the array with WHITE. This function is called
* in the constructor when the Ant object is first created.
*/
void Ant::allocAndFillBoard(int pNumOfRows, int pNumOfCols) {

	// Allocate the memory for the rows.
	board.ary = new Colors*[pNumOfRows];
	for (int i = 0; i < pNumOfRows; ++i) {

		// Allocate the memory for the columns.
		board.ary[i] = new Colors[pNumOfCols];

		for (int j = 0; j < pNumOfCols; j++) {

			// Fill every space white.
			board.ary[i][j] = WHITE;
		}
	}
}

/**
* Private helper function to deallocate memory for the 2D array.
* This function is called in the destructor when the ant object 
* is destroyed.
*/
void Ant::deallocBoard() {

	for (int i = 0; i <= board.maxRow; i++) {

		// Deallocate the memory for the columns.
		delete[] board.ary[i];
	}
	// Deallocate the memory for the rows.
	delete[] board.ary;
}

/**
* Private helper function to assign random values to the column and row
* location of the ant between 0 and the max row. This function is
* called in the constructor that is used when the user specifies
* using a random starting location. The inputted number of rows and
* columns for the board are passed as arguments to this function to
* generate the random location.
*/
void Ant::setRandLocation(int pNumOfRows, int pNumOfCols) {

	// Setup seed and srand for use with rand().
	unsigned seed = time(0);
	srand(seed);

	// Number of columns/rows can be up to 120,
	// so the location will be between subscript 0 and 119.
	location.antCol = rand() % pNumOfCols;
	location.antRow = rand() % pNumOfRows;
}

/**
* Private helper function to assign a color enum to the space of the
* current location of the ant. This function exists mainly to increase
* code readability. Is passed a Colors parameter to assign to the space.
*/
void Ant::setSpaceToColor(Colors color) {

	board.ary[location.antRow][location.antCol] = color;
}

/**
* One of the primary public methods of the Ant class and is step 2 of
* the rules of Langston's Ant. First gets the color of the current space
* of the ant, then applies the rule to determine which way to rotate
* and flips the color of the space to the opposite color.
*/
void Ant::rotateAndChangeColor() {

	// Get the color of the current space.
	Colors currentSpaceColor = board.ary[location.antRow][location.antCol];

	// RULES OF LANGSTON'S ANT.
	// If the current space is white
	if (currentSpaceColor == WHITE) {

		// Turn right 90 degrees and change the color.
		rotateRight();
		setSpaceToColor(BLACK);
	}
	// If the current space is black
	else if (currentSpaceColor == BLACK) {

		// Turn left 90 degrees and change the color.
		rotateLeft();
		setSpaceToColor(WHITE);
	}
}

/**
* One of the primary public methods of the Ant class and is step 1 of
* the rules of Langston's Ant. Uses a switch statement to determine the
* orientation of the ant and then moves the ant one space in that direction.
* if the ant is at, and is facing, a border, the function will instead wrap
* the ant's location to the opposite side of the board.
*/
void Ant::moveAnt() {

	switch (orientation) {

	case RIGHT:
		// If the ant is facing right and is at the right border
		if (location.antCol == board.maxCol) {

			// wrap the ant's location around to the left border.
			location.antCol = 0;
		}
		// Otherwise move the ant one space to the right.
		else {
			location.antCol++;
		}
		break;
	case UP:
		// If the ant is facing up and is at the top border
		if (location.antRow == 0) {

			// wrap the ant's location around to the bottom border.
			location.antRow = board.maxRow;
		}
		// Otherwise move the ant one space up.
		else {
			location.antRow--;
		}
		break;
	case LEFT:
		// If the ant is facing left and is at the left border
		if (location.antCol == 0) {

			// wrap the ant's location around to the right border.
			location.antCol = board.maxCol;
		}
		// Otherwise move the ant one space to the left.
		else {
			location.antCol--;
		}
		break;
	case DOWN:
		// If the ant is facing down and is at the bottom border
		if (location.antRow == board.maxRow) {

			// wrap the ant's location around to the top border.
			location.antRow = 0;
		}
		// Otherwise move the ant one space down.
		else {
			location.antRow++;
		}
		break;
	default:
		// ERROR HANDLING:
		cout << "ERROR: Orientation unknown, cannot move ant." << endl;
		break;
	}
}

/**
* Private helper function to rotate the ant. Uses a switch statement to determine
* the orientation of the ant and then changes the value of the orientation to 
* the corresponding enum value, to simulate a rotation of 90 degrees in that direction.
*/
void Ant::rotateRight() {

	switch (orientation) {

	case RIGHT:
		// If facing right, change to face down.
		orientation = DOWN;
		break;
	case DOWN:
		// If facing down, change to face left.
		orientation = LEFT;
		break;
	case LEFT:
		// If facing left, change to face up.
		orientation = UP;
		break;
	case UP:
		// If facing up, change to face right.
		orientation = RIGHT;
		break;
	default:
		// ERROR HANDLING:
		cout << "ERROR: Orientation unknown, cannot rotate right." << endl;
	}
}

/**
* Private helper function to rotate the ant. Uses a switch statement to determine
* the orientation of the ant and then changes the value of the orientation to
* the corresponding enum value, to simulate a rotation of 90 degrees in that direction.
*/
void Ant::rotateLeft() {

	switch (orientation) {
		
	case RIGHT:
		// If facing right, change to face up.
		orientation = UP;
		break;
	case UP:
		// If facing up, change to face left.
		orientation = LEFT;
		break;
	case LEFT:
		// If facing left, change to face down.
		orientation = DOWN;
		break;
	case DOWN:
		// If facing down, change to face right.
		orientation = RIGHT;
		break;
	default:
		// ERROR HANDLING:
		cout << "ERROR: Orientation unknown, cannot rotate left." << endl;
		break;
	}
}

/**
* Primary public method of the Ant class. Prints a visualization of the board,
* as well as certain key information about the current information of the board
* to the screen.
*/
void Ant::printBoard() {

	// To hold the color of each space.
	Colors color;

	// Print the top border of the board, with two extra "-"
	// for the border columns.
	for (int i = 0; i <= (board.maxCol + 2); i++) {
		cout << "-";
	}
	// Wrap the next row.
	cout << endl;

	for (int i = 0; i <= board.maxRow; i++) {

		// Print the left border.
		cout << "|";

		for (int j = 0; j <= board.maxCol; j++) {

			// Check if the current square is occupied by
			// the ant, and if so simply print the ant.
			if (i == location.antRow && j == location.antCol) {
				cout << "*";
			} 
			// Otherwise, print the corresponding symbol of the space.
			else {
				// Get the color of the current square.
				color = board.ary[i][j];

				// Print the corresponding symbol depending on the color.
				if (color == WHITE) {
					cout << " ";
				}
				else if (color == BLACK) {
					cout << "#";
				}
			}
		}

		// Print the right border.
		cout << "|" << endl;
	}

	// Print the bottom border, with two extra "-" for the border columns.
	for (int i = 0; i <= (board.maxCol + 2); i++) {
		cout << "-";
	}
	// Wrap to the next row.
	cout << endl;

	// Print the board information.
	cout << "Board size: " << (board.maxCol + 1) << " cols x "
		<< (board.maxRow + 1) << " rows\n"
		<< "Ant location: col " << (location.antCol + 1) << ", row "
		<< (location.antRow + 1) << "\n"
		<< "Ant orientation: ";

	// finish the printing of the board info with the current orientation.
	switch (orientation)
	{
	case RIGHT:
		cout << "right\n";
		break;
	case UP:
		cout << "up\n";
		break;
	case LEFT:
		cout << "left\n";
		break;
	case DOWN:
		cout << "down\n";
		break;
	default:
		// ERROR HANDLING.
		cout << "ERROR: Orientation unknown, can't print orientation info.\n";
		break;
	}
}