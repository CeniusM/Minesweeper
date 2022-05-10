#pragma once

//my way of making a more easy to use 2d array in c++
class Int2d
{
public:
	Int2d(int i, int j);
	~Int2d();

	int* operator[](int index);

	int GetFirstCount();
	int GetSecondCount();

private:
	int Count1;
	int Count2;
	int** arr2d;
};

