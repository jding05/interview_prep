#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "header.h"

void recursion(struct s_node *lst, int start)
{
	if (!lst)
		return ;
	recursion(lst->next, 0);
	if (start)
		printf("%s\n", lst->word);
	else
		printf("%s ", lst->word);
}

void printReverse(struct s_node *lst)
{
	recursion(lst, 1);
}
