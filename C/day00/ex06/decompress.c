#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "header.h"

// struct s_elem {
// 	char *word;
// 	int  occurence;
// };

// struct s_list {
// 	struct s_elem **elems;
// 	int           len;
// };

// struct s_string {
//   char *content;
//   int  length; //the current length of 'content'
//   int  capacity; //the allocated size of 'content'
// };

struct s_string *stringInit(void)
{
	struct s_string *str = (struct s_string *)malloc(sizeof(struct s_string));
	str->capacity = 100;
	str->content = (char *)malloc(sizeof(char) * (str->capacity + 1));
	str->length = 0;
	return (str);
}

int	stringAppend(struct s_string *dyString, char *str) //return 0 = FAIL, 1 = SUCCESS
{
	int len = (int)strlen(str);
	int capacity = dyString->capacity;
	if (capacity < len + dyString->length) {
		while (capacity < len + dyString->length) // dynamic allocate
			capacity *= 2;
		char *newstr = (char *)malloc(sizeof(char) * (capacity + 1));
		if (!newstr)
			return 0;
		bzero(newstr, capacity + 1);
		dyString->capacity = capacity;
		memcpy(newstr, dyString->content, dyString->length);
		memcpy(&newstr[dyString->length], str, len);
		free(dyString->content);
		dyString->content = newstr;
		dyString->length += len;
	}
	else
	{
		memcpy(&dyString->content[dyString->length], str, len);
		dyString->length += len;
	}
	return (1);
}

char **split(char *str, char *deliminator)
{
	int count = 0;
	int len_deliminator  = (int)strlen(deliminator);
	int len_substring = 0;
	for (int i = 0; str[i]; i++)
	{
		if (!strncmp(str + i, deliminator, len_deliminator))
		{
			if (len_substring > 0)
			{
				len_substring = 0;
				count++;
			}
			i += len_deliminator -1;
		}	
		else 
			len_substring++;
		
	}
	if (len_substring > 0)
		count++;
	char **table = (char **)malloc(sizeof(char *) * (count + 1));
	if (table == NULL)
		return NULL;

	int start = 0;
	int key = 0;
	table[key] = NULL;
	len_substring = 0;
	for (int i = 0; str[i]; i++)
	{
		if (!strncmp(str + i, deliminator, len_deliminator))
		{
			if (len_substring > 0)
			{
				table[key++] = strndup(str + start, len_substring);
				len_substring = 0;
			}
			i += len_deliminator -1;
			start = i + 1;
		}
		else
		{
			len_substring++;
		}
	}
	if (len_substring > 0)
		table[key++] = strndup(str + start, len_substring);
	table[key] = NULL;
	return (table);

}


void readWords(char *keySources, int len, char ***words, int *lenWords)
{
	keySources[len] = '\0';
	(*words) = split(keySources, ",");
	for (*lenWords = 0; (*words)[*lenWords]; (*lenWords)++)
		;
}

char *decompress(char *cBook)
{
	int start;
	int len;
	char **words;
	int lenWords;
	struct s_string *dyString;

	for (start = 0; cBook[start] && cBook[start] != '<'; start++)
		;
	start++;
	for (len = 0; cBook[len] && cBook[len] != '>'; len++)
		;
	readWords(&cBook[start], len, &words, &lenWords);
	start += len + 1;
	dyString = stringInit();
	
	while (cBook[start])
	{
		int i = 0;
		while (cBook[start + i] && cBook[start + i] != '@')
			i++;
		if (!cBook[start + i]) // reach the end
		{
			stringAppend(dyString, &cBook[start]);
			break;	
		}
		cBook[start + i] = '\0'; // set @ to null terminator
		stringAppend(dyString, &cBook[start]); // append the sentences before @
		start += i + 1;
		stringAppend(dyString, words[cBook[start] -1]);
		start++;
	}
	for (int i = 0; i < lenWords; i++)
		free(words[i]);
	free(words);
	char *output = dyString->content;
	free(dyString);
	return (output);
}
