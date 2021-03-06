#include "SDLLib.h"
#include "board.h"
#include "gameEngine.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>


int main(){
	//Init randomizer
	srand((unsigned)time(NULL));

	//SDL library
	SDLLib mSDLLib;

	//Game board
	board mBoard;

	//Game engine
	gameEngine mGameEngine(&mBoard, &mSDLLib);

	//Main game loop flag
	bool gameOver=false;
	bool exitGame=false;

	//TODO: remove as this is for testing
	mBoard.addBalls();
	mBoard.addBalls();

	//Game loop
	while(!exitGame){
		while(!gameOver){
			//Check for gameover
			//TODO

			//Get input
			//TODO checking mouse event
			mGameEngine.input();

			//Draw board
			mGameEngine.drawBoard();
			mSDLLib.updateScreen();

		}
		//TODO End of game
		printf("Game over");
		//TODO Check for new game
	}

	return 0;
}