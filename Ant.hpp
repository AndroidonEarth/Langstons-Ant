/*********************************************************************
** Program name: Langston's Ant
** Author: Andrew Swaim
** Date: Janurary 16, 2018
** Description: Ant.hpp, specification file for the Ant class.
*********************************************************************/


#ifndef ANT_HPP
#define ANT_HPP

/**
* Enum to hold the two possible color states of each space.
*/
enum Colors { WHITE, BLACK };

/**
* Enum to hold the four possible states of the orientation of the ant.
*/
enum Card { UP, DOWN, LEFT, RIGHT };


/**
* Simple structure to store the column number and row number of
* the ant's location, stored in terms of the subscript of the 2D array.
*/
struct Coord {
	int antCol;
	int antRow; 
};

/**
* Simple structure to store information about the board. Contains a dynamic
* 2D array to store the information about the color state of each space on 
* the board, as well as two ints to store the max column and row subscript.
*/
struct Board {
	Colors** ary;
	int maxCol;
	int maxRow;
};

class Ant {

private:
	// Data member variables.
	Board board;
	Coord location;
	Card orientation;

	// Helper functions.
	void allocAndFillBoard(int pNumOfRows, int pNumOfCols);
	void deallocBoard();
	void setRandLocation(int pNumOfRows, int pNumOfCols);
	void rotateRight();
	void rotateLeft();
	void setSpaceToColor(Colors color);

public:
	// Primary methods.
	Ant(int pNumOfRows, int pNumOfCols);
	Ant(int pNumOfRows, int pNumOfCols, int pStartRow, int pStartCol);
	~Ant();
	void moveAnt();
	void rotateAndChangeColor();
	void printBoard();
};

#endif

