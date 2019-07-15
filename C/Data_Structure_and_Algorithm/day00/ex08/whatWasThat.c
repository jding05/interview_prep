#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "header.h"


char    *delete(char *word, int pos)
{
	int len = strlen(word);
	if (pos >= len || pos < 0)
		return NULL;
	char *str = (char *)malloc(sizeof(char) * (len -1));
	strncpy(str, word, pos);
	strcpy(&str[pos], &word[pos + 1]);
	return str;
}

char    *replace(char *word, int pos, char c)
{
	int len = strlen(word);
	if (pos >= len || pos < 0)
		return NULL;
	char *str = strdup(word);
	str[pos] = c;
	return str;
	
}
char    *add(char *word, int pos, char c)
{
	int len = strlen(word);
	if (pos > len || pos < 0)
		return NULL;
	char *str = (char *)malloc(sizeof(char) * len + 1);
	strncpy(str, word, pos);
	str[pos] = c;
	strcpy(&str[pos + 1], &word[pos]);
	return str;
}

int findMin(int a, int b, int c)
{
	if (a < b)
		return a < c ? a : c;
	else
		return b < c ? b : c;
}

int countSteps(char *target, char *str)
{
	int tlen = strlen(target) + 1;
	int slen = strlen(str) + 1;
	int tab[slen][tlen];

	// iterate thru target len, and copy the index on first array
	for (int i = 0; i < tlen; i++)
		tab[0][i] = i;
	// iterate thru str len,
	for (int row = 1; row < slen; row++)
	{
		// assign index on every array first index;
		tab[row][0] = row;
		for (int col = 1; col < tlen; col++)
		{
			int min = findMin(tab[row][col - 1], tab[row - 1][col - 1], tab[row - 1][col]);
			if (target[col - 1] == str[row - 1])
				tab[row][col] = min;
			else
				tab[row][col] = min + 1;
		}
	}
	return tab[slen - 1][tlen - 1];
}

// 	target	str
// abcde  bcde
//     0 1 2 3 4 5 
// 0 [ 0 1 2 3 4 5 
// 1 [ 1 1 1 2 3 4 ]
// 2 [ 2 2 2 1 2 3 ]
// 3 [ 3 3 3 2 1 2 ]
// 4 [ 4 4 4 3 2 1 ]

// abcde abc
//     0 1 2 3 4 5   
// 0 [ 0 1 2 3 4 5]
// 1 [ 1 0 1 2 3 4]
// 2 [ 2 1 0 1 2 3]
// 3 [ 3 2 1 0 1 2]



char *whatWasThat(char *word, char **dict)
{
	int min = DEPTH + 1;
	char *ret;

	for (int i = 0; dict[i]; i++)
	{
		int t = countSteps(word, dict[i]);
		if (t < min)
		{
			min = t;
			ret = dict[i];
		}
	}
	return ret;
}
