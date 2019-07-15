#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

#include "header.h"

size_t hash(char *input)
{
	if (!input)
		return (0);
	size_t	res = strlen(input);
	for (unsigned int i = 0; i < strlen(input) && i < 16; i++)
	{
		res <<= 4;
		res += (unsigned char)input[i];
	}
	return (res);
}

struct s_dict *dictInit(int capacity)
{
	struct s_dict *dict;

	dict = (struct s_dict*)malloc(sizeof(struct s_dict));
	dict->capacity = capacity;
	dict->items = (struct s_item**)malloc(sizeof(struct s_item*) * capacity);
	bzero(dict->items, sizeof(struct s_item*) * capacity);
	return (dict);
}

int	dictInsert(struct s_dict *dict, char *key, int value)
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

int	dictSearch(struct s_dict *dict, char *key)
{
	size_t k = hash(key) % (size_t)dict->capacity;
	if (!(dict->items[k]))
		return (-1);
	struct s_item *t = dict->items[k];
	while (t)
	{
		if (!strcmp(t->key, key))
			return (t->value);
		t = t->next;
	}
	return (-1);
}



char *add_header(char *book, struct s_dict *dict, int n, int N)
{
	char buf[2048];

	int p = 0;
	buf[p++] = '<';
	for (int c = 0; c < 256; c++)
	{
		int i;
		for (i = 0; i < dict->capacity; i++)
		{
			struct s_item *t = dict->items[i];
			while (t)
			{
				if (t->value == c)
				{
					strcpy(&buf[p], t->key);
					p += strlen(t->key);
					buf[p] = ',';
					p++;
					break ;
				}
				t = t->next;
			}
			if (t)
				break ;
		}
		if (i == dict->capacity)
			break ;
	}
	buf[p] = '>';
	buf[p + 1] = '\n';
	buf[p + 2] = '\0';
	int headerLen = strlen(buf);
	if (headerLen >= N - n)
	{
		printf("The file too big to compile!!!");
		exit(1);
	}
	memcpy(&book[headerLen], &book[0], n);
	memcpy(book, buf, headerLen);
	return (book);
}

char *compress(char *book, struct s_dict *dict)
{
	char index;
	char buf[14];
	int bookLenOG = (int)strlen(book);
	int bookLen = bookLenOG;

	for (int wordLen = 13; wordLen >= 3; wordLen--)
	{
		int p = 0;
		int i = 0;
		char end = 0;
		while (i + wordLen <= bookLen)
		{
			strncpy(buf, &book[i], wordLen);
			buf[wordLen] = 0;
			if ((index = (unsigned char)dictSearch(dict, buf)) != -1)
			{
				book[p] = '@';
				book[p + 1] = index + 1;
				book[p + 2] = 0;
				i += wordLen - 1;
				end = 1;
				p++;
			}
			else
			{
				book[p] = book[i];
				end = 0;
			}
			p++;
			i++;
		}
		if (!end)
		{
			for (int i = bookLen - wordLen + 1; i < bookLen; i++)
				book[p++] = book[i];
		}
		bzero(&book[p], bookLen - p);
		bookLen = p;
	}
	book = add_header(book, dict, bookLen, bookLenOG);
	return (book);
}
