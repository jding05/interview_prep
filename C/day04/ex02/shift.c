#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "header.h"

char *rightShift(char *bin, int k)
{
	if (bin[0] == '0')
	{
		memcpy(&bin[1 + k], &bin[1], 5 - k);
		for (int i = 1; i <= k; i++)
			bin[i] = '0';
	}
	else
	{
		memcpy(&bin[1 + k], &bin[1], 5 - k);
		for (int i = 1; i <= k; i++)
			bin[i] = '1';
	}
	return bin;
}

char *leftShift(char *bin, int k)
{
	if (bin[0] == '0')
	{
		memcpy(&bin[1], &bin[1 + k], 5 - k);
		for (int i = 6 - k; i < 6; i++)
			bin[i] = '0';
	}
	else
	{
		memcpy(&bin[1], &bin[1 + k], 5 - k);
		for (int i = 6 - k; i < 6; i++)
			bin[i] = '1';
	}
	return bin;
}

int toInt(char *bits)
{
	int res = 0;
	int sign = bits[0] == '0' ? 1 : -1;
	for (int i = 1; i < 6; i++)
	{
		res += (sign == 1 ? bits[i] - '0' :  1 - (bits[i] - '0'));
		if (i != 5)
			res <<= 1;
	}
	res *= sign;
	if (sign == -1)
		res -= 1;
	return res;
}

