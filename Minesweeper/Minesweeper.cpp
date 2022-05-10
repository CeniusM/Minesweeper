#include "Minesweeper.h"




int** Minesweeper::GetBoard()
{
	return m_board;
}

int Minesweeper::GetState()
{
	return m_state;
}

int Minesweeper::GetFirstCount()
{
	return m_Count1;
}

int Minesweeper::GetSecondCount()
{
	return m_Count2;
}

Minesweeper::Minesweeper(int i, int j)
{
	m_state = 1;
	m_Count1 = i;
	m_Count2 = j;
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
	for (int ii = 0; ii < m_Count1; ii++) {
		delete[] m_board[ii];
	}
	delete[] m_board;
}