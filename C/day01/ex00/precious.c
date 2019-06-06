#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "header.h"

static struct s_node	*create_machine(void)
{
	char *str = CS;
	int sl = (int)strlen(str);
	struct s_node *t = 0;
	struct s_node *node = (struct s_node *)malloc(sizeof(struct s_node));
	bzero(node, sizeof(struct s_node));
	node->c = str[0];
	for (int i = 1; i < sl; i++)
	{
		t = (struct s_node *)malloc(sizeof(struct s_node));
		t->c = str[i];
		node->next = t;
		t->prev = node;
		node = t;
	}
	while (t->prev)
		t = t->prev;
	node->next = t;
	t->prev = node;
	node = t;
	return (node);
}

static void				destroy_machine(struct s_node *head)
{
	struct s_node *last = head->prev;
	struct s_node *next;
	while (head != last)
	{
		next = head->next;
		free(head);
		head = next;
	}
	free(head);
}

char					*precious(int *text, int size)
{
	char 			*res = (char *)malloc(sizeof(char) * size + 1);
	struct s_node	*node = create_machine();
	int 			i;
	for (i = 0; i < size; i++)
	{
		if (text[i] >= 0)
		{
			for (int j = 0; j < text[i]; j++)
				node = node->next;
		}
		else
		{
			for (int j = 0; j > text[i]; j--)
				node = node->prev;
		}
		res[i] = node->c;
	}
	res[i] = 0;
	destroy_machine(node);
	return (res);
}
