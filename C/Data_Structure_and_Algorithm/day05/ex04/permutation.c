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

void permutation(char *str, int index, int len)
{
	if (index == len)
	{
		printf("%s\n", str);
		return ;
	}
	for (int i = index; i < len; i++)
	{
		swap(str, i, index);
		permutation(str, index + 1, len);
		swap(str, i, index);
	}
}

void	printPermutations(char *str)
{
	char *copy = strdup(str);
	permutation(copy, 0, strlen(copy));
	free(copy);
}