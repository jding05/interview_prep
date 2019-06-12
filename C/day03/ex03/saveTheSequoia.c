#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include "header.h"

// struct s_node {
// 	int value;
// 	struct s_node *right;
// 	struct s_node *left;
// };

// save the value of binary tree, make largest on top, lowest on bottom

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
