#include "header.h"

void rotate(int **picture, int n)
{
	for (int row = 0; row < n/2; row++)
	{
		for (int col = 0; col < n/2; col++)
		{
			int tmp = picture[row][col];
			picture[row][col] = picture[n - row -1][col];
			picture[n - row -1][col] = picture[n - row -1][n - col -1];
			picture[n - row -1][n - col -1] = picture[row][n - col -1];
			picture[row][n - col -1] = tmp;
		}
	}
}

// example
// 1   2  3  4    13 9  5 1
// 5   6  7  8    14 10 6 2
// 9  10 11 12    15 11 7 3
// 13 14 15 16    16 12 8 4 
