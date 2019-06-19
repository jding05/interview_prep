#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *str, int left, int right)
{
	char tmp = str[left];
	str[left] = str[right];
	str[right] = tmp;
}

void	permutation(char *str, int index, int len, struct s_dict *dict)
{
	if (index == len && dictSearch(dict, str) == -1)
	{
		dictInsert(dict, str, 1);
		printf("%s\n", str);
	}
	for (int i = index; i < len; i++)
	{
		swap(str, index, i);
		permutation(str, index + 1, len, dict);
		swap(str, index, i);
	}
}

void	printUniquePermutations(char *str)
{
	if (!str)
		return ;
	struct s_dict *dict = dictInit(strlen(str));
	char *copy = strdup(str);
	permutation(copy, 0, strlen(copy), dict);
	free(copy);
}