#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "header.h"

int selectHotspots(struct s_hotspot **hotspots)
{
	int len = 0;
	for (int i = 0; hotspots[i]; i++)
	{
		hotspots[i]->pos += hotspots[i]->radius;
		hotspots[i]->radius *= 2;
		len++;
	}
	int count = 1;
	int pos = hotspots[0]->pos;
	for (int i = 1; i < len; i++)
	{
		if (hotspots[i]->pos - hotspots[i]->radius >= pos)
		{
			pos = hotspots[i]->pos;
			count++;
		}
	}
	return count;
}
