

const void GetMinesAround(int** board, int length1, int length2)
{
	int mines = 0;
	for (int i = 0; i < length1; i++)
	{
		for (int j = 0; j < length2; j++)
		{
			for (int ii = -1; ii < 2; ii++)
			{
				for (int jj = -1; jj < 2; jj++)
				{
					if (i + ii < length1 && j + jj < length2 && i + ii > -1 && j + jj > -1)
						if ((board[i + ii][j + jj] & 0b010) == 0b010)
							mines++;
				}
			}
			board[i][j] ^= (mines << 3);
			mines = 0;

			// make all seen for debuging
			//board[i][j] ^= 0b1;
		}
	}
}