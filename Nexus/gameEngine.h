#ifndef _GAMEENGINE_
#define _GAMEENGINE_

#include "board.h"
#include "SDLLib.h"
#include "common.h"

class gameEngine
{
public:
	gameEngine(board *pBoard, SDLLib *pSDLLib);	//Create new engine
	~gameEngine();

	void drawBoard();							//Draws the board to the screen
	void input();								//Attempt to deal with game input
private:
	board *mBoard;
	SDLLib *mSDLLib;
};
#endif