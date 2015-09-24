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
/// Find contents of a given cell 
/// </summary>
/// <param name="pX">Board X</param>
/// <param name="pY">Board Y</param>
/// <returns>Ball number</returns>
int board::getCell(int pX, int pY){
	//Check bounds of pX and pY and return -1 if outside of the board
	if (pX<0 || pX>BOARD_SIZE || pY<0 || pY>BOARD_SIZE){
		return -1;
	} else {
		return mBoard[pX][pY];
	}
}

/// <summary>
/// Store a ball at the given location
/// </summary>
/// <param name="pX">Board x</param>
/// <param name="pY">Board y</param>
/// <param name="ball">Ball number</param>
void board::setCell(int pX, int pY, int ball){
	if (pX<0 || pX>BOARD_SIZE || pY<0 || pY>BOARD_SIZE){
		//TODO out of bounds?
	} else {
		mBoard[pX][pY]=ball;
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