#include <stdlib.h>

struct s_node {
	void *content;
	struct s_node *next;
};

struct s_node s_stack {
	struct s_node *top;
};

struct s_stack *init(void) {
	struct s_stack *stack = malloc(sizeof(struct s_stack));
	stack->top = 0;
	return stack;
}

void *pop(struct s_stack *stack) {
	if (!stack->top) {
		return 0;
	}
	struct s_node *node = stack->top;
	void *content = node->content;
	stack->top = node->next;
	free(node);
	return content;
}

void push(struct s_stack *stack, void *content) {
	struct s_node *node = malloc(sizeof(struct s_node));
	node->content = content;
	node->next = stack->top;
	stack->top = node;
}

void *peek(struct s_stack *stack) {
	if (!stack->top) {
		return 0;
	}
	return stack->top->content;
}

int isEmpty(struct s_stack *stack) {
	if (!stack->top) {
		return 1;
	}
	return 0;
}
