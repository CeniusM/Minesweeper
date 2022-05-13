#include "MinesweeperGame.h"
#include "Minesweeper.h"
#include "GameLogic.h"
#include "MyHelper.cpp"
#include "GUI.h";

#include <iostream>

void Game::MainLoop()
{
	int foo = 100;

	running = true;
	Minesweeper MGame(20, 30);
	GUI gui(MGame.GetFirstLength(), MGame.GetSecondLength(), MGame.GetBoard());
	GenerateBoard(MGame, 10, 1, 1);
	while (MGame.GetState() == 1 && running)
	{
		MH::Clear();
		gui.PrintBoard();
		MH::ThreadSleep(500);
		if (foo < 0) running = 0;
		foo--;
	}	
}

Game::Game()
{
	running = false;
}

Game::~Game()
{
}