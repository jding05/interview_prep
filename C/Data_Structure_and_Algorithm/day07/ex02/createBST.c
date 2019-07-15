#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include "header.h"

struct s_node *create(int *arr, int left, int right)
{
	if (left >= right)
		return NULL;
	int mid = left + (right - left) / 2;
	struct s_node *node = calloc(1, sizeof(struct s_node));
	node->value = arr[mid];
	node->left = create(arr, left, mid);
	node->right = create(arr, mid + 1, right);
	return node;
}

struct s_node *createBST(int *arr, int n)
{
	return create(arr, 0, n);
}
