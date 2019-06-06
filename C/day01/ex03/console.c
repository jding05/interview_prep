#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "header.h"
#define BUF_LEN 280
struct s_stack *stackInit(void)
{
	struct s_stack *head = (struct s_stack *)malloc(sizeof(struct s_stack));
	bzero(head, sizeof(struct s_stack));
	return (head);
}

int pop(struct s_stack *stack)
{
	if (!stack || !stack->item)
		return (-1);
	struct s_item	*tmp = stack->item;
	int idx = stack->item->idx;
	if (!stack->item->next)
		stack->item = 0;
	else
		stack->item = stack->item->next;
	free(tmp);
	return (idx);
}

void push(struct s_stack *stack, int idx)
{
	struct s_item *item = (struct s_item *)malloc(sizeof(struct s_item));
	bzero(item, sizeof(struct s_item));
	item->idx = idx;
	item->next = stack->item;
	stack->item = item;
}

char *console(void)
{
	char *buf = (char *)malloc(BUF_LEN);
	struct s_stack *stack = stackInit();
	char *line = 0;
	size_t len = 255;
	size_t msg_len;
	int ind = 0;
	int idx;

	while (1)
	{
		printf("🍬 ?> ");
		getline(&line, &len, stdin);
		msg_len = strlen(line);
		line[msg_len -1] = '\0';
		if (!strcmp("UNDO", line))
		{
			if (!stack->item)
				continue;
			idx = pop(stack);
			bzero(&buf[idx], BUF_LEN - idx);
			
			ind = idx;
		}
		else if (!strcmp("SEND", line))
		{
			while (stack->item)
				pop(stack);
			free(stack);
			return buf;
		}
		else
		{
			push(stack, ind);
			strcpy(&buf[stack->item->idx], line);
			ind += msg_len -1;
		}
		printf("%s\n", buf);
	}
}
