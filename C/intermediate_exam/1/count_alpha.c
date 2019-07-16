#include <stdio.h>
#include <unistd.h>

int isUpper(char c) {
	return c >= 'A' && c <= 'Z';
}

int isLower(char c) {
	return c >= 'a' && c <= 'z';
}

void count_alpha(char *s) {
	int cache[26] = {0};
	for (int i = 0; i < s[i]; i++) {
		if (isUpper(s[i])) {
			s[i] += 32;
		}
		if (isLower(s[i])) {
			cache[s[i] - 'a']++;
		}
	}
	int start = 1;
	for (int i = 0; i < s[i]; i++) {
		if (isLower(s[i]) && cache[s[i] - 'a'] > 0) {
			if (start == 1) {
				printf("%d%c", cache[s[i] - 'a'], s[i]);
				start = 0;
			} else {
				printf(", %d%c", cache[s[i] -'a'], s[i]);
			}
			cache[s[i] - 'a'] = 0;
		}
	}
	printf("\n");
}
int main(int ac, char **av) {
	if (ac == 2) {
		count_alpha(av[1]);
	} else {
		printf("\n");
	}
	return 0;
}