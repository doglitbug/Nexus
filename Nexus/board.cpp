#include "board.h"
#include <string.h>

board::board(){
	resetBoard();
}

void board::resetBoard(){
	memset(mBoard,0,sizeof(mBoard[0][0]*BOARD_SIZE*BOARD_SIZE));
}

int board::getCell(int pX, int pY){
	//TODO: Check bounds of pX and pY?
	if (pX<0 || pX>BOARD_SIZE || pY<0 || pY>BOARD_SIZE){
		return -1;
	} else {
		return mBoard[pX][pY];
	}
}