#include <stdio.h>

void equation(int n) {
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			for (int c = 0; c < n; c++) {
				if ((a * 10 + b) + (c * 10 + a) == n) {
					printf("A = %d, B = %d, C = %d\n", a, b, c);
				}
			}
		}
	}
}

// time O(n^3)
// space O(1);