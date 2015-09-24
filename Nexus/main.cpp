#include "SDLLib.h"
#include "board.h"
#include "gameEngine.h"
#include <time.h>


int main(){
	//Init randomizer
	srand((unsigned)time(NULL));

	//SDL library
	SDLLib mSDLLib;

	//Game board
	board mBoard;

	//Game engine
	gameEngine mGameEngine(&mBoard, &mSDLLib);

	mBoard.addBalls();

	mGameEngine.drawBoard();

	mSDLLib.updateScreen();

	SDL_Delay(2000);

	return 0;
}