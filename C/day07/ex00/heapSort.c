#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "header.h"

void swap(struct s_art **masterpiece, int left, int right)
{
	struct s_art *tmp = masterpiece[left];
	masterpiece[left] = masterpiece[right];
	masterpiece[right] = tmp;
}

void percolateDown(struct s_art **masterpiece, int i, int size)
{
	while (i < size / 2 - 1)
	{
		int leftChild = 2 * i + 1;
		int rightChild = 2 * i + 2;
		int swapCandidate = leftChild;

		if (rightChild < size && strcmp(masterpiece[leftChild]->name, masterpiece[rightChild]->name) < 0)
			swapCandidate = rightChild;
		if (strcmp(masterpiece[i]->name, masterpiece[swapCandidate]->name) < 0)
			swap(masterpiece, i, swapCandidate);
		else
			break;
		i = swapCandidate;
	}
}

// percolate down from the last parent node
void heapify(struct s_art **masterpiece, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		percolateDown(masterpiece, i, n);
}

void heapSort(struct s_art **masterpiece, int n)
{
	heapify(masterpiece, n);
	for (int i = n -1; i >= 0; i--)
	{
		swap(masterpiece, 0, i);
		percolateDown(masterpiece, 0, i);
	}
}