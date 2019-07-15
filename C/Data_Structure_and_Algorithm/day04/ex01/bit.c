#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "header.h"

char *handleNegation(char *a)
{
	if (a[0] == '~')
	{
		for (int i = 0; i < 4; i++)
			a[i] = a[i + 1] == '0' ? '1' : '0';
		a[4] = 0;
	}
	return a;
}

char *getAnd(char *a, char *b)
{
	a = handleNegation(a);
	b = handleNegation(b);
	for (int i = 0; i < 4; i++)
	{
		char A = a[i] - '0';
		char B = b[i] - '0';
		if (A & B)
			a[i] = '1';
		else
			a[i] = '0';
	}
	return a;
}

char *getOr(char *a, char *b)
{
	a = handleNegation(a);
	b = handleNegation(b);
	for (int i = 0; i < 4; i++)
	{
		char A = a[i] - '0';
		char B = b[i] - '0';
		if (A | B)
			a[i] = '1';
	}
	return a;
}

int toInt(char *bits)
{
	int ret = 0;
	for (int i = 0; i < 4; i++)
	{
		ret += bits[i] - '0';
		if (i != 3)
		{
			ret <<= 1;
		}
	}
	return ret;
}
