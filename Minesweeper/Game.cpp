#include "MinesweeperGame.h"
#include "Minesweeper.h"
#include "GameLogic.h"
#include "MyHelper.cpp"
#include "GUI.h";

#include <iostream>

void Game::MainLoop()
{
	MH::NewPage();

	running = true;

	int x = 0, y = 0;
	Minesweeper MGame(30, 30);
	GUI gui(MGame.GetFirstLength(), MGame.GetSecondLength(), MGame.GetBoard());
	while (MGame.GetState() == 1 && running)
	{
		if (GetKeyState('A') & 0x8000)
			if (x > 0)
				x -= 3;
		if (GetKeyState('D') & 0x8000)
			if (x + 3< MGame.GetSecondLength() * 3 - 1)
				x += 3;
		if (GetKeyState('W') & 0x8000)
			if (y > 0)
				y--;
		if (GetKeyState('S') & 0x8000)
			if (y < MGame.GetFirstLength() - 1)
				y++;
		if (GetKeyState(32) & 0x8000)
			MGame.MakeMove(y, x / 3);

		gui.PrintBoard();

		MH::gotoxy(x, y);
		std::cout << ">";
		MH::gotoxy(x + 2, y);
		std::cout << "<";

		MH::ThreadSleep(100);
	}	
}

Game::Game()
{
	running = false;
}

Game::~Game()
{
}