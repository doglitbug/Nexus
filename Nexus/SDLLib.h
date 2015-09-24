#ifndef _SDLLIB_
#define _SDLLIB_

#include <SDL.h>
#undef main
#include <SDL_image.h>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768
#define BALL_SIZE 40

class SDLLib
{
public:
	SDLLib();										//Constructor
	~SDLLib();										//Destructor
	void drawBall(int x, int y, int ballNumber);	//Draw a ball at grid location
	void updateScreen();							//Updates the screen
private:
	void loadMedia();								//Loads the images for use
};
#endif