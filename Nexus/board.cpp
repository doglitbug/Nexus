#include "board.h"
#include <string.h>

/// <summary>
/// Sets up the board for initial use
/// </summary>
board::board(){
	resetBoard();
}

/// <summary>
/// Resets the board for a new game
/// </summary>
void board::resetBoard(){
	memset(mBoard,0,sizeof(mBoard));
}

/// <summary>
/// Find contents of a given location
/// </summary>
/// <param name="location">Location on board</param>
/// <returns>Ball number</returns>
int board::getCell(point location){
	if (checkBounds(location)){
		return mBoard[location.x][location.y];
	} else {
		return -1;
	}
}

/// <summary>
/// Store a ball at the given location
/// </summary>
/// <param name="location">Location on board</param>
/// <param name="ball">Ball number</param>
void board::setCell(point location, int ball){
	if (checkBounds(location)){
		mBoard[location.x][location.y]=ball;
	}
}

/// <summary>
/// Add 3 radom balls the the board in random locations
/// </summary>
void board::addBalls(){
	//Create a vector of free spaces
	std::vector<point> freeSquares;

	for (int y=0;y<BOARD_SIZE;y++){
		for (int x=0;x<BOARD_SIZE;x++){
			if (mBoard[x][y]==0){
				freeSquares.push_back(point(x,y));
			}
		}
	}

	//Randomize the vector
	std::random_shuffle(freeSquares.begin(),freeSquares.end());

	//Add 3 balls or less if that is all the room that is left
	//TODO integer literal!
	int numberToAdd=(freeSquares.size()<3)?freeSquares.size():3;
	//Loop through and add a ball
	for (int i=0;i<numberToAdd;i++){
		//Get free location
		point location=freeSquares.at(i);
		//Get a random ball
		int ballNumber=rand()%(NUMBER_BALLS)+1;
		//Store on board
		setCell(location,ballNumber);
	}
}

/// <summary>
/// Checks a given point is with in bounds for the board
/// </summary>
/// <param name="location">location to check</param>
/// <returns>True within bounds/false otherwise</returns>
bool board::checkBounds(point location){
	 return !(location.x<0 || location.x>BOARD_SIZE || location.y<0 || location.y>BOARD_SIZE);
}