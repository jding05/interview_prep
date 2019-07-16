struct s_node {
	int value;
	struct s_node **nodes;
};

int height_tree(struct s_node *root) {
	if (root == 0) {
		return 0;
	}
	int max = 0;
	while (*(root->nodes)) {
		int height = height_tree(*(root->nodes)) + 1;
		if (height > max) {
			max = height;
		}
		root->nodes++;
	}
	return max;
}

// time O(n) n is total # of nodes in the tree
// space O(height)

#include <stdlib.h>
struct s_node* b(int v) {
	struct s_node* new = malloc(sizeof(struct s_node));
	new->value = v;
	new->nodes = malloc(100000);
	return new;
}

#include <stdio.h>
int main() {

	struct s_node *r = b(94);
	r->nodes[0] = b(34);
	r->nodes[1] = b(52);

	r->nodes[0]->nodes[0] = b(1);
	r->nodes[0]->nodes[1] = b(99);
	r->nodes[0]->nodes[2] = b(11);

	r->nodes[0]->nodes[1]->nodes[0] = b(13);

	printf("%d\n", height_tree(r));

	return 0;
}