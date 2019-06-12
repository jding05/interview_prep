#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include "header.h"

/*
struct s_node {
	char	*name;
	struct s_node **children;
};
*/

// find common parent node from two random nodes

struct s_node **getpath(struct s_node *root, char* target)
{
	struct s_node **tmp;
	if (root == NULL)
		return NULL;
	if (!strcmp(root->name, target))
	{
		tmp = (struct s_node **)malloc(sizeof(struct s_node *) * 2);
		tmp[0] = root;
		tmp[1] = NULL;
		return tmp;
	}
	for (int i = 0; root->children[i]; i++)
	{
		if ((tmp = getpath(root->children[i], target)))
		{
			int len = 0;
			while (tmp[len])
				len++;
			tmp = (struct s_node **)realloc(tmp, sizeof(struct s_node *) * (len + 2));
			tmp[len] = root;
			tmp[len + 1] = NULL;
			return tmp;
		}
	}
	return NULL;
} 

struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies)
{
	struct s_node **p1 = getpath(root, firstSpecies);
	struct s_node **p2 = getpath(root, secondSpecies);
	struct s_node *res = NULL;

	if (p1 && p2)
	{
		int len1 = 0;
		while (p1[len1])
			len1++;
		int len1end = len1;
		int len2 = 0;
		while (p2[len2])
			len2++;
		while (len1 >= 0 && len2 >= 0 && p1[len1] == p2[len2])
		{
			len1--;
			len2--;
		}
		if (len1 < len1end)
			res = p1[len1 + 1];
	}
	if (p1)
		free(p1);
	if (p2)
		free(p2);
	return res;
}
