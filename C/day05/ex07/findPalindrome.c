#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *isPalindrome(char *s)
{
	int i = 0;
	int j = strlen(s) - 1;

	while (i < j)
	{
		if (s[i++] != s[j--])
			return 0;
	}
	return s;
}

char *deleteCharAt(char *s, int index)
{
	int len = strlen(s);
	int j = 0;
	char *res = calloc(len, sizeof(char));
	for (int i = 0; i < len; i++)
	{
		if (i != index)
			res[j++] = s[i];
	}
	return res;
}

char *findPalindrome(char *sequence, int nDelete)
{
	char *res;

	if (!sequence)
		return 0;
	if (nDelete == 0)
		return isPalindrome(sequence);
	for (int i = 0; sequence[i]; i++)
	{
		char *tmp = deleteCharAt(sequence, i);
		if ((res = findPalindrome(tmp, nDelete - 1)))
			return res;
		free(tmp);
	}
	return 0;
}