struct s_node {
	int value;
	struct s_node *right;
	struct s_node *left;
};

void reverse_tree(struct s_node *root) {
	if (!root) {
		return ;
	}
	struct s_node *tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	reverse_tree(root->left);
	reverse_tree(root->right);
}


#include <stdio.h>
int main(void)
{
	struct s_node a;
	a.value = 94;
	a.left = NULL;
	a.right = NULL;
	struct s_node b;
	b.value = 34;
	b.left = NULL;
	b.right = NULL;
	struct s_node c;
	c.value = 52;
	c.left = NULL;
	c.right = NULL;
	struct s_node d;
	d.value = 1;
	d.left = NULL;
	d.right = NULL;
	struct s_node e;
	e.value = 99;
	e.left = NULL;
	e.right = NULL;
	
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	printf("|%i|%i|\n", a.left->left->value, a.right->value);
	reverse_tree(&a);
	printf("|%i|%i|\n", a.right->right->value, a.left->value);
	return 0;
}