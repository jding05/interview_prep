#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "header.h"

struct s_queue *queueInit(void)
{
	struct s_queue *queue = (struct s_queue *)malloc(sizeof(struct s_queue));
	queue->first = 0;
	queue->last = 0;
	return queue;
}

char *dequeue(struct s_queue *queue)
{
	if (queue == 0 || queue->first == 0)
		return 0;
	struct s_node *node = queue->first;
	char *msg = node->message;
	queue->first = queue->first->next;
	free(node);
	return msg;
}

void enqueue(struct s_queue *queue, char *message)
{
	struct s_node *node = (struct s_node *)malloc(sizeof(struct s_node));
	if (node == 0)
		return ;
	node->message = message;
	node->next = 0;
	if (queue->first == 0)
		queue->first = node;
	if (queue->last != 0)
		queue->last->next = node;
	queue->last = node;
}

char *peek(struct s_queue *queue)
{
	if (queue == 0 || queue->first == 0)
		return 0;
	return queue->first->message;
}

int isEmpty(struct s_queue *queue)
{
	return queue->first == 0;
}
