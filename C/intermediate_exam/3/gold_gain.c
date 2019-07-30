#include <stdlib.h>

int max(int left, int right) {
	return left > right ? left : right;
}

int gold_gain(int **mine, int n) {
	int **cache = malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		cache[i] = malloc(sizeof(int) * n);
	}
	for (int i = n -1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (i == n -1) {
				cache[j][i] = mine[j][i];
			} else if (j == 0) {
				cache[j][i] = max(cache[j][i+1], cache[j+1][i+1]);
				cache[j][i] += mine[j][i];
			} else if (j == n -1) {
				cache[j][i] = max(cache[j][i+1], cache[j-1][i+1]);
				cache[j][i] += mine[j][i];
			} else {
				cache[j][i] = max(cache[j][i+1], cache[j-1][i+1]);
				cache[j][i] = max(cache[j][i], cache[j+1][i+1]);
				cache[j][i] += mine[j][i];
			}
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		res = max(res, cache[i][0]);
	}
	return res;
}

// time O(n^2)
// space O(n^2)

#include <stdio.h>
int main() {

	int **maine = malloc(sizeof(int *) * 3);
	for (int i = 0; i < 3; i++) {
		maine[i] = malloc(sizeof(int) * 3);
	}
	maine[0][0] = 1;
	maine[0][1] = 0;
	maine[0][2] = 0;
	maine[1][0] = 0;
	maine[1][1] = 3;
	maine[1][2] = 4;
	maine[2][0] = 0;
	maine[2][1] = 0;
	maine[2][2] = 0;
	printf("%d\n", gold_gain(maine, 2));

 	int **mainee = malloc(sizeof(int *) * 3);
	for (int i = 0; i < 3; i++) {
		mainee[i] = malloc(sizeof(int) * 3);
	}
	mainee[0][0] = 1;
	mainee[0][1] = 2;
	mainee[0][2] = 3;
	mainee[1][0] = 3;
	mainee[1][1] = 4;
	mainee[1][2] = 8;
	mainee[2][0] = 9;
	mainee[2][1] = 6;
	mainee[2][2] = 7;
	printf("%d\n", gold_gain(mainee, 3));

	int **maineee = malloc(sizeof(int *) * 4);
	for (int i = 0; i < 4; i++) {
		maineee[i] = malloc(sizeof(int) * 4);
	}
	maineee[0][0] = 1;
	maineee[0][1] = 3;
	maineee[0][2] = 1;
	maineee[0][3] = 5;
	maineee[1][0] = 2;
	maineee[1][1] = 2;
	maineee[1][2] = 4;
	maineee[1][3] = 1;
	maineee[2][0] = 5;
	maineee[2][1] = 0;
	maineee[2][2] = 2;
	maineee[2][3] = 3;
	maineee[3][0] = 0;
	maineee[3][1] = 6;
	maineee[3][2] = 1;
	maineee[3][3] = 2;


	printf("%d\n", gold_gain(maineee, 4));
	return 0;
}
