#include "MyHelper.cpp"
#include "GUI.h"

void GUI::PrintBoard()
{
	MH::gotoxy(0,0);
	int piece;
	for (int i = 0; i < count1; i++)
	{
		for (int j = 0; j < count2; j++)
		{
			piece = board[i][j];

			switch (piece & 0b111)
			{
			case 0b001: // seen, no bomb
				if ((piece & 0b1111000) != 0) // puts in the number of bombs
					m_line[j] = (char)((piece >> 3) + (char)'0');
				else
					m_line[j] = ' ';
				break;
			case 0b000: // unseen
				m_line[j] = (char)219; // (char)219 = '█'
				break;
			case 0b100: // unseen flag
				m_line[j] = 'P';
				break;
			case 0b101: // seen, bomb
				m_line[j] = 'X';
				break;
			default:
				break;
			}
		}
		std::cout << m_line << std::endl;
	}
}

GUI::GUI(int i, int j, int** board)
{
	count1 = i;
	count2 = j;
	m_line = new char[j + 1];
	for (int ii = 0; ii < j; ii++)
		m_line[ii] = (char)0;
	m_line[j] = NULL;
	this->board = board;
}

GUI::~GUI()
{
	delete[] m_line;
}