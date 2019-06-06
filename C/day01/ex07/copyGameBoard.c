#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "header.h"

// copy the node value

struct s_node *cloneGameBoard(struct s_node *node)
{
	if (!node)
		return NULL;
	struct s_node *head = (struct s_node *)malloc(sizeof(struct s_node));
	struct s_node *cur = head;
	struct s_node *n = node;
	cur->value = n->value;
	node = n->next;
	n = n->next;
	while (n) {
		struct s_node *tmp = (struct s_node *)malloc(sizeof(struct s_node));
		tmp->value = n->value;
		tmp->random = NULL;
		cur->next = tmp;
		cur = cur->next;
		n = n->next;
	}
	n = node;
	cur = head;
	while (n)
	{
		if (n->random)
		{
			struct s_node *n2 = node;
			struct s_node *cur2 = head;
			while  (n2 && n->random != n2)
			{
				n2 = n2->next;
				cur2 = cur2->next;
			}
			cur->random = cur2;
		}
		cur = cur->next;
		n = n->next;
	}
	return head;
}
