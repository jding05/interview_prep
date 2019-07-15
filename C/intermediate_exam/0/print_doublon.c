#include <stdio.h>

void print_doublon(int *a, int na, int *b, int nb) {
	if (na == 0 || nb == 0) {
		return ;
	}

	int i = 0;
	int j = 0;
	int start = 1;
	while (i < na && j < nb) {
		if (a[i] == b[j]) {
			if (start == 1) {
				printf("%d", a[i]);
				start = 0;
			} else {
				printf(" %d", a[i]);
			}
			i++;
			j++;
		} else if (a[i] > b[j]) {
			j++;
		} else {
			i++;
		}
	}
	printf("\n");
}

// time O(na + nb)
// space O(1)

int main() {

	int a[] = {1, 2, 10, 15};
	int b[] = {2, 20, 40, 70};

	print_doublon(a, 4, b, 4);

	int c[] = {-5,  2, 10, 15, 50, 70, 100, 200, 300, 1200, 5000};
	int d[] = {2,  4,  5,  6,  7, 10,  40,  70};

	print_doublon(c, 11, d, 8);

	int e[] = {100,  200, 300};
	int f[] = {1,    2,   3, 4};

	print_doublon(e, 3, f, 4);
	return 0;
}