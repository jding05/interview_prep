#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "header.h"

int rightmostCar(unsigned int parkingRow)
{
	int pos = -1;
	while (parkingRow)
	{
		pos++;
		if (parkingRow & 1)
			break;
		parkingRow >>= 1;
	}
	return pos;
}
