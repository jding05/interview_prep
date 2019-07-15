 #include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include "header.h"

// quick sort

static void swap(struct s_player **left, struct s_player **right)
{
	struct s_player *tmp = *left;
	*left = *right;
	*right = tmp;
}

static int partition(struct s_player **players, int left, int right)
{
	int pivotIndex = left + rand() % (right - left +1);
	int pivotScore = players[pivotIndex]->score;
	swap(&players[pivotIndex], &players[left]);
	int leftIndex = left + 1;
	int rightIndex = right;
	while (leftIndex <= rightIndex)
	{
		if (players[leftIndex]->score >= pivotScore)
			leftIndex++;
		else if (players[rightIndex]->score < pivotScore)
			rightIndex--;
		else
			swap(&players[leftIndex++], &players[rightIndex--]);
	}
	swap(&players[rightIndex], &players[left]);
	return rightIndex;
}

static void quickSortR(struct s_player **players, int left, int right)
{
	if (left >= right)
		return ;
	int pivotPos = partition(players, left, right);
	quickSortR(players, left, pivotPos -1);
	quickSortR(players, pivotPos + 1, right);
}

void quickSort(struct s_player **players)
{
	int size = 0;
	while (players[size++]);
	if (size-- <= 1)
		return ;
	printf("size: %d", size);
	quickSortR(players, 0, size -1);
}