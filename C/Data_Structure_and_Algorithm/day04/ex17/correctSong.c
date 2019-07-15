#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "header.h"

void	correctSong(struct s_bit *bit, int l, int row, int col, int dist)
{
	if (row < l)
		for (int i = row; i < row + dist; i++)
			bit->arr[i] |= 1 << col; 
}
