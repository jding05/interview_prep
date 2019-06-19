#include "header.h"
#include <stdio.h>
#include <stdlib.h>

// DFS

void dfs(int target, struct s_array *arr)
{
	if (target == 0)
	{
		arrayPrint(arr);
		free(arr->content);
		free(arr);
		return ;
	}
	for (int i = target; i > 0; i--)
	{
		struct s_array *clone = arrayClone(arr);
		arrayAppend(clone, i);
		dfs(target - i, clone);
	}
	free(arr->content);
	free(arr);
}

void printPossibleSlices(int pizzaSize)
{
	struct s_array *arr = arrayInit();
	dfs(pizzaSize, arr);
}