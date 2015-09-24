#include "board.h"
#include <string.h>

board::board(){
	resetBoard();
}

void board::resetBoard(){
	memset(mBoard,0,sizeof(mBoard));
}

int board::getCell(int pX, int pY){
	//Check bounds of pX and pY and return -1 if outside of the board
	if (pX<0 || pX>BOARD_SIZE || pY<0 || pY>BOARD_SIZE){
		return -1;
	} else {
		return mBoard[pX][pY];
	}
}

void board::setCell(int pX, int pY, int ball){
	if (pX<0 || pX>BOARD_SIZE || pY<0 || pY>BOARD_SIZE){
		//TODO out of bounds
	} else {
		mBoard[pX][pY]=ball;
	}
}

void board::addBalls(){
	//TODO: finish
	mBoard[0][0]=2;
	mBoard[1][1]=4;
	mBoard[2][2]=6;
}