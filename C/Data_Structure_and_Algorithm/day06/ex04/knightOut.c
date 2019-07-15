#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "header.h"

int getInitialPos(uint64_t board)
{
	int pos = 0;
	while ((board >> pos & 1) == 0)
		pos++;
	return pos;
}

double probability(int ***cache, int x, int y, int n)
{
	if ((x < 0 || x > 7) || (y < 0 || y > 7))
		return 1;
	if (n == 0 && (x >= 0 && x <= 7) && (y >= 0 && y <= 7))
		return 0;
	if (cache[x][y][n])
		return (cache[x][y][n]);
	double p = probability(cache, x - 2, y + 1, n - 1) * 1 / 8
			 + probability(cache, x - 2, y - 1, n - 1) * 1 / 8
			 + probability(cache, x - 1, y + 2, n - 1) * 1 / 8
			 + probability(cache, x + 1, y + 2, n - 1) * 1 / 8
			 + probability(cache, x + 2, y + 1, n - 1) * 1 / 8
			 + probability(cache, x + 2, y - 1, n - 1) * 1 / 8
			 + probability(cache, x - 1, y - 2, n - 1) * 1 / 8
			 + probability(cache, x + 1, y - 2, n - 1) * 1 / 8;
	cache[x][y][n] = p;
	return p;
}

int ***initMap()
{
	int ***map = (int***)malloc(sizeof(int**) * 8);
	for (int i = 0; i < 8; i++)
	{
		map[i] = (int**)malloc(sizeof(int*) * 8);
		for (int j = 0; j < 8; j++)
		{
			map[i][j] = (int*)malloc(sizeof(int) * 8);
			for (int k = 0; k < 8; k++)
				map[i][j][k] = 0;
		}
	}
	return map;
}

double	knightOut(uint64_t board, int n)
{
	int pos = getInitialPos(board);
	double prob = 0.0;

	if ((int)board < 0 || n < 0)
		return -1;
	int ***map = initMap();
	int row = pos / 8;
	int col = pos % 8;
	prob = probability(map, row, col, n);
	return prob;
}