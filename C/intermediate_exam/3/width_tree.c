struct s_node {
	int value;
	struct s_node *left;
	struct s_node *right;
};

int max(int left, int right) {
	return left >= right ? left : right;
}

int width_tree(struct s_node *n) {
	int w = 0;
	get_width(n, &w);
	return w;
}

int get_width(struct s_node *n, int *w) {
	if (n == 0) {
		return 0;
	}
	int left = get_width(n->left, w);
	int right = get_width(n->right, w);
	if (n->left != 0 && n->right != 0) {
		int sum = left + right + 1;
		*w = max(*w, sum);
	}
	return max(left, right) + 1;
}

// time O(n)
// space O(height) , worst O(n)