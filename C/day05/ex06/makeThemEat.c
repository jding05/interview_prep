#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	dfs(struct s_people **people, int index, int nbTable, int totalTime, int *arr)
{
	if (!people[index])
		return (1);
	for (int i = 0; i < nbTable; i++)
	{
		if (arr[i] + people[index]->time <= totalTime)
		{
			arr[i] += people[index]->time;
			if (dfs(people, index + 1, nbTable, totalTime, arr))
				return (1);
			arr[i] -= people[index]->time;
		}
	}
	return (0);
}

int	isPossible(struct s_people **people, int nbTable, int totalTime)
{
	int	*arr = calloc(nbTable, sizeof(int));
	int	res = dfs(people, 0, nbTable, totalTime, arr);
	free(arr);
	return (res);
}