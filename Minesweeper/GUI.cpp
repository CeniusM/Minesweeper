#include "MyHelper.cpp"
#include "GUI.h"

void GUI::PrintBoard()
{
	int piece;
	for (int i = 0; i < count1; i++)
	{
		for (int j = 0; j < count2; j++)
		{
			piece = board[i][j];
			m_linePtr = &m_line[i * 3];
			if ((piece & 0b1) == 0) // not seen
			{
				if ((piece & 0b100) == 0) // not flaged
				{
					m_linePtr[0] = '[';
					m_linePtr[1] = '?';
					m_linePtr[2] = ']';
				}
				else
				{
					m_linePtr[0] = '[';
					m_linePtr[1] = 'P';
					m_linePtr[2] = ']';
				}
			}
			else if ((piece & 0b10) == 0) // seen and no bomb
			{
				m_linePtr[0] = '[';
				m_linePtr[1] = ' ';
				m_linePtr[2] = ']';
			}
			else // seen and bomb
			{
				m_linePtr[0] = '[';
				m_linePtr[1] = 'X';
				m_linePtr[2] = ']';
			}
		}
		MH::WriteLine(m_line);
	}
}

GUI::GUI(int i, int j, int** board)
{
	count1 = i;
	count2 = j;
	m_line = (char*)malloc(sizeof(char) * j);
	m_linePtr = 0b0;
	this->board = board;
}

GUI::~GUI()
{
	delete[] m_line;
	delete m_linePtr;
}
