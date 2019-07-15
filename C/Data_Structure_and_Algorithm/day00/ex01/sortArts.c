#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "header.h"

int		countArts(struct s_art **arts)
{
	int counter = 0;
	while (*arts)
	{
		counter++;
		arts++;
	}
	return (counter);
}

void	merge(struct s_art **arts, struct s_art **helper, int left, int mid, int right)
{
	for (int i = left; i <= right; i++)
	{
		helper[i] = arts[i];
	}
	int leftBound = left;
	int rightBound = mid + 1;
	while (leftBound <= mid && rightBound <= right)
	{
		if (strcmp(helper[leftBound]->name, helper[rightBound]->name) <= 0)
		{
			arts[left++] = helper[leftBound++];
		}
		else
		{
			arts[left++] = helper[rightBound++];
		}
	}
	while (leftBound <= mid)
		arts[left++] = helper[leftBound++];
}

void	mergeSort(struct s_art **arts, struct s_art **helper, int left, int right)
{
	int	mid;

	if (left >= right)
		return ;
	mid = left + (right - left) / 2;
	mergeSort(arts, helper, left, mid);
	mergeSort(arts, helper, mid + 1, right);
	merge(arts, helper, left, mid, right);
}

void	sortArts(struct s_art **arts)
{
	struct s_art	**helper;
	int				len;

	len = countArts(arts);
	helper = malloc(sizeof(struct s_art*) * len);
	printf("len:%d\n",len);
	mergeSort(arts, helper, 0, len - 1);
	free(helper);
}
