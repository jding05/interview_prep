#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include "header.h"

// counting sort --> for small range

void countSort(unsigned char *utensils, int n)
{
	unsigned char max = 0;
	for (int i = 0; i < n; i++)
	{
		if (utensils[i] > max)
			max = utensils[i];
	}
	int *array = (int*)malloc(sizeof(int) * (max + 1));
	bzero(array, sizeof(int) * (max + 1));
	for (int i = 0; i < n; i++)
		array[utensils[i]]++;
	int j = 0;
	for (int i = 0; i <= max; i++)
	{
		while (array[i])
		{
			utensils[j++] = i;
			array[i]--;
		}
	}
}

