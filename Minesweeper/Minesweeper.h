#pragma once

class Minesweeper
{
public:
	Minesweeper(int i, int j);
	~Minesweeper();

	int MakeMove(int x, int y);
	int** GetBoard();
	int GetState();

	int GetFirstLength();
	int GetSecondLength();

private:
	bool firstMove;
	int m_state;
	int** m_board;

	// first lenght
	int m_Length1;
	// second lenght
	int m_Length2;
};
/*

m_board int piece,

0b001   = seen
0b010   = bomb
0b100   = flaged

0b "1111" 000 = used to show how many bombs there is around

*/

