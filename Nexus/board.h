#ifndef _BOARD_
#define _BOARD_

#define BOARD_SIZE 9

#define NUMBER_BALLS 6

//Special images(non ball)
#define FREE 0
#define POSSIBLE 7
#define SELECTED 8

//Direction images
#define UP 10
#define RIGHT 11
#define DOWN 12
#define LEFT 13


#include "common.h"
#include <vector>
#include <algorithm>

class board
{
public:
	board();									//Constructor

	void resetBoard();							//Clears off the board for a new game
	int getCell(point location);				//Returns the contents of given cell
	void setCell(point location, int ball);		//Sets the contents of a cell
	void addBalls();							//Add 3 random balls to the board
	void findPossible(point source);			//Finds possible targets for source
	void clearPossible();						//Clears off possible targets when source is cleared

private:
	int mBoard[BOARD_SIZE][BOARD_SIZE];			//Contents of the board
	bool checkBounds(point location);			//Checks location is within bounds of the board
};
#endif