#include "board.h"
#include <string.h>
#include <vector>

/// <summary>
/// Sets up the board for initial use
/// </summary>
board::board(){
	resetBoard();
}

/// <summary>
/// Resets the board for a new game
/// </summary>
void board::resetBoard(){
	memset(mBoard,FREE,sizeof(mBoard));
}

/// <summary>
/// Find contents of a given location
/// </summary>
/// <param name="location">Location on board</param>
/// <returns>Ball number</returns>
int board::getCell(point location){
	if (checkBounds(location)){
		return mBoard[location.x][location.y];
	} else {
		return -1;
	}
}

/// <summary>
/// Store a ball at the given location
/// </summary>
/// <param name="location">Location on board</param>
/// <param name="ball">Ball number</param>
void board::setCell(point location, int ball){
	if (checkBounds(location)){
		mBoard[location.x][location.y]=ball;
	}
}

/// <summary>
/// Add 3 random balls the the board in random locations
/// </summary>
void board::addBalls(){
	//Create a vector of free spaces
	std::vector<point> freeSquares;

	for (int y=0;y<BOARD_SIZE;y++){
		for (int x=0;x<BOARD_SIZE;x++){
			if (mBoard[x][y]==FREE){
				freeSquares.push_back(point(x,y));
			}
		}
	}

	//Randomize the vector
	std::random_shuffle(freeSquares.begin(),freeSquares.end());

	//Add 3 balls or less if that is all the room that is left
	//TODO integer literal!
	int numberToAdd=(freeSquares.size()<3)?freeSquares.size():3;
	//Loop through and add a ball
	for (int i=0;i<numberToAdd;i++){
		//Get free location
		point location=freeSquares.at(i);
		//Get a random ball
		//+1 to account for the FREE cell at index 0
		int ballNumber=rand()%(NUMBER_BALLS)+1;
		//Store on board
		setCell(location,ballNumber);
	}
}

/// <summary>
/// Checks a given point is with in bounds for the board
/// </summary>
/// <param name="location">location to check</param>
/// <returns>True within bounds/false otherwise</returns>
bool board::checkBounds(point location){
	return !(location.x<0 || location.x>=BOARD_SIZE || location.y<0 || location.y>=BOARD_SIZE);
}
/// <summary>
/// Shows all the possible locations that the selected ball can be placed in
/// and create the paths require to travel to any valid place
/// Widely adapter from: http://www.redblobgames.com/pathfinding/a-star/introduction.html
/// </summary>
/// <param name="source">Starting point</param>
void board::findPossible(point source){
	//Used as a list of points to check
	std::vector<point> frontier;

	//Add starting point to list
	frontier.push_back(source);

	while(frontier.size()!=0){
		//Grab first point from list
		point current=frontier[0];
		//Remove first point from the list
		frontier.erase(frontier.begin());

		//Create neighbours in clockwise order from up
		point neighbours[]={
		point(current.x,current.y-1),
		point(current.x+1,current.y),
		point(current.x,current.y+1),
		point(current.x-1,current.y)};

		//Loop through each neighbour
		//TODO Check, I think this should probably be an iterator but this works too...
		int numberOfNeighbours=sizeof(neighbours)/sizeof(point);
		for (int dir=0;dir<numberOfNeighbours;dir++){
			//Check if neighbour is a free cell
			if (getCell(neighbours[dir])==FREE){
				//Set cell to point to where we came from be reversing the direction number
				int oppositeDirection=((dir+numberOfNeighbours/2)%numberOfNeighbours);
				//Add start of image arrows
				setCell(neighbours[dir],oppositeDirection+UP);
				//Add to frontier list for later exploration
				frontier.push_back(neighbours[dir]);
			}
		}		
	}
}

/// <summary>
/// Clears possible targets from board, replacing them with free
/// </summary>
void board::clearPossible(){
	for (int y=0;y<BOARD_SIZE;y++){
		for (int x=0;x<BOARD_SIZE;x++){
			if (mBoard[x][y]>=POSSIBLE){
				mBoard[x][y]=FREE;
			}
		}
	}
}

