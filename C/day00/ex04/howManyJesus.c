#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "header.h"

/*
** Rabin-Karp algorithm
*/

int	hash(char *str, int size)
{
	int	value = 0;
	for (int i = 0; i < size; i++)
		value += str[i];
	return value;
}

int	howManyJesus(char *bible, char *jesus)
{
	int	count = 0;
	int	goalLen = (int)strlen(jesus);
	int	srcLen = (int)strlen(bible);
	int	goalHash = hash(jesus, goalLen);
	int	srcHash = hash(bible, goalLen);
	for (int i = 0; i < srcLen - goalLen; i++)
	{
		if (srcHash == goalHash && !strncmp(bible + i, jesus, goalLen))
			count++;
		srcHash -= bible[i];
		srcHash += bible[i + goalLen];
	}
	return count;
}