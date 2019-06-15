#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include "header.h"

// radix sort - based on count sort
// binary search

int getDescription(struct s_info *info)
{
	return (info->gender * 1000000  + 
			info->height * 100000   + 
			info->hairColor * 10000 + 
			info->eyeColor * 1000   + 
			info->glasses * 100     + 
			info->tattoo * 10       + 
			info->piercing * 1
	);
}

void countSort(struct s_criminal **criminals, int n, int exp)
{
	struct s_criminal *output[n];
	int i = 0;
	int count[10] = {0};

	// store count of occurrences in cout[]
	for (int i = 0; i < n; i++)
		count[ (criminals[i]->description/exp) % 10 ]++;

	// change count[i] so that count[i] now 
	// contains actual position of this digit output (the index of position)
	for (i = 1; i < 10; i++)
		count[i] += count[i -1];

	// build the ouput array, put it backward
	for (i = n -1; i >= 0; i--)
	{
		output[count[ (criminals[i]->description / exp) % 10 ] -1 ] = criminals[i];
		count[(criminals[i]->description / exp ) % 10]--;
	}

	// copy output to ciriminals
	for (i = 0; i < n; i++)
		criminals[i] = output[i];
}

void sortCriminals(struct s_criminal **criminals)
{
	int len = 0;
	while (criminals[len])
		len++;
	// do counting sort for every digit
	for (int exp = 1; 10000000/exp > 0; exp *= 10)
		countSort(criminals, len, exp);
}

int	binarySearchFirst(struct s_criminal **criminals, int left, int right, int target)
{
	while (left < right -1)
	{
		int mid = left + (right - left)/2;
		if (criminals[mid]->description >= target)
			right = mid;
		else
			left = mid;
	}
	if (criminals[left]->description == target)
		return left;
	else if (criminals[right]->description == target)
		return right;
	else
		return -1;
}

struct s_criminal **findPotentialCriminals(struct s_criminal **criminals, struct s_info *info)
{
	// printf("hi");
	int description = getDescription(info);
	int len = 0;
	while (criminals[len])
		len++;
	int first = binarySearchFirst(criminals, 0, len -1, description);
	if (first == -1)
		return 0;
	int end = first;
	while (criminals[end]->description == description)
		end++;
	criminals[end] = 0;
	return (&criminals[first]);
}
