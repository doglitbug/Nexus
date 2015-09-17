#include "board.h"
#include <string.h>

board::board(){
	resetBoard();
}

void board::resetBoard(){
	memset(mBoard,0,sizeof(mBoard[0][0]*BOARD_SIZE*BOARD_SIZE));
}

int board::getCell(int pX, int pY){
	//Check bounds of pX and pY and retunr -1 if outside of the board
	if (pX<0 || pX>BOARD_SIZE || pY<0 || pY>BOARD_SIZE){
		return -1;
	} else {
		return mBoard[pX][pY];
	}
}

void board::setCell(int pX, int pY, int contents){
	if (pX<0 || pX>BOARD_SIZE || pY<0 || pY>BOARD_SIZE){
		//TODO out of bounds
	} else {
		mBoard[pX][pY]=contents;
	}
}