/*********************************************************************
** Program name: Langston's Ant
** Author: Andrew Swaim
** Date: Janurary 16, 2018
** Description: main.cpp, driver for Project1. Uses the Ant class, 
	inputValidation functions, and the menu functions. NOTE: To
	replicate the "highway" phenomenon illustrated in the Langston's
	Ant wikipedia, select at least a 100 x 100 board with at least
	11000 moves, then after the first step is executed select 
	option 2 to execute every calculation step in the program and
	display the final result. For Windows, if your console screen is
	not large enough, right click the top of the window, click 
	properties, and under 'layout' increase the size of your window.
	THANK YOU!
*********************************************************************/

#include "Ant.hpp"
#include "inputValidation.hpp"
#include "menu.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {

	////////////////////////////////////////////////////////////////////
	// Variables.
	////////////////////////////////////////////////////////////////////

	// Constant variables.
	const int MAX_STEPS = 100000;
	const int MIN_STEPS = 1;
	const int MAX_ROWS_OR_COLUMNS = 120;
	const int MIN_ROWS_OR_COLUMNS = 5;

	// Langston's Ant simulation variables.
	int numOfRows = 0;
	int numOfCols = 0;
	int numOfSteps = 0;
	int startRow = 0;
	int startCol = 0;
	Ant *ant = NULL;

	// User choice input variable.
	char charChoice = ' ';

	////////////////////////////////////////////////////////////////////
	// Program begins.
	////////////////////////////////////////////////////////////////////

	// Display the intro and first menu choice.
	displayIntro();
	cout << "\n\n\n!!! I'VE INCLUDED THE EXTRA CREDIT !!!\n";
	displayMenu1();

	// Get menu choice. charChoice == '2' means user selected to quit instead.
	charChoice = getMenuChoice('2');

	// Start program, beginning with getting starting info.
	while (charChoice != '2') {

		////////////////////////////////////////////////////////////////////
		// Get starting info.
		////////////////////////////////////////////////////////////////////

		// Get rows.
		cout << "\nEnter a number of rows for the board between 5 and 120\n\n";
		numOfRows = getValidIntInRange(MIN_ROWS_OR_COLUMNS, MAX_ROWS_OR_COLUMNS);

		// Get columns.
		cout << "\nEnter a number of columns for the board between 5 and 120\n\n";
		numOfCols = getValidIntInRange(MIN_ROWS_OR_COLUMNS, MAX_ROWS_OR_COLUMNS);

		// Get steps.
		cout << "\nEnter a number of steps you would like to run\n"
			<< "the program for between 1 and 100000\n\n";
		numOfSteps = getValidIntInRange(MIN_STEPS, MAX_STEPS);

		// Prompt for random starting location.
		cout << "\nDo you want to randomize the ant's starting location?\n"
			<< "Enter y or Y for YES, or enter n or N for NO.\n\n";
		charChoice = getValidChar("yes", "no");

		// If the user specifies random starting location
		if (charChoice == 'y' || charChoice == 'Y') {

			// Create the ant object using constructor that randomizes location.
			ant = new Ant(numOfRows, numOfCols);
		}
		// Otherwise, prompt further for starting location.
		else if (charChoice == 'n' || charChoice == 'N') {

			// Get starting row between the min and user specified max.
			cout << "\nEnter the starting row for the ant.\n\n";
			startRow = getValidIntInRange(MIN_ROWS_OR_COLUMNS, numOfRows);

			// Get starting column between the min and user specified max.
			cout << "\nEnter the starting column for the ant.\n\n";
			startCol = getValidIntInRange(MIN_ROWS_OR_COLUMNS, numOfCols);

			// Create the ant object with constructor that specifies location.
			ant = new Ant(numOfRows, numOfCols, startRow, startCol);
		}

		////////////////////////////////////////////////////////////////////
		// Print the starting board and number of steps.
		////////////////////////////////////////////////////////////////////

		cout << "\n\n";
		ant->printBoard();
		cout << "\n\nThis is the starting board.\n"
			<< "Press enter to begin with " << numOfSteps << " steps.\n\n";
		cin.get();

		////////////////////////////////////////////////////////////////////
		// Begin simulation.
		////////////////////////////////////////////////////////////////////

		do {

			// Move the ant in the direction of orientation.
			ant->moveAnt();

			// Apply the Langston's Ant rule based on the new space.
			ant->rotateAndChangeColor();

			// Decrement number of steps remaining.
			numOfSteps--;
			
			// Print the new board and remaining steps.
			ant->printBoard();
			cout << "\nNumber of steps remaining is " << numOfSteps << ".\n\n";

			////////////////////////////////////////////////////////////////////
			// Evaluate results and determine next step.
			////////////////////////////////////////////////////////////////////

			// If number of steps reached 0 normally, 
			// hang here before exiting while loop.
			if (numOfSteps == 0) {

				cout << "\nNo more steps! Press enter to continue.\n";
				cin.get();
			}

			// If there are still steps remaining, give the user the option
			// to stop and terminate the simulation early or continue.
			if (numOfSteps > 0) {

				displayMenu2();
				charChoice = getMenuChoice('3');

				// If the user decides execute every step immediately.
				if (charChoice == '2') {
					
					cout << "\nRunning simulation, please wait...\n\n";

					// Finish the simulation and print the final board.
					for (int i = numOfSteps; i > 0; i--) {
						ant->moveAnt();
						ant->rotateAndChangeColor();
					}
					ant->printBoard();
					
					// Set num of steps to 0 to end the while loop.
					numOfSteps = 0;
					cout << "\n\nSimulation complete. This is the final board\n"
						<< "Press enter to continue.\n";
					cin.get();
				}
				// If the user decides to end the program early.
				else if (charChoice == '3') {

					// Set num of steps to 0 to end the while loop.
					numOfSteps = 0;
					cout << "\nSimulation canceled. Press enter to continue.\n";
					cin.get();
				}
			}

			// ERROR HANDLING:
			else if (numOfSteps < 0) {

				cout << "ERROR: Something went wrong, number of steps is "
					<< "less than 0.\nEnding program, press enter continue...";
				cin.get();
				return 0;
			}

		} while (numOfSteps > 0);

		////////////////////////////////////////////////////////////////////
		// Simulation ended.
		////////////////////////////////////////////////////////////////////

		// Deallocate dynamic memory.
		delete ant;

		// Indicate program has finished and offer display second menu.
		cout << "\nProgram has finished.\n";
		displayMenu3();
		// Get user choice. If '2' (quit) is selected loop will be exited
		// and program will end.
		charChoice = getMenuChoice('2');
	}

	////////////////////////////////////////////////////////////////////
	// Program ending.
	////////////////////////////////////////////////////////////////////

	displayOutro();
	getchar();

	return 0;
}