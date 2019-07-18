struct s_node {
	int value;
	struct s_node *left;
	struct s_node *right;
};

#define MAX(a,b) (a > b ? a : b)

int recur(struct s_node *root, int parentVal, int depth) {
	if (!root) {
		return depth;
	}
	if (parentVal + 1 != root->value) {
		depth = 0;
	}
	int left = recur(root->left, root->value, depth + 1);
	int right = recur(root->right, root->value, depth + 1);
	return MAX(MAX(left, right), depth);
}

int longest_sequence(struct s_node *node) {
	if (!node) {
		return 0;
	}
	int cur = 1;
	return MAX(MAX(recur(node->left, node->value, cur), recur(node->right, node->value, cur)), cur);
}
// time O(n)
// space O(height)


#include <stdlib.h>
#include <stdio.h>
struct s_node* b(int v) {
	struct s_node* new = malloc(sizeof(struct s_node));
	new->value = v;
	new->left = 0;
	new->right = 0;
	return new;
}
int main() {
	struct s_node* n = b(10);
	n->left = b(5);
	n->left->left = b(6);
	n->left->left->left = b(7);
	n->left->left->right = b(13);
	n->left->right = b(9);
	printf("%d\n", longest_sequence(n));

	struct s_node* m = b(5);
	m->left = b(6);
	m->right = b(4);
	m->right->left = b(9);
	m->right->left->left = b(3);
	m->right->left->right = b(2);
	m->right->right = b(3);
	m->right->right->right = b(2);
	printf("%d\n", longest_sequence(m));

	struct s_node* o = b(30);
	o->left = b(15);
	o->left->left = b(61);
	o->right = b(41);
	o->right->right = b(80);
	printf("%d\n", longest_sequence(o));

	printf("%d\n", longest_sequence(0));

	return 0; 
}