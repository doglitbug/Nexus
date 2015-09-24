#include "gameEngine.h"

gameEngine::gameEngine(board *pBoard, SDLLib *pSDLLib){
	mBoard=pBoard;
	mSDLLib=pSDLLib;
	selected=false;
	selectedFlash=true;

	selectedLocation=point(1,1);
	unsigned long mTime1 = SDL_GetTicks();
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

	//Check for selected

	//Check timer
	unsigned long mTime2 = SDL_GetTicks();
	if ((mTime2-mTime1)>400){		
		//Reset timer
		mTime1=SDL_GetTicks();
		selectedFlash=!selectedFlash;
	}

	//Draw selected if need be
	if (selected && selectedFlash){
		mSDLLib->drawBall(selectedLocation,NUMBER_BALLS+1);
	}
}

/// <summary>
/// Deal with game input
/// </summary>
void gameEngine::input(){
	//TODO: integrate keyboard as well?
	point mouse=mSDLLib->getMouseClick();
	point grid;
	//Check a click happened
	if (mouse.x!=NULL){
		//Check click was on the board
		if (mouse.x<BOARD_SIZE*BALL_SIZE && mouse.y<BOARD_SIZE*BALL_SIZE){
			grid.x=mouse.x/BALL_SIZE;
			grid.y=mouse.y/BALL_SIZE;

			printf("Board click\n");
			printf("X: %d Y %d\n",grid.x,grid.y);
			mBoard->addBalls();
			selected=true;
			selectedLocation=grid;
		} else {
			printf("X: %d Y %d\n",mouse.x,mouse.y);
		}
	}
}

void gameEngine::doMouseClick(point location){
	
}