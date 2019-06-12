#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include "header.h"

/*
struct s_node {
	int value;
	struct s_node *right;
	struct s_node *left;
};
*/

// creating BST from sorted array
/*
3 steps:
1.) get the mid node and make it as root
2.) recursively do same for left half and right half
	a. get left to mid -1 as root->left;
	b. get mid + 1 to right as root->right
*/

struct s_node *creatingBST(int *arr, int left, int right)
{
	if (left > right)
		return NULL;
	int mid = left + (right - left)/2;
	struct s_node *root = (struct s_node *)malloc(sizeof(struct s_node));
	bzero(root, sizeof(struct s_node));
	root->value = arr[mid];
	root->left = creatingBST(arr, left, mid -1);
	root->right = creatingBST(arr, mid +1, right);
	return (root);
}

struct s_node *createBST(int *arr, int n)
{
	return creatingBST(arr, 0, n -1);
}
