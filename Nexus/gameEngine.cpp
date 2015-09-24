#include "gameEngine.h"

gameEngine::gameEngine(board *pBoard, SDLLib *pSDLLib){
	mBoard=pBoard;
	mSDLLib=pSDLLib;
}

gameEngine::~gameEngine(){
	mBoard=NULL;
	mSDLLib=NULL;
}

/// <summary>
/// Draw the game board
/// </summary>
void gameEngine::drawBoard(){
	for (int y=0;y<BOARD_SIZE;y++){
		for (int x=0;x<BOARD_SIZE;x++){
			point temp;
			temp.x=x;
			temp.y=y;
			mSDLLib->drawBall(temp,mBoard->getCell(temp));
		}
	}
}
