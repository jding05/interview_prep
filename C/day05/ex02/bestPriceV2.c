#include "header.h"
#include <stdio.h>
#include <stdlib.h>

double	getBest(int pizzaSize, double *stored, double *prices)
{
	if (stored[pizzaSize])
		return stored[pizzaSize];
	stored[pizzaSize] = prices[pizzaSize];
	for (int i = 1; i < pizzaSize; i++)
	{
		double max = getBest(i, stored, prices) + getBest(pizzaSize - i, stored, prices);
		if (max > stored[pizzaSize])
			stored[pizzaSize] = max;
	}
	return stored[pizzaSize];
}

double	optimizedBestPrice(int pizzaSize, double *prices)
{
	double *stored = calloc(pizzaSize, sizeof(double));
	double res = getBest(pizzaSize, stored, prices);
	free(stored);
	return (res);
}