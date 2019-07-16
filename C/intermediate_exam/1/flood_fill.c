#include "t_point.h"

void flood_fill(char **tab, t_point size, t_point begin) {
	char ref = tab[begin.y][begin.x];
	tab[begin.y][begin.x] = 'F';
	if (begin.x -1 >= 0 && tab[begin.y][begin.x -1] == ref) {
		t_point newstart = begin;
		newstart.x -= 1;
		flood_fill(tab, size, newstart);
	}
	if (begin.x + 1 < size.x && tab[begin.y][begin.x + 1] == ref) {
		t_point newstart = begin;
		newstart.x += 1;
		flood(tab, size, newstart);
	}
	if (begin.y -1 >= 0 && tab[begin.y -1[begin.x]] == ref) {
		t_point newstart = begin;
		newstart.y -= 1;
		flood_fill(tab, size, newstart);
	}
	if (begin.y + 1 < size.y && tab[begin.y + 1][begin.x] == ref) {
		t_point newstart = begin;
		newstart.y += 1;
		flood_fill(tab, size, newstart);
	}
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	t_point size = {8, 5};
	t_point begin = {5, 3};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char **tab = (char **)malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; i++) {
		tab[i] = (char*)malloc(sizeof(char) * size.x);
		strcpy(tab[i], zone[i]);
	}
	for (itn i = 0; i < size.y; i++) {
		printf("%s\n", tab[i]);
	}
	printf("\n");
	flood_fill(tab, size, begin);
	for (int i = 0; i < size.y; i++) {
		printf("%s\n", tab[i]);
	}
	return 0;
}