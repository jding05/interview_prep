#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include "header.h"

// divide and conquer
// split to smallest one element and compare

int findMin(int *ages, int left, int right)
{
	if (left == right)
		return (ages[left]);
	int mid = left + (right - left)/2;
	int leftm = findMin(ages, left, mid);
	int rightm = findMin(ages, mid + 1, right);
	return leftm > rightm ? rightm : leftm; 
}

void printYoungest(int *ages, int length)
{
	if (length < 1)
		printf("Wrong input\n");
	int n = findMin(ages, 0, length -1);
	printf("Youngest : %d\n", n);
}