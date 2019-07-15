int is_anagram(char *a, char *b) {
	if (a == 0 && b == 0) {
		return 1;
	} else if (a == 0 || b == 0) {
		return 0;
	}
	int cache[126] = {0};
	int len = 0;
	for (int i = 0; a[i]; i++) {
		cache[(int)a[i]]++;
		len++;
	}
	for (int i = 0; b[i]; i++) {
		if (len == 0) {
			return 1;
		}
		if (cache[(int)b[i]]-- == 0) {
			return 0;
		}
		len--;
	}
	for (int i = 0; i < 126; i++) {
		if (cache[i] != 0) {
			return 0;
		}
	}
	return 1;
}

// time O(max(lenA, 126))
// space O(1) // precise O(126)


#include <stdio.h>
int main(int ac, char ** av)
{
	if (ac > 2)
		printf("|%i|\n", is_anagram(av[1], av[2]));
	return 0;
}