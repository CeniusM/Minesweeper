#include "Minesweeper.h"
#include "GameLogic.h"

int Minesweeper::MakeMove(int x, int y)
{
	if (x < 0 || y < 0 || x > m_Length1 || y > m_Length2)
		return 0;
	if (firstMove)
	{
		GenerateBoard(*this, m_Length1 * m_Length2 / 20, x, y);
		firstMove = false;
		m_board[x][y] ^= 0b1;
		return true;
	}
	if ((m_board[x][y] & 0b1) == 1)
		return 0;


	MakeSeen(*this, x, y);
	//m_board[x][y] |= 0b1;



	return 1; // unless its allredy a taken square
}

int** Minesweeper::GetBoard()
{
	return m_board;
}

int Minesweeper::GetState()
{
	return m_state;
}

int Minesweeper::GetFirstLength()
{
	return m_Length1;
}

int Minesweeper::GetSecondLength()
{
	return m_Length2;
}

Minesweeper::Minesweeper(int i, int j)
{
	firstMove = true;
	m_state = 1;
	m_Length1 = i;
	m_Length2 = j;
	m_board = new int* [i];
	for (int ii = 0; ii < i; ii++)
	{
		m_board[ii] = new int[j];
		for (int jj = 0; jj < j; jj++)
		{
			m_board[ii][jj] = 0;
		}
	}
}

Minesweeper::~Minesweeper()
{
	for (int ii = 0; ii < m_Length1; ii++) {
		delete[] m_board[ii];
	}
	delete[] m_board;
}