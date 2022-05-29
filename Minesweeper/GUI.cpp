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
	MoveWindow(console, r.left, r.top, x * charWidth + 40/*why i need +40, no clue*/, y * charHeight + 40, TRUE);
}

void GUI::PrintBoard()
{
	// Generate Frame


	// Display Frame
	screen[nScreenWidth * nScreenHeight - 1] = '\0';
	WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight * 3, { 0,0 }, &dwBytesWritten);
}

GUI::GUI(int x, int y, int** board)
{
	nScreenWidth = x; // *2 or 3 for the width of any given square
	nScreenHeight = y;

	// Create Screen Buffer
	screen = new wchar_t[nScreenWidth * nScreenHeight]; 
	for (int i = 0; i < nScreenHeight; i++)
	{
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
}