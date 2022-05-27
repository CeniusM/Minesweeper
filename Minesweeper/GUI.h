#pragma once

#include "Minesweeper.h"

class GUI
{
public:
	GUI(int i, int j, int** board);
	~GUI();

	void PrintBoard();

private:
	int** board;
	int count1;
	int count2;

	wchar_t* screen;
	HANDLE hConsole;
	DWORD dwBytesWritten;
	int nScreenWidth;
	int nScreenHeight;
};