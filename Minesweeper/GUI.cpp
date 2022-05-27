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

void GUI::PrintBoard()
{
	int piece;
	for (int i = 0; i < count1; i++)
	{
		for (int j = 0; j < count2; j++)
		{
			piece = board[i][j];
	
			screen[i * count1 + j * 3] = '[';
			switch (piece & 0b111)
			{
			case 0b001: // seen, no bomb
				if ((piece & PieceFlag::bombAmount) != 0) // puts in the number of bombs
					screen[i * count1 + j * 3 + 1] = (char)((piece >> 3) + (char)'0');
				else
					screen[i * count1 + j * 3 + 1] = ' ';
				break;
			case 0b000: // unseen
				screen[i * count1 + j * 3 + 1] = '?';//(char)219; // (char)219 = '█'
				break;
			case 0b100: // unseen flag
				screen[i * count1 + j * 3 + 1] = 'P';
				break;
			case 0b011: // seen, bomb
				screen[i * count1 + j * 3 + 1] = 'X';
				break;
			default:
				break;
			}
			screen[i * count1 + j * 3 + 2] = ']';
		}
	}

	// Display Frame
	screen[nScreenWidth * nScreenHeight - 1] = '\0';
	WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight * 3, { 0,0 }, &dwBytesWritten);

	//MH::gotoxy(0,0);
	//int piece;
	//for (int i = 0; i < count1; i++)
	//{
	//	for (int j = 0; j < count2; j++)
	//	{
	//		piece = board[i][j];
	//
	//		m_linePtr = &m_line[j*3];
	//
	//		m_linePtr[0] = '[';
	//		switch (piece & 0b111)
	//		{
	//		case 0b001: // seen, no bomb
	//			if ((piece & PieceFlag::bombAmount) != 0) // puts in the number of bombs
	//				m_linePtr[1] = (char)((piece >> 3) + (char)'0');
	//			else
	//				m_linePtr[1] = ' ';
	//			break;
	//		case 0b000: // unseen
	//			m_linePtr[1] = '?';//(char)219; // (char)219 = '█'
	//			break;
	//		case 0b100: // unseen flag
	//			m_linePtr[1] = 'P';
	//			break;
	//		case 0b011: // seen, bomb
	//			m_linePtr[1] = 'X';
	//			break;
	//		default:
	//			break;
	//		}
	//		m_linePtr[2] = ']';
	//	}
	//	std::cout << m_line << std::endl;
	//}
}

GUI::GUI(int x, int y, int** board)
{
	nScreenWidth = x;
	nScreenHeight = y;

	// Create Screen Buffer
	screen = new wchar_t[nScreenWidth * 3 * nScreenHeight]; 
	for (int i = 0; i < nScreenHeight; i++)
	{
		for (int j = 0; j < nScreenWidth; j++)
		{
			screen[i * nScreenWidth + j * 3] = ' ';
			screen[i * nScreenWidth + j * 3 + 1] = ' ';
			screen[i * nScreenWidth + j * 3 + 2] = ' ';
		}
	}
	hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	dwBytesWritten = 0;

	// set console size
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	MoveWindow(console, r.left, r.top, nScreenWidth * 3 * 8 + 40 /*why i need 40, no clue*/, nScreenHeight * 16, TRUE);

	// my own crab
	count1 = x;
	count2 = y;
	this->board = board;
}

GUI::~GUI()
{
	delete[] screen;
}