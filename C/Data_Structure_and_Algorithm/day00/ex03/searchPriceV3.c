#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "header.h"

struct	s_dict *dictInit(int capacity)
{
	struct s_dict *dict;

	dict = (struct s_dict *)malloc(sizeof(struct s_dict) * capacity);
	dict->capacity = capacity;
	dict->items = (struct s_item**)malloc(sizeof(struct s_item*) * capacity);
	bzero(dict->items, sizeof(struct s_items*) * capacity); 
	return (dict);
}

size_t			hash(char *input)
{
	size_t	res = strlen(input);
	for (unsigned int i = 0; i < strlen(input) && i < 16; i++)
	{
		res <<= 4;
		res += (unsigned char)input[i];
	}
	return (res);
}

/*
** add one element in the dictionnary, if FAIL return 0, otherwise 1
*/

int				dictInsert(struct s_dict *dict, char *key, struct s_art *value)
{
	int k = hash(key) % dict->capacity;
	struct s_item *node = (struct s_item*)malloc(sizeof(struct s_item));
	if (!node)
		return (0);
	node->key = key;
	node->value = value;
	node->next = NULL;
	if (!dict->items[k])
		dict->items[k] = node;
	else
	{
		struct s_item *cur = dict->items[k];
		while (cur && cur->next)
			cur = cur->next;
		cur->next = node;
	}
	return (1);
}

/*
** find one element in the dictionnary, if not found, return NULL
*/

struct s_art	*dictSearch(struct s_dict *dict, char *key)
{
	size_t k = hash(key) % dict->capacity;
	if (!dict->items[k])
		return NULL;
	struct s_item *cur = dict->items[k];
	while (cur)
	{
		if (!strcmp(cur->key, key))
			return cur->value;
		cur = cur->next;
	}
	return NULL;
}

int				searchPrice(struct s_dict *dict, char *name)
{
	struct s_art	*t = dictSearch(dict, name);
	return t == NULL ? -1 : t->price;
}