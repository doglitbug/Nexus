#include "gameEngine.h"

gameEngine::gameEngine(board *pBoard, SDLLib *pSDLLib){
	mBoard=pBoard;
	mSDLLib=pSDLLib;
}

gameEngine::~gameEngine(){
	mBoard=NULL;
	mSDLLib=NULL;
}

void gameEngine::drawBoard(){
	for (int y=0;y<BOARD_SIZE;y++){
		for (int x=0;x<BOARD_SIZE;x++){
			mSDLLib->drawBall(x,y,mBoard->getCell(x,y));
		}
	}
}

