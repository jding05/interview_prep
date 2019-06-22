#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#include "header.h"

struct s_deque *dequeInit(void)
{
	struct s_deque *deque = calloc(1, sizeof(struct s_deque));
	return deque;
}

void pushFront(struct s_deque *deque, int value)
{
	struct s_dequeNode *tmp = calloc(1, sizeof(struct s_dequeNode));
	tmp->value = value;
	if (deque->first)
	{
		deque->first->prev = tmp;
		tmp->next = deque->first;
	}
	else
		deque->last = tmp;
	deque->first = tmp;
}

void pushBack(struct s_deque *deque, int value)
{
	struct s_dequeNode *tmp = calloc(1, sizeof(struct s_dequeNode));
	tmp->value = value;
	if (deque->last)
	{
		deque->last->next = tmp;
		tmp->prev = deque->last;
	}
	else
		deque->first = tmp;
	deque->last = tmp;
}

int popFront(struct s_deque *deque)
{
	if (!deque->first)
		return INT_MIN;
	struct s_dequeNode *tmp = deque->first;
	int value = tmp->value;
	deque->first = deque->first->next;
	if (deque->first)
		deque->first->prev = NULL;
	return value;
}

int popBack(struct s_deque *deque)
{
	if (!deque->last)
		return INT_MIN;
	struct s_dequeNode *tmp = deque->last;
	int value = tmp->value;
	deque->last = deque->last->prev;
	if (deque->last)
		deque->last->next = NULL;
	return value;
}

int isEmpty(struct s_deque *deque)
{
	if (!deque)
		return 1;
	if (!deque->first)
		return 1;
	return 0;
}

struct s_max *maxSlidingWindow(int *arr, int n, int k)
{
	if (k < 1 || k > n)
		return NULL;
	struct s_max *res = calloc(1, sizeof(struct s_max));
	res->length = n - k + 1;
	res->max = calloc(n - k + 1, sizeof(int));
	struct s_deque *deque = dequeInit();
	for (int i = 0; i < k; i++)
	{
		while (deque->last && arr[deque->last->value] <= arr[i])
			popBack(deque);
		pushBack(deque, i);
	}
	for (int i = k; i <= n; i++)
	{
		if (deque->first)
			res->max[i - k] = arr[deque->first->value];
		if (deque->first && deque->first->value <= i - k)
			popFront(deque);
		while (deque->last && arr[deque->last->value] <= arr[i])
			popBack(deque);
		pushBack(deque, i);
	}
	return res;
}