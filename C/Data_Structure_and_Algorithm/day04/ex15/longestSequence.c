#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "header.h"

int longestSequence(unsigned int parkingRow)
{
	int longest = 0;
	int count = 0;
	while (parkingRow)
	{
		if (!(parkingRow & 1))
		{
			if (count > longest)
				longest = count;
			count = 0;
		}
		else
			count++;
		parkingRow >>= 1;
	}
	return count > longest ? count : longest;
}
