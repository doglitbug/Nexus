#include "gameEngine.h"

gameEngine::gameEngine(board *pBoard, SDLLib *pSDLLib){
	mBoard=pBoard;
	mSDLLib=pSDLLib;
	selected=false;
	selectedFlash=true;

	source=point(1,1);
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
		mSDLLib->drawBall(source,NUMBER_BALLS+1);
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

			doMouseClick(grid);

		} else {
			printf("X: %d Y %d\n",mouse.x,mouse.y);
		}
	}
}
/// <summary>
/// Deal with a mouse click on the moard
/// </summary>
/// <param name="location">Location that was clicked</param>
void gameEngine::doMouseClick(point target){
	printf("Board click\n");
	printf("X: %d Y %d\n",target.x,target.y);

	//Check nothing is already selected
	if (!selected){
		//If there is a ball, make it the selected one
		if (mBoard->getCell(target)!=0){
			selected=true;
			source=target;
		}
		//else if we are selected and click on an empty spot
	} else if (mBoard->getCell(target)==0){
		//TODO check pathfinding and actually move ball
		printf("Move from (%d,%d) to (%d,%d)\n",source.x,source.y,target.x,target.y);
		//Move source to target
		mBoard->setCell(target,mBoard->getCell(source));
		//Clear source
		mBoard->setCell(source,0);
		//Set flag as we are no longer on a selected ball
		selected=false;
		mBoard->addBalls();
	} else {
		//Change currently selected ball
		source=target;
	}
}