#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "header.h"

// struct s_node {
// 	int value;
// 	struct s_node *right;
// 	struct s_node *left;
// };

// int getHeight(struct s_node *root)
// {
// 	if (root == NULL)
// 		return (0);
// 	return (fmax(getHeight(root->left), getHeight(root->right)) + 1);
// }

// int countNodes(struct s_node *root)
// {
// 	if (root == NULL)
// 		return (0);
// 	else 
// 		return (countNodes(root->left) + countNodes(root->right) + 1);
// }

// void add_to_arr(struct s_node **arr, struct s_node *root, int level, int *isRoot)
// {
// 	if (level == 0)
// 	{
// 		arr[*isRoot] = root;
// 		(*isRoot)++;
// 	}
// 	else
// 	{
// 		add_to_arr(arr, root->right, level - 1, isRoot);
// 		add_to_arr(arr, root->left, level - 1, isRoot);
// 	}
// }

// struct s_node **to_arr(struct s_node *root, int size)
// {
// 	int isRoot = 0;
// 	int height = getHeight(root);
// 	struct s_node **arr = (struct s_node**)malloc(sizeof(struct s_node*) * (size + 1));
// 	for (int i = 0; i < height; i++)
// 		add_to_arr(arr, root, i, &isRoot);
// 	return (arr);
// }

// void climbing_up(struct s_node **arr, int parent_ind, int size)
// {
// 	struct s_node *tmp;
// 	int li;
// 	int ri;
// 	int largest;

// 	while (2 * parent_ind + 1 < size)
// 	{
// 		ri = 2 * parent_ind + 1;
// 		li = 2 * parent_ind + 2;
// 		if (ri >= size && li >= size)
// 			break;
// 		else if (ri >= size)
// 			largest = li;
// 		else if (li >= size)
// 			largest = ri;
// 		else
// 			largest = arr[li]->value > arr[ri]->value ? li : ri;
// 		if (arr[parent_ind]->value < arr[largest]->value)
// 		{
// 			tmp = arr[parent_ind];
// 			arr[parent_ind] = arr[largest];
// 			arr[largest] = tmp;
// 			parent_ind = largest;
// 		}
// 		else
// 			break;
// 	}
// }

// void insertMonkey(struct s_node **root, struct s_node *monkey)
// {
// 	struct s_node **arr;
// 	int size;
// 	int parent_index;
// 	int li;
// 	int ri;

// 	size = countNodes(*root);
// 	arr = to_arr(*root, size);
// 	arr[size] = monkey;
// 	size++;
// 	parent_index = (size - 2) / 2;
// 	for (int i = size - 1; i >= 0; i--)
// 		climbing_up(arr, i, size);
// 	for (int i = 0; i < size; i++)
// 	{
// 		ri = 2 * i + 1;
// 		li = 2 * i + 2;
// 		arr[i]->left = li >= size ? NULL : arr[li];
// 		arr[i]->right = ri >= size ? NULL : arr[ri];
// 	}
// 	*root = arr[0];
// }

// int	getHeight(struct s_node *root)
// {
// 	if (root == NULL)
// 		return (0);
// 	else 
// 		return(fmax(getHeight(root->left), getHeight(root->right)) + 1);
// }

unsigned int countNodes(struct s_node *root)
{
	if (root == NULL)
		return (0);
	else
		return (countNodes(root->left) + 1 + countNodes(root->right));
}

// void	add_to_arr(struct s_node **arr, struct s_node *root, int level, int *i)
// {
// 	if (level == 0)
// 	{
// 		arr[*i] = root;
// 		(*i)++;
// 	}
// 	else
// 	{
// 		add_to_arr(arr, root->right, level - 1, i);
// 		add_to_arr(arr, root->left, level - 1, i);
// 	}
// }


// struct s_node **to_arr(struct s_node *root, int size)
// {
// 	int i;
// 	int h;
// 	struct s_node **arr;

// 	h = getHeight(root);
// 	i = 0;
// 	arr = (struct s_node**)malloc(sizeof(struct s_node*) * (size + 1));
// 	for (int j = 0; j < h; j++)
// 		add_to_arr(arr, root, j, &i);
// 	return (arr);
// }





// void	percolate_up(struct s_node **arr, int i, int size)
// {
// 	struct s_node *tmp;
// 	int li;
// 	int ri;
// 	int largest;

// 	while (2 * i + 1 < size)
// 	{
// 		ri = 2 * i + 1;
// 		li = 2 * i + 2;
// 		if (ri >= size && li >= size)
// 			break ;
// 		else if (ri >= size)
// 			largest = li;
// 		else if (li >= size)
// 			largest = ri;
// 		else
// 			largest = (arr[li]->value > arr[ri]->value ? li : ri);
// 		if (arr[i]->value < arr[largest]->value)
// 		{
// 			tmp = arr[i];
// 			arr[i] = arr[largest];
// 			arr[largest] = tmp;
// 			i = largest;
// 		}
// 		else
// 			break ;
// 	}
// }


// void insertMonkey(struct s_node **root, struct s_node *monkey)
// {
// 	struct s_node **arr;
// 	int size;
// 	int	monkey_parent_i;
// 	int lj;
// 	int rj;

// 	size = countNodes(*root);
// 	arr = to_arr(*root, size);
// 	arr[size] = monkey;
// 	size += 1;
// 	monkey_parent_i = (size - 2) / 2;
// 	for (int i = size - 1; i >= 0; i--)
// 		percolate_up(arr, i, size);
// 	for (int j = 0; j < size; j++)
// 	{
// 		rj = 2 * j + 1;
// 		lj = 2 * j + 2;
// 		arr[j]->left = (lj >= size ? NULL : arr[lj]);
// 		arr[j]->right = (rj >= size ? NULL : arr[rj]);
// 	}
// 	*root = arr[0];
// }





struct s_node *swap(struct s_node **root, struct s_node **parent, struct s_node *cur, struct s_node *child)
{
	struct s_node *p = *parent;
	if (p)
	{
		if (p->left == cur) // swap cur with larger right child
			p->left = child;
		else
			p->right = child;
	}
	else
		*root = child;
	if (cur->left == child)
	{
		cur->left = child->left; // swap cur and left
		child->left = cur;
		struct s_node *tmp = cur->right;
		cur->right = child->right;
		child->right = tmp;
	}
	else
	{
		cur->right = child->right;
		child->right = cur;
		struct s_node *tmp = cur->left;
		cur->left = child->left;
		child->left = tmp;
	}
	*parent = child;
	return cur; // going down
}

void maxHeapSwitch(struct s_node **root, struct s_node *parent, struct s_node *cur)
{
	if (cur->left)
		maxHeapSwitch(root, cur, cur->left);
	if (cur->right)
		maxHeapSwitch(root, cur, cur->right);
	struct s_node *tmp = cur;
	while (tmp && (tmp->right || tmp->left)
		&& ((tmp->right && tmp->value < tmp->right->value)
		|| ((tmp->left && tmp->value > tmp->left->value))))
	{
		struct s_node *t;
		if (!tmp->right || !tmp->left)
			t = (tmp->left ? tmp->left : tmp->right);
		else
			t = (tmp->right->value > tmp->left->value ? tmp->right : tmp->left);
		tmp = swap(root, &parent, tmp, t);
	}
}

void	saveTheSequoia(struct s_node **root)
{
	if (!root || !(*root) || (!(*root)->left && !(*root)->right))
		return ;
	maxHeapSwitch(root, NULL, *root);
}

void insertMonkey(struct s_node **root, struct s_node *monkey)
{
	if (!*root)
	{
		*root = monkey;
		return ;
	}
	struct s_node *tmp = *root;
	unsigned int elem = countNodes(*root) + 1; // 7 -> 8 1000
	unsigned int set = elem & 1; // 0 
	elem = elem >> 1; // 100
	while (elem > 1) {
		if (elem & 1) // 0 //0
			tmp = tmp->right;
		else
			tmp = tmp->left;
		elem = elem >> 1;
	}
	if (set)
		tmp->right = monkey;
	else
		tmp->left = monkey;
	saveTheSequoia(root);
}