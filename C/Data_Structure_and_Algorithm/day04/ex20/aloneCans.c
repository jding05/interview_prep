#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "header.h"

void aloneCans(int *arr, int n)
{
	int n1 = 0;
	int n2 = 0;
	int	mask = 0;
	int right_most_set_bit;

	for (int i = 0; i < n; i++)
		mask ^= arr[i];
	right_most_set_bit = mask & ~(mask - 1);
	for (int i = 0; i < n; i++)
	{
		if (arr[i] & right_most_set_bit)
			n1 ^= arr[i];
		else
			n2 ^= arr[i];
	}
	printf("%d\n%d\n", n1, n2);
}
