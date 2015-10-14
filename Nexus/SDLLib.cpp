#include "SDLLib.h"
#include "board.h"

SDL_Window* gWindow = NULL;			//The window we are rendering to

SDL_Surface* gScreenSurface=NULL;	//The window surface

SDL_Surface* gBalls[9];			//The coloured ball images
									//Last image is selected image

/// <summary>
/// Sets up SDL subsystems
/// </summary>
SDLLib::SDLLib(){
	//Init
	SDL_Init(SDL_INIT_EVERYTHING);

	//Create window
	gWindow=SDL_CreateWindow("Nexus",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	
	//Create surface for window
	gScreenSurface = SDL_GetWindowSurface( gWindow );

	//Load media
	loadMedia();
}

/// <summary>
/// Frees up allocated resources
/// </summary>
SDLLib::~SDLLib(){
	//Deallocate surfaces
	for (int i=0;i<9;i++){
		SDL_FreeSurface(gBalls[i]);
		gBalls[i]=NULL;
	}


	//Destroy Window
	SDL_DestroyWindow(gWindow);
	gWindow=NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();

}
/// <summary>
/// Loads all the image files into an array for drawing
/// </summary>
void SDLLib::loadMedia(){
	//Load ball images
	gBalls[0]=IMG_Load("img/free.png");
	gBalls[1]=IMG_Load("img/bleau.png");
	gBalls[2]=IMG_Load("img/blue.png");
	gBalls[3]=IMG_Load("img/green.png");
	gBalls[4]=IMG_Load("img/purple.png");
	gBalls[5]=IMG_Load("img/red.png");
	gBalls[6]=IMG_Load("img/yellow.png");

	gBalls[7]=IMG_Load("img/possible.png");
	gBalls[8]=IMG_Load("img/selected.png");
}

/// <summary>
/// Draws a ball at the given co-ords
/// </summary>
/// <param name="location">Location on board</param>
/// <param name="pBallNumber">Ball number</param>
void SDLLib::drawBall(point location, int pBallNumber){
	//Create SDL Rectangle for the ball image to draw to the screen
	SDL_Rect DestR;
	DestR.x=location.x*BALL_SIZE;
	DestR.y=location.y*BALL_SIZE;
	DestR.h=DestR.w=BALL_SIZE;

	SDL_BlitSurface(gBalls[pBallNumber], NULL, gScreenSurface, &DestR);
	
}

/// <summary>
/// Force SDL to update changes to the screen
/// </summary>
void SDLLib::updateScreen(){
	SDL_UpdateWindowSurface( gWindow );
}

/// <summary>
/// Returns a point that has been clicked on
/// </summary>
/// <returns>Board location clicked on</returns>
point SDLLib::getMouseClick(){
	point temp=point(NULL,NULL);
	SDL_Event e;
	while (SDL_PollEvent(&e)){
		switch(e.type){
		case SDL_MOUSEBUTTONDOWN:
			temp.x=e.motion.x;
			temp.y=e.motion.y;
			break;
		}
	}
	return temp;
}