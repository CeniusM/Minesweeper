#include "MyHelper.cpp"
#include "GUI.h"


//idk what is needed
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <chrono>
#include <stdio.h>
#include <Windows.h>
#include <thread>
#include <string>

void GUI::SetConsoleSize(int x, int y, int charWidth, int charHeight)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	MoveWindow(console, r.left, r.top, x * charWidth, y * charHeight, TRUE);
}

void GUI::PrintBoard()
{
	// Generate Frame
	int piece = 0;
	for (int i = 0; i < count1; i++)
	{
		for (int j = 0; j < count2; j++)
		{
			piece = board[i][j];
			if ((piece & PieceFlag::Seen) == 0)
			{
				screen[i * count2 + j] = 0x2588;
				if ((piece & PieceFlag::Flaged) == 0)
					screen2d[i][j] = 0x2588;
				else
					screen2d[i][j] = 'P';
			}
			else
			{	
				if ((piece & PieceFlag::Bomb) == PieceFlag::Bomb)
					screen2d[i][j] = 'X';
				else if ((piece & PieceFlag::bombAmount) != 0)
					screen2d[i][j] = (char)((piece & PieceFlag::bombAmount) - (int)'0');

			}
		}
	}

	// Display Frame
	screen[nScreenWidth * nScreenHeight - 1] = '\0';
	WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
}

GUI::GUI(int x, int y, int** board)
{
	nScreenWidth = x; // *2 or 3 for the width of any given square
	nScreenHeight = y;

	// Create Screen Buffer
	screen = new wchar_t[nScreenWidth * nScreenHeight];
	screen2d = new wchar_t* [nScreenHeight];
	for (int i = 0; i < nScreenHeight; i++)
	{
		screen2d[i] = &screen[i * nScreenWidth];
		for (int j = 0; j < nScreenWidth; j++)
		{
			screen[i * nScreenWidth + j] = ' ';
		}
	}
	hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	dwBytesWritten = 0;

	SetConsoleSize(nScreenWidth, nScreenHeight, 8, 16);

	// my own crab
	count1 = x;
	count2 = y;
	this->board = board;
}

GUI::~GUI()
{
	delete[] screen;
	delete[] screen2d; // do i need to remove any more?
}