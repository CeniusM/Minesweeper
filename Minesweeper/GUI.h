#pragma once

#include "Minesweeper.h"

class GUI
{
public:
	GUI(int i, int j, int** board);
	~GUI();

	void PrintBoard();

private:
	char* m_line;
	char* m_linePtr;
	int** board;
	int count1;
	int count2;
};