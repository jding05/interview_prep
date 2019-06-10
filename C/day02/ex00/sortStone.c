#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include "header.h"

void sortStones(struct s_stone **stone)
{
	struct s_stone *t = *stone;
	struct s_stone tmp;

	int count = 0;
	while (t)
	{
		count++;
		t = t->next;
	}
	struct s_stone *group = (struct s_stone *)malloc(sizeof(struct s_stone) * count);
	bzero(group, sizeof(struct s_stone) * count);
	t = *stone;
	int gid = 0;
	group[gid].size = t->size;
	group[gid].next = t;
	while (t)
	{
		if (t->size != group[gid].size)
		{
			gid++;
			group[gid].size = t->size;
			group[gid].next = t;
		}
		t = t->next;
	}
	for (int j = 0; j < gid; j++)
	{
		for (int i = 0; i < gid - j; i++)
		{
			if (group[i].size > group[i + 1].size)
			{
				tmp = group[i];
				group[i] = group[i +1];
				group[i + 1] = tmp;
			}
		}
	}
	*stone = group[0].next;
	t = *stone;
	for (int i = 0; i <= gid; i++)
	{
		while (t->next && t->size == t->next->size)
			t = t->next;
		t->next = NULL;
		if (i < gid)
		{
			t->next = group[i + 1].next;
			t = t->next;
		}
	}
	free(group);
}

// original bubble sort O(n^2)

// void sortStones(struct s_stone **stone)
// {
// 	struct s_stone *head = *stone;
// 	struct s_stone *cur = *stone;
// 	struct s_stone *prev = NULL;
// 	int count = 0;
// 	while (head)
// 	{
// 		head = head->next;
// 		count++;
// 	}
// 	for (int i = 0; i < count -1; i++)
// 	{
// 		for (int j = 0; j < count - i -1; j++)
// 		{
// 			cur = *stone;
// 			int start = 1;
// 			while (cur->next)
// 			{
// 				if (cur->size > cur->next->size)
// 				{
// 					if (start == 1)
// 					{
// 						*stone = cur->next;
// 						cur->next = cur->next->next;
// 						(*stone)->next = cur;
// 						cur = *stone;
// 					}
// 					else
// 					{
// 						prev->next = cur->next;
// 						cur->next = cur->next->next;
// 						prev->next->next = cur;
// 						cur = prev->next;
// 					}
// 				}
// 				prev = cur;
// 				cur = cur->next;
// 				start = 0;
// 			}
// 		}
// 	}
// }

