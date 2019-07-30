struct s_node {
	int value;
	struct s_node *right;
	struct s_node *left;
};

void convert_subtree(struct s_node *root, struct s_node **prev) {
	if (!root) {
		return ;
	}
	convert_subtree(root->left, prev);
	if (*prev) {
		(*prev)->right = root;
		root->left = *prev;
	}
	*prev = root;
	convert_subtree(root->right, prev);
}

struct s_node *bst_leftmost(struct s_node *root) {
	while (root->left) {
		root = root->left;
	}
	return root;
}

struct s_node *bst_rightmost(struct s_node *root) {
	while (root->right) {
		root = root->right;
	}
	return root;
}

struct s_node *convert_bst(struct s_node *bst) {
	if (bst == 0) {
		return bst;
	}
	struct s_node *prev = 0;
	convert_subtree(bst, &prev);
	struct s_node *min = bst_leftmost(bst);
	struct s_node *max = bst_rightmost(bst);
	min->left = max;
	max->right = min;
	return min;
}
// time O(n)
// space O(n)


// 123 4 567

//     4 
//  2 .    6
// 1 . 3  5  7


/******************
    TEST MAIN
******************/

#include <stdlib.h>
#include <stdio.h>
struct s_node *new(int d)
{
	struct s_node *n =(struct s_node *)malloc(sizeof(struct s_node));
	n->value =d;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void p(struct s_node *r)
{
	if(!r)
		return ;
	p(r->left);
	printf("%d\n", r->value);
	p(r->right);
}
int main()
{
	struct s_node *a = new(12);
	a->left = new(6);
	a->left->left = new(3);
	a->left->right = new(9);

	a->right = new(18);
	a->right->right = new(20);
	a->right->left = new(15);
	struct s_node *c = a;
	p(c);
	printf("-----------------------------\ncir Doub linklist: \n");
	struct s_node *r = convert_bst(a);
	int i = 0;
	while (i++ < 15)
	{
		printf("%d\n", r->value);
		r = r->right;
	}
}