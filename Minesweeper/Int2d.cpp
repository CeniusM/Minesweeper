#include "Int2d.h"

Int2d::Int2d(int i, int j)
{
	Count1 = i;
	Count2 = j;
	arr2d = new int*[i];
	for (int ii = 0; ii < i; ii++)
	{
		arr2d[ii] = new int[j];
		for (int jj = 0; jj < j; jj++)
		{
			arr2d[ii][jj] = 0;
		}
	}
}

Int2d::~Int2d()
{
	for (int ii = 0; ii < Count1; ii++) {
		delete[] arr2d[ii];
	}
	delete[] arr2d;
}

int* Int2d::operator[](int index)
{
	return arr2d[index];
}

int Int2d::GetFirstCount()
{
	return Count1;
}

int Int2d::GetSecondCount()
{
	return Count2;
}
