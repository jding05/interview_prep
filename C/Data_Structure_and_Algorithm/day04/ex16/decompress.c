#include <stdlib.h>
#include "header.h"

int	**pianoDecompress(struct s_bit *bit, int l)
{
	int **res = calloc(bit->n + 1, sizeof(int*));
	int n;
	for (int i = 0; i < bit->n; i++)
	{
		res[i] = calloc(l, sizeof(int));
		n = bit->arr[i];
		for (int j = 0; j < l; j++)
		{
			res[i][j] = n & 1;
			n >>= 1;
		}
	}
	return res;
}