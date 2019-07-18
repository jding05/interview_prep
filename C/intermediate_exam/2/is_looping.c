struct s_node {
	int value;
	struct s_node *next;
};

int is_looping(struct s_node *node) {
	if (node == 0 || node->next == 0) {
		return 0;
	}
	struct s_node *fast = node;
	struct s_node *slow = node;
	while (fast->next && fast->next->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			return 1;
		}
	}
	return 0;
}

// time O(n)
// space O(1)