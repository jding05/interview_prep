#include "header.h"

void rotate(int **picture, int n)
{
	int index_len = n -1;
	for (int row = 0; row < n/2; row++)
	{
		for (int col = row; col < index_len - row; col++)
		{
			int tmp = picture[row][col];
			picture[row][col] = picture[index_len - col][row];
			picture[index_len - col][row] = picture[index_len - row][index_len - col];
			picture[index_len - row][index_len - col] = picture[col][index_len - row];
			picture[col][index_len - row] = tmp;
		}
	}
}

// example
// 1   2  3  4    13 9  5 1
// 5   6  7  8    14 10 6 2
// 9  10 11 12    15 11 7 3
// 13 14 15 16    16 12 8 4 
