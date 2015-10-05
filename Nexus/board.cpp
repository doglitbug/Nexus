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
/// 
/// </summary>
/// <param name="source">Starting point</param>
void board::findPossible(point source){
	//Used in calculations
	point temp;

	std::vector<point> frontier;

	frontier.push_back(source);

	while(frontier.size()!=0){
		//grab first element from list
		point current=frontier[0];
		//Remove first from the list
		frontier.erase(frontier.begin());

		//Check all neighbours
		//Check up
		temp=current;
		temp.y-=1;
		if (getCell(temp)==FREE){
			setCell(temp,SOUTH);
			frontier.push_back(temp);
		}

		//Check right
		temp=current;
		temp.x+=1;
		if (getCell(temp)==FREE){
			setCell(temp,WEST);
			frontier.push_back(temp);
		}

		//Check down
		temp=current;
		temp.y+=1;
		if (getCell(temp)==FREE){
			setCell(temp,NORTH);
			frontier.push_back(temp);
		}

		//Check left
		temp=current;
		temp.x-=1;
		if (getCell(temp)==FREE){
			setCell(temp,EAST);
			frontier.push_back(temp);
		}
	}
}


	//while not frontier.empty():
	//	current = frontier.get()
	//	for next in graph.neighbors(current):
	//		if next not in visited:
	//			frontier.put(next)
	//			visited[next] = True

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

