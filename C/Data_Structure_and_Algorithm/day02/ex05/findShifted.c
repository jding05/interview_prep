#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include "header.h"

int search(int *rocks, int left, int right, int key)
{
	int mid = left + (right - left)/2;
	if (left > right)
		return (-1);
	// find the key
	else if (rocks[mid] == key)
	{
		if (rocks[mid] == rocks[right])
			return (right);
		else
			return (mid);
	}
	// left < mid
	else if (rocks[left] <= rocks[mid])
	{
		// left <= key < mid , search first half
		if (key >= rocks[left] && key < rocks[mid])
			return (search(rocks, left, mid, key));
		// search second half
		return (search(rocks, mid + 1, right, key));
	}
	else
	{
		// key in the second half
		if (key >= rocks[mid] && key <= rocks[right])
			return (search(rocks, mid + 1, right, key));
		// key in the first half
		return (search(rocks, left, mid, key));
	}
}

int	searchShifted(int *rocks, int length, int value)
{
	int res;
	res = search(rocks, 0, length -1, value);
	if (res < 0)
		return (res);
	while (res >= 0 && rocks[res] == value)
		res--;
	return (res + 1);
}