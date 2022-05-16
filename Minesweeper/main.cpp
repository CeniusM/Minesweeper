#include "MinesweeperGame.h"
#include "GetMinesAround.h"
#include "MyHelper.cpp"

#include <functional>
#include <iostream>

int main()
{
	//int** board = new int*[1000];
	//for (int i = 0; i < 1000; i++)
	//	board[i] = new int[1000];
	//std::cout << MH::GetTimeOfAction("Time get mines", 1000000, std::bind(&GetMinesAround, board, 1000, 1000));
	//MH::ThreadSleep(10000);











	Game game;
	MH::WriteLine("welcome to my Minesweeper... enjoy <3");
	MH::WriteLine("count down...");
	for (int i = 3; i > 0; i--)
	{
		std::cout << i << std::endl;
		MH::ThreadSleep(1000);
	}
	MH::WriteLine("Go!");
	MH::ThreadSleep(1000);


	// .... tf
	MH::gotoxy(0,0);
	std::cout << "                                     " << std::endl;
	std::cout << "             " << std::endl;
	std::cout << " " << std::endl;
	std::cout << " " << std::endl;
	std::cout << " " << std::endl;
	std::cout << "   " << std::endl;
	MH::gotoxy(0, 0);


	game.MainLoop();
}