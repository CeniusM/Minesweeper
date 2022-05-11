#include "MinesweeperGame.h"
#include "MyHelper.cpp"

#include <iostream>

int main()
{
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
	game.MainLoop();
}