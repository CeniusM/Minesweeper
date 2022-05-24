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

			m_linePtr = &m_line[j*3];

			m_linePtr[0] = '[';
			switch (piece & 0b111)
			{
			case 0b001: // seen, no bomb
				if ((piece & PieceFlag::bombAmount) != 0) // puts in the number of bombs
					m_linePtr[1] = (char)((piece >> 3) + (char)'0');
				else
					m_linePtr[1] = ' ';
				break;
			case 0b000: // unseen
				m_linePtr[1] = '?';//(char)219; // (char)219 = '█'
				break;
			case 0b100: // unseen flag
				m_linePtr[1] = 'P';
				break;
			case 0b011: // seen, bomb
				m_linePtr[1] = 'X';
				break;
			default:
				break;
			}
			m_linePtr[2] = ']';
		}
		std::cout << m_line << std::endl;
	}
}

GUI::GUI(int i, int j, int** board)
{
	count1 = i;
	count2 = j;
	m_line = new char[j * 3 + 1];
	for (int ii = 0; ii < j * 3; ii++)
		m_line[ii] = (char)0;
	m_line[j * 3] = NULL;
	m_linePtr = nullptr;
	this->board = board;
}

GUI::~GUI()
{
	delete[] m_line;
}