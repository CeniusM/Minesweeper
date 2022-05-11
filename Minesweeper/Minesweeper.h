#pragma once

class Minesweeper
{
public:
	Minesweeper(int i, int j);
	~Minesweeper();

	int MakeMove(int x, int y);
	int** GetBoard();
	int GetState();

	int GetFirstCount();
	int GetSecondCount();

private:
	bool firstMove;
	int m_state;
	int** m_board;

	// first lenght
	int m_Count1;
	// second lenght
	int m_Count2;
};

/*

m_board int piece,

0b001   = seen
0b010   = bomb
0b100   = flaged

*/

