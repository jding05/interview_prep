#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "header.h"

struct s_stack *stackInit(void)
{
	struct s_stack *head = (struct s_stack *)malloc(sizeof(struct s_stack));
	bzero(head, sizeof(struct s_stack));
	return (head);
}

void *pop(struct s_stack *stack)
{
	if (!stack || !stack->item)
		return (0);
	struct s_item	*tmp = stack->item;
	void	*word = stack->item->word;
	stack->item = stack->item->next;
	free(tmp);
	return (word);
}

void push(struct s_stack *stack, char *word)
{
	struct s_item *item = (struct s_item *)malloc(sizeof(struct s_item));
	bzero(item, sizeof(struct s_item));
	item->word = word;
	item->next = stack->item;
	stack->item = item;
}

void printReverseV2(struct s_node *lst)
{
	struct s_stack *stack = stackInit();
	while (lst)
	{
		push(stack, lst->word);
		lst = lst->next;
	}
	while (stack->item->next)
	{
		printf("%s ", stack->item->word);
		pop(stack);
	}
	printf("%s\n", stack->item->word);
	pop(stack);
}
