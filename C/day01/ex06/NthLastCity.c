#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "header.h"

char *NthLastCity(struct s_city *city, int n)
{
	struct s_city *tmp = city;
	while (n-- > 0)
	{
		if (tmp == NULL)
			return NULL;
		tmp = tmp->next;
	}
	tmp = tmp->next;
	while (tmp) {
		tmp = tmp->next;
		city = city->next;
	}
	return city->name;
}

