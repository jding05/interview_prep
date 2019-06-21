#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "header.h"

// recursive
int counts(int dist, int *locations, int index, int n)
{
	if (index >= n -1)
		return 0;
	int count = 0;
	for (int i = index; i < n -1; i++)
	{
		if (locations[i + 1] - locations[index] > dist)
			count++;
	}
	count+= counts(dist, locations, index + 1, n);
	return count;
}

double probaDistance(int dist, int *locations, int n)
{
	double count = (double)counts(dist, locations, 0, n);
	return count / (n * (n - 1) / 2);
}


// iterative
// double probaDistance(int dist, int *locations, int n)
// {
// 	double count = 0.0;
// 	for (int i = 0; i < n - 1; i++)
// 		for (int j = i + 1; j < n; j++)
// 			if (abs(locations[i] - locations[j]) > dist)
// 				count++;
// 	return count / (n * (n - 1) / 2);
// }
