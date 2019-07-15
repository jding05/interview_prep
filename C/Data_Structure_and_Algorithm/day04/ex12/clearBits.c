#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "header.h"

unsigned int clearBits(unsigned int parkingRow, int n)
{
	return parkingRow & ~((1 << n) -1);
}
