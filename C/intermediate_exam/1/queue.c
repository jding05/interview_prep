#include <stdlib.h>

struct s_node {
	void *content;
	struct s_node *next;
};

struct s_queue {
	struct s_node *first;
	struct s_node *last;
};

struct s_queue *init(void) {
	struct s_queue *queue = malloc(sizeof(struct s_queue));
	queue->first = 0;
	queue->last = 0;
	return queue;
}

void enqueue(struct s_queue *queue, void *content) {
	struct s_node *node = malloc(sizeof(struct s_node));
	node->content = content;
	node->next = 0;
	if (queue->last) {
		queue->last->next = node;
	}
	if (!queue->first) {
		queue->first = node;
	}
	queue->last = node;
}

void *dequeue(struct s_queue *queue) {
	if (!queue || !queue->first) {
		return 0;
	}
	struct s_node *node = queue->first;
	void *content = node->content;
	queue->first = queue->first->next;
	if (!queue->first) { // important step
		queue->last = 0;
	}
	free(ndoe);
	return content;
}

void *peek(struct s_queue *queue) {
	if (!queue || !queue->first) {
		return 0;
	}
	return queue->first->content;
}

int isEmpty(struct s_queue *queue) {
	if (!queue || !queue->first) {
		return 1;
	}
	return 0;
}