struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int descendants(struct s_node *n, int node_count, int *split) {
	// base case
	if (n == 0) {
		return 0;
	}
	// step 1: get the nb of nodes from lchild, rchild
	int left = descendants(n->left, node_count, split);
	int right = descendants(n->right, node_count, split);

	// step 2: current level, check if it can split to half
	int sum = left + right + 1;
	if (*split == 0 && node_count - sum == sum) {
		*split = 1;
	}

	// step 3: return total node in this subtree
	return sum;
}

int can_split(struct s_node *n) {
	int split = 1;
	int node_count = 0;
	
	node_count = descendants(n, node_count, &split);
	if (node_count % 2 == 1) {
		return 0;
	}
	split = 0;
	descendants(n, node_count, &split);
	return split;
}

// time O(n)
// space O(height) -- worst O(n)

typedef struct s_node node;
#include <stdio.h>
void	trav(node *root)
{
	if (root)
	{
		trav(root->left);
		printf("%i\n", root->value);
		trav(root->right);
	}
}
int main()
{
	node	root1 = {
		.value = 28,
		.left = &(node){
			.value = 51,
			.left = &(node){
				.value = 26,
				.left = &(node){.value = 76},
				.right = &(node){.value = 13}
			},
			.right = &(node){.value = 48}
		}
	};
	node	root2 = {
		.value = 28,
		.left = &(node){
			.value = 51,
			.left = &(node){
				.value = 26,
				.left = &(node){.value = 76}
			},
			.right = &(node){.value = 48}
		}
	};
	// trav(&root1);
	printf("split %i\n", can_split(&root1));
	// trav(&root2);
	printf("split %i\n", can_split(&root2));
}
