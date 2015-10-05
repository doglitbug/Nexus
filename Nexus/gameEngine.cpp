#include "gameEngine.h"
#include <vector>
#include <algorithm>    // std::reverse

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

	//Check timer
	unsigned long mTime2 = SDL_GetTicks();
	if ((mTime2-mTime1)>400){		
		//Reset timer
		mTime1=SDL_GetTicks();
		selectedFlash=!selectedFlash;
	}

	//Draw selected if need be
	if (selected && selectedFlash){
		mSDLLib->drawBall(source,SELECTED);
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
/// Deal with a mouse click on the board
/// </summary>
/// <param name="location">Location that was clicked</param>
void gameEngine::doMouseClick(point target){
	printf("Board click\n");
	printf("X: %d Y %d\n",target.x,target.y);

	//Check nothing is already selected
	if (!selected){
		//If there is a ball, make it the selected one
		if (mBoard->getCell(target)!=FREE){
			selected=true;
			source=target;
			//Clear possible locations and find new ones
			mBoard->clearPossible();
			mBoard->findPossible(source);
		}
		//else if we are selected and click on an empty spot
	} else if (mBoard->getCell(target)>=POSSIBLE){

		std::vector<point> path=findPath(source, target);

		//Save the type of ball we are moving around
		int movementPiece=mBoard->getCell(source);
		//Travel the new path but drawing each step and erasing the previous one
		int numberSteps=path.size();
		//Start at second point as we erase the source one first loop
		for (int step=1;step<numberSteps;step++){
			//Erase previous step
			mSDLLib->drawBall(path[step-1],FREE);
			//Draw current step
			mSDLLib->drawBall(path[step],movementPiece);
			//Update the visuals
			mSDLLib->updateScreen();

			//Wait a bit
			SDL_Delay(200);
		}
		//Clean up
		path.clear();

		//Actually move the ball!
		mBoard->setCell(target,movementPiece);
		mBoard->setCell(source,FREE);

		//Set flag as we are no longer on a selected ball
		selected=false;
		//Clear possible locations and pathfinding
		mBoard->clearPossible();
		mBoard->addBalls();
	} else {
		//Change currently selected ball
		source=target;
		//Clear possible locations/pathfinding and find new ones
		mBoard->clearPossible();
		mBoard->findPossible(source);
	}
}

std::vector<point> gameEngine::findPath(point source, point target){
	//Move from source to target
	//We shall create a path from target to the source using parent directions in board.
	//Then reverse travel the path to go from source to target and animate

	//Used to hold path from target to source
	std::vector<point> path;

	//Used to walk along the path from target to source to generate path		
	point currentPoint=target;

	//Repeat until we hit the source

	//Add target point to the path as the first step
	path.push_back(target);

	while(currentPoint!=source){			
		//See which way to travel next based on contents of board
		//Subtract UP to get direction as opposed to ball number
		//yes I "overloaded" the board instead of creating a new array...
		//you learn these things in RISC OS, sigh
		switch(mBoard->getCell(currentPoint)-UP){
		case 0://Up
			currentPoint.y-=1;
			break;
		case 1://Right
			currentPoint.x+=1;
			break;
		case 2://Down
			currentPoint.y+=1;
			break;
		case 3://Left
			currentPoint.x=-1;
			break;
		default:
			//Should never hit unless pathfinding was corrupted
			break;
		}
		//Add current point to the path
		path.push_back(currentPoint);
	}

	//reverse the path
	std::reverse(path.begin(),path.end());
	return path;
}