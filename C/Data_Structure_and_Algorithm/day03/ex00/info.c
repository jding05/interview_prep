#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <math.h>

#include "header.h"
/*
struct s_node {
	int value;
	struct s_node *right;
	struct s_node *left;
};

struct s_info {
	int min;        // the minimum value in the tree
	int max;        // the max value in the tree
	int elements;   // the number of nodes in the tree
	int height;     // the height of the tree
	int isBST;      // 0 = FALSE, 1 = TRUE
	int isBalanced; // 0 = FALSE, 1 = TRUE
};
*/

int findMin(struct s_node *root)
{
	if (root == NULL)
		return (INT_MAX);
	return (fmin(root->value, fmin(findMin(root->left), findMin(root->right))));
}

int findMax(struct s_node *root)
{
	if (root == NULL)
		return (INT_MIN);
	return (fmax(root->value, fmax(findMax(root->left), findMax(root->right))));

}

int countNodes(struct s_node *root)
{
	if (root == NULL)
		return 0;
	return (countNodes(root->left) + countNodes(root->right) + 1);
}

int findHeight(struct s_node *root)
{
	if (root == NULL)
		return (0);
	int leftHeight = findHeight(root->left);
	int rightHeight = findHeight(root->right);
	return ((leftHeight > rightHeight ? leftHeight : rightHeight) + 1);
}

int checkBST(struct s_node *root, int min, int max)
{
	if (root == NULL)
		return 1;
	if (root->value < min || root->value > max)
		return 0;
	return (checkBST(root->left, min, root->value -1) &&
			checkBST(root->right, root->value + 1, max));
}

int isBST(struct s_node *root)
{
	if (root == NULL)
		return 1;
	return (checkBST(root, INT_MIN, INT_MAX));
}

int findBalanceHeight(struct s_node *root)
{
	if (root == NULL)
		return (0);
	int leftHeight = findHeight(root->left);
	if (leftHeight == -1)
		return -1;
	int rightHeight = findHeight(root->right);
	if (rightHeight == -1)
		return -1;
	if (abs(rightHeight - leftHeight) > 1)
		return (-1);
	return ((leftHeight > rightHeight ? leftHeight : rightHeight) + 1);
}

int isBalanced(struct s_node *root)
{
	return (findBalanceHeight(root) != -1 ? 1 : 0);
}

struct s_info   getInfo(struct s_node *root)
{
	struct s_info info;
	
	if (root == 0)
	{
		info.elements = 0;
		return info;
	}
	info.min = findMin(root);
	info.max = findMax(root);
	info.elements = countNodes(root);
	info.height = findHeight(root);
	info.isBST = isBST(root);
	info.isBalanced = isBalanced(root);
	return (info);
}
