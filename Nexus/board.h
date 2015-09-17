#ifndef _BOARD_
#define _BOARD_

#define BOARD_SIZE 9

class board
{
public:
	board();									//Constructor

	void resetBoard();							//Clears off the board for a new game
	int getCell(int pX, int pY);				//Returns the contents on given cell
	void setCell(int pY, int pY, int contents);	//Sets the contents of a cell

private:
	int mBoard[BOARD_SIZE][BOARD_SIZE];			//Contents of the board
};
#endif