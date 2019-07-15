#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "header.h"

char *getXor(char *a, char *b)
{
	for (int i = 0; i < 6; i++)
	{
		if (a[i] == b[i])
			a[i] = '0';
		else
			a[i] = '1';
	}
	return a;
}

int toInt(char *bits)
{
	int sum = 0;
	for (int i = 0; bits[i]; i++)
	{
		sum += bits[i] - '0';
		if (i != 5)
			sum <<= 1;
	}
	return sum;
}
