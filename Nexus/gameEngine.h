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
	void doMouseClick(point location);			//Deal with mouse clicks

	board *mBoard;
	SDLLib *mSDLLib;
	bool selected;								//Is there a piece that has been selected prior to a move
	point selectedLocation;						//If so, where?
	bool selectedFlash;							//Are we in the flashing state?

	unsigned long mTime1;						//Used for flashing the selected piece
};
#endif