#include "Minesweeper.h"
#include "GetMinesAround.h"



void GenerateBoard(Minesweeper& MGame, int bombAmout, int startX, int startY)
{
	int** board = MGame.GetBoard();

	for (int i = 0; i < MGame.GetFirstLength(); i++)
	{
		for (int j = 0; j < MGame.GetSecondLength(); j++)
		{
			
		}
	}

	GetMinesAround(board, MGame.GetFirstLength(), MGame.GetSecondLength());
}