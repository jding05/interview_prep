#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "header.h"

int carPosition(unsigned int parkingRow)
{
	int pos = -1;
	if (!parkingRow || (parkingRow & parkingRow -1))
		return -1;
	while (parkingRow)
	{
		parkingRow >>= 1;
		pos++;
	}
	return pos;
}
