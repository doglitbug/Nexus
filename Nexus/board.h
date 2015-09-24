#ifndef _BOARD_
#define _BOARD_

#define BOARD_SIZE 9
#define NUMBER_BALLS 6

class board
{
public:
	board();									//Constructor

	void resetBoard();							//Clears off the board for a new game
	int getCell(int pX, int pY);				//Returns the contents on given cell
	void setCell(int pX, int pY, int ball);		//Sets the contents of a cell
	void addBalls();							//Add 3 radom balls to the board
private:
	int mBoard[BOARD_SIZE][BOARD_SIZE];			//Contents of the board
};
#endif