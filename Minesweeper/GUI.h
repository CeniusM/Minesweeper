#pragma once

#include "Minesweeper.h"

class GUI
{
public:
	GUI(int i, int j, int** board);
	~GUI();

	void PrintBoard();

private:
	void SetConsoleSize(int x, int y, int charWidth, int charHeight);

	int** board;
	int count1;
	int count2;

	wchar_t* screen;
	wchar_t** screen2d;
	HANDLE hConsole;
	DWORD dwBytesWritten;
	int nScreenWidth;
	int nScreenHeight;
};