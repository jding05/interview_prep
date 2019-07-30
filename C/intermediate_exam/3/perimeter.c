#include <stdio.h>

struct s_node {
	int value;
	struct s_node *right;
	struct s_node *left;
};

void printLeft(struct s_node *root) {
	printf(" %d", root->value);
	if (root->left) {
		printLeft(root->left);
	}
}

void printRight(struct s_node *root) {
	if (root->right) {
		printRight(root->right);
		printf(" %d", root->value);
	}
}

void printBottom(struct s_node *root) {
	if (root->left) {
		printBottom(root->left);
	}
	if (root->right) {
		printBottom(root->right);
	}
	if (!root->left && !root->right) {
		printf(" %d", root->value);
	}
}

void perimeter(struct s_node *root) {
	if (!root) {
		return ;
	} else {
		printf("%d", root->value);
	}
	if (root->left) {
		printLeft(root->left);
		printBottom(root->left);
	}
	if (root->right) {
		printBottom(root->right);
		printRight(root->right);
	}
	printf("\n");
}
// time O(n)
// space O(n)

/************
  Test Main
************/
#include <stdlib.h>
typedef struct s_node Node;

Node* b(int v) {
	Node* new = malloc(sizeof(Node));
	new->value = v;
	new->left = new->right = 0;
	return new;
}
int main() {

	Node* r = b(92);

	r->left = b(85);
	r->left->left = b(79);
	r->left->left->right = b(10);
	r->left->left->right->left = b(39);
	r->left->left->right->left->left = b(35);
	r->left->left->right->left->left->left = b(96);

	r->right = b(26);
	r->right->right = b(64);
	r->right->right->left = b(40);
	r->right->right->left->left = b(88);
	r->right->right->left->left->left = b(12);
	r->right->right->left->left->left->left = b(58);

	r->right->right->left->left->right = b(55);
	r->right->right->left->left->right->left = b(58);
	r->right->right->left->left->right->right = b(41);

	r->right->right->left->right = b(10);
	r->right->right->left->right->left = b(52);
	r->right->right->left->right->left->left = b(22);
	r->right->right->left->right->left->right = b(35);

	r->right->right->left->right->right = b(87);
	r->right->right->left->right->right->right = b(31);


	r->right->right->right = b(78);
	r->right->right->right->left = b(2);
	r->right->right->right->left->left = b(33);
	r->right->right->right->left->left->right = b(55);

	r->right->right->right->left->right = b(11);
	r->right->right->right->left->right->left = b(99);

	r->right->right->right->right = b(85);
	r->right->right->right->right->right = b(51);

	perimeter(r);
	return 0;
}