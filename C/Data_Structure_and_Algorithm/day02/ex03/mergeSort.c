#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include "header.h"

// mergeSort
// since quickSort and insertion sort are not stable algorithm,
// it doesn't maintain index associations

static void merge(struct s_player **players, struct s_player **helper, int left, int mid, int right)
{
	// for (int i = left; i <= right; i++)
	// {
	// 	helper[i] = players[i];
	// }
	// int l = left; 
	// int r = mid + 1;
	// while (l <= mid && r <= right)
	// {
	// 	if (helper[l]->score >= helper[r]->score)
	// 		players[left++] = helper[l++];
	// 	else
	// 		players[left++] = helper[r++];
	// }
	// if (l <= mid)
	// 	players[left++] = helper[l++];
	// else if (r <= right)
	// 	players[left++] = helper[r++];

	int i, j;
	int len1 = mid - left + 1;
	int len2 = right - mid;
	struct s_player *L[len1];
	struct s_player *R[len2];

	for (i = 0; i < len1; i++)
		L[i] = players[left + i];
	for (j = 0; j < len2; j++)
		R[j] = players[mid + 1 + j];
	i = 0;
	j = 0;
	while (i < len1 && j < len2)
		if (L[i]->score >= R[j]->score)
			players[left++] = L[i++];
		else
			players[left++] = R[j++];

	while (i < len1)
		players[left++] = L[i++];
	while (j < len2)
		players[left++] = R[j++];
	helper = NULL;
}

static void split(struct s_player **players, struct s_player **helper, int left, int right)
{
	// validation
	if (left >= right)
		return ;
	// find mid ,and split to two half
	int mid = left + (right - left)/2;
	split(players, helper, left, mid);
	split(players, helper, mid + 1, right);
	merge(players, helper, left, mid, right);
}

struct s_player **mergeSort(struct s_player **players)
{
	int size = 0;
	while (players[size])
		size++;
	if (size <= 1)
		return players;
	struct s_player **helper = (struct s_player **)malloc(sizeof(struct s_player) * size + 1);
	split(players, helper, 0, size - 1);
	return players;
}
