
#include "Minesweeper.h"
#include "GetMinesAround.h"

#include <stdlib.h>
#include <iostream>

void GenerateBoard(Minesweeper& MGame, int mineAmout, int startX, int startY)
{
	int** board = MGame.GetBoard();
	int firstLength = MGame.GetFirstLength();
	int secondLength = MGame.GetSecondLength();

	//int minesPlaced = 0;
	int squaresGoneThrough = 0;

	float chanceOfMine = // percent
		(float)mineAmout / (float)(firstLength * secondLength) * 100;

	for (int i = 0; i < firstLength; i++)
	{
		for (int j = 0; j < secondLength; j++)
		{
			if (rand() % 100 < (int)chanceOfMine)
			{
				//std::cout << chanceOfMine << " - " << squaresGoneThrough << " - ON" << std::endl;
				//minesPlaced++;
				board[i][j] ^= 0b010;
				mineAmout--;
			}
			//else
			//	std::cout << chanceOfMine << " - " << squaresGoneThrough << " - Off" << std::endl;

			chanceOfMine = (float)mineAmout / 
				(float)((firstLength * secondLength) - squaresGoneThrough)
				* 100;
			squaresGoneThrough++;
		}
	}
	//std::cout << minesPlaced << " | " << squaresGoneThrough << std::endl;
	GetMinesAround(board, firstLength, secondLength);
}

void MakeAroundSeen(Minesweeper& MGame, int x, int y, int depth) // need a redo
{
	if (depth < 1)
		return;
	int** board = MGame.GetBoard();
	if ((board[x][y] & PieceFlag::isChecked) == PieceFlag::isChecked)
		return;
	if ((board[x][y] & PieceFlag::Bomb) != 0)
		return;
	int xi = 0, yj = 0;
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			xi = x + i;
			yj = y + j;
			if (xi < MGame.GetFirstLength() && yj < MGame.GetSecondLength() && xi > -1 && yj > -1)
			{
				board[xi][yj] |= 0b1;
				if ((board[xi][yj] & PieceFlag::Bomb) != 0)
					continue;
				depth--;
				board[x][y] |= PieceFlag::isChecked;
				MakeAroundSeen(MGame, xi, yj, depth);
			}
		}
	}
}
void MakeSeen(Minesweeper& MGame, int x, int y)
{
	int depth = 10; // just in case
	MakeAroundSeen(MGame, x, y, depth);
}