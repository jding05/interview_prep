int find_pivot(int *arr, int n) {
	int total = 0;
	int sum = 0;

	for (int i = 0; i < n; i++) {
		total += arr[i];
	}
	for (int i = 0; i < n; i++) {
		if (sum == total - sum - arr[i]) {
			return i;
		}
		sum += arr[i];
	}
	return -1;
}

// time O(n)
// space O(1)