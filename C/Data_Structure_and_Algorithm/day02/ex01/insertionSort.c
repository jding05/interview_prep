#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include "header.h"

// insertion sort

void insertionSort(struct s_player **players)
{
	int size = 0;
	while (players[size++]);
	if (size-- <= 1)
		return ;
	for (int i = 0; i < size; i++)
	{
		struct s_player *tmp = players[i];
		int j = i -1;
		while (j >= 0 && players[j]->score < tmp->score)
		{
			players[j + 1] = players[j];
			j--;
		}
		players[j + 1] = tmp;
	}
}