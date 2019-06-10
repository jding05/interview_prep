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


















// typedef struct s_criminal t_criminal;
// typedef struct s_info t_info;

// int g_size;

// int power(int n, int p)
// {
// 	int ret = 1;

// 	while (p)
// 	{
// 		ret *= n;
// 		p--;
// 	}
// 	return (ret);
// }

// int getDescription(t_info *info)
// {
// 	int sum = 0;
// 	sum += info->gender;
// 	sum *= 10;
// 	sum += info->height;
// 	sum *= 10;
// 	sum += info->hairColor;
// 	sum *= 10;
// 	sum += info->eyeColor;
// 	sum *= 10;
// 	sum += info->glasses;
// 	sum *= 10;
// 	sum += info->tattoo;
// 	sum *= 10;
// 	sum	+= info->piercing;
// 	return (sum);
// }

// void sortFeature(t_criminal **criminals, int i)
// {
// 	t_criminal **arr[10];
// 	int count[10];
// 	int j;

// 	bzero(count, sizeof(int) * 10);
// 	if (i < 0 || i > 6)
// 		return ;
// 	for (int j = 0; j < 10; j++)
// 		arr[j] = malloc(sizeof(t_criminal*));
// 	for (j = 0; criminals[j]; j++)
// 	{
// 		int t = (criminals[j]->description / power(10, i)) % 10;
// 		arr[t] = realloc(arr[t], sizeof(t_criminal*) * (count[t] + 1));
// 		arr[t][count[t]] = criminals[j];
// 		count[t]++;
// 	}
// 	g_size = j;
// 	int pos = 0;
// 	for (int j = 0; j < 10; j++)
// 		for (int k = 0; k < count[j]; k++)
// 		{
// 			criminals[pos] = arr[j][k];
// 			pos++;
// 		}
// 	for (int j = 0; j < 10; j++)
// 		free(arr[j]);
// }

// void sortCriminals(t_criminal **criminals)
// {
// 	for (int i = 0; i < 7; i++)
// 		sortFeature(criminals, i);
// }

// int find_recur(t_criminal **criminals, int size, int n)
// {
// 	if (size < 1)
// 		return (-1);
// 	if (size == 1)
// 		return (criminals[0]->description == n ? 0 : -1);
// 	int m = size / 2;
// 	if (criminals[m]->description == n)
// 		return (m);
// 	if (criminals[m]->description > n)
// 		return (find_recur(criminals, m, n));
// 	return (m + find_recur(&criminals[m], size - m, n));
// }

// t_criminal **findPotentialCriminals(t_criminal **criminals, t_info *info)
// {
// 	int n = getDescription(info);
// 	int p = find_recur(criminals, g_size, n);
// 	if (p == -1)
// 		return NULL;
// 	int l = p;
// 	while (l >= 0 && criminals[l]->description == n)
// 		l--;
// 	l++;
// 	int r = p;
// 	while (criminals[r] && criminals[r]->description == n)
// 		r++;
// 	r--;
// 	t_criminal **ret = malloc(sizeof(t_criminal*) * (r - l + 2));
// 	int i = 0;
// 	while (l <= r)
// 	{
// 		ret[i] = criminals[l];
// 		i++;
// 		l++;
// 	}
// 	ret[i] = NULL;
// 	return (ret);
// }
