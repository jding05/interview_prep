#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "header.h"

/*
** below is sortArts() *******************************************
*/

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

/*
** below is search *******************************************
*/

int		binarySearch(struct s_art **arts, int left, int right, char *name)
{
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		int res = strcmp(arts[mid]->name, name);
		if (res == 0)
		{
			return (arts[mid]->price);
		}
		else if (res < 0)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return (-1);
}

int 	searchPrice(struct s_art **arts, int n, char *name)
{
	return (binarySearch(arts, 0, n - 1, name));
}


// int		countArts(struct s_art **arts)
// {
// 	int i = 0;
// 	while (*arts)
// 	{
// 		arts++;
// 		i++;
// 	}
// 	return (i);
// }

// void	sort_recur(struct s_art **arts, int n)
// {
// 	if (n <= 1)
// 		return ;
// 	int Ppos = n - 1;
// 	struct s_art *t = (struct s_art*)malloc(sizeof(struct s_art));
// 	*t = *(arts[n / 2]);
// 	*(arts[n / 2]) = *(arts[Ppos]);
// 	*(arts[Ppos]) = *t;
// 	for (int i = 0; i < Ppos; i++)
// 		if (strcmp(arts[i]->name, t->name) > 0)
// 		{
// 			*(arts[Ppos]) = *(arts[i]);
// 			if (Ppos > i + 1)
// 			{
// 				Ppos--;
// 				*(arts[i]) = *(arts[Ppos]);
// 				*(arts[Ppos]) = *t;
// 				i--;
// 			}
// 			else
// 			{
// 				*(arts[i]) = *t;
// 				Ppos = i;
// 				break ;
// 			}
// 		}
// 	sort_recur(arts, Ppos);
// 	sort_recur(arts + Ppos + 1, n - Ppos - 1);
// 	free(t);
// }

// void	sortArts(struct s_art **arts)
// {
// 	sort_recur(arts, countArts(arts));
// }

// int	searchPrice(struct s_art **arts, int n, char *name)
// {
// 	int k;

// 	if (n / 2 == 0)
// 		return (strcmp(arts[0]->name, name) ? -1 : arts[0]->price);
// 	if (!(k = strcmp((arts[n / 2])->name, name)))
// 		return (arts[n / 2]->price);
// 	if (k > 0)
// 		return (searchPrice(arts, n / 2, name));
// 	return (searchPrice(arts + n / 2, n - n / 2, name));
// }
