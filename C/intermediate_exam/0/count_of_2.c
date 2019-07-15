int count_of_2(int n) {
	if (n <= 1) {
		return 0;
	}
	int count = 0;
	for (int i = 2; i <= n; i++) {
		int tmp = i;
		while (tmp > 0) {
			if (tmp % 10 == 2) {
				count++;
			}
			tmp /= 10;
		}
	}
	return count;
}

// time O(n * k) -- k is the number digits of n
// space O(1)