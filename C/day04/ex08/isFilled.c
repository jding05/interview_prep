#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "header.h"

int isFilled(unsigned int parkingRow)
{
	return !(parkingRow & (parkingRow + 1))
}