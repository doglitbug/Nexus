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



	//TODO: finish
	//TODO: return -1 if unsuccessful???
	mBoard[0][0]=2;
	mBoard[1][1]=4;
	mBoard[2][2]=6;

	
}

/// <summary>
/// Checks a given point is with in bounds for the board
/// </summary>
/// <param name="location">location to check</param>
/// <returns>true within bounds/false otherwise</returns>
bool board::checkBounds(point location){
	 if (location.x<0 || location.x>BOARD_SIZE || location.y<0 || location.y>BOARD_SIZE){
		 return false;
	 } else {
		 return true;
	 }
}