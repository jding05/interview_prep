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
	for (int i = left; i <= right; i++)
	{
		helper[i] = players[i];
	}
	int l = left; 
	int r = mid + 1;
	while (l <= mid && r <= right)
	{
		if (helper[l]->score >= helper[r]->score)
			players[left++] = helper[l++];
		else
			players[left++] = helper[r++];
	}
	if (l <= mid)
		players[left++] = helper[l++];
	if (r <= right)
		players[left++] = helper[r++];
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
	while (players[size++]);
	if (size-- <= 1)
		return players;
	struct s_player **helper = (struct s_player **)malloc(sizeof(struct s_player) * size + 1);
	split(players, helper, 0, size -1);
	return players;
}









// typedef struct s_player t_player;

// void merge_recur(t_player **players, t_player **arr, int n)
// {
// 	if (n / 2 > 1)
// 	{
// 		merge_recur(players, arr, n / 2);
// 		merge_recur(&players[n / 2], &arr[n / 2], n - n / 2);
// 	}
// 	int c = 0;
// 	int c2 = n / 2;
// 	for (int i = 0; i < n; i++)
// 	{
// 		if (c == -1 || c2 == -1)
// 		{
// 			arr[i] = (c == -1 ? players[c2++] : players[c++]);
// 			continue ;
// 		}
// 		if (players[c]->score >= players[c2]->score)
// 		{
// 			arr[i] = players[c];
// 			c = (c + 1 >= n / 2 ? -1 : c + 1);
// 		}
// 		else
// 		{
// 			arr[i] = players[c2];
// 			c2 = (c2 + 1 >= n ? -1 : c2 + 1);
// 		}
// 	}
// 	for (int i = 0; i < n; i++)
// 		players[i] = arr[i];
// }

// struct s_player **mergeSort(struct s_player **players)
// {
// 	int size = 0;

// 	while (players[size])
// 		size++;

// 	t_player **arr = malloc(sizeof(t_player*) * (size + 1));
// 	merge_recur(players, arr, size);
// 	free(arr);
// 	return (players);
// }
