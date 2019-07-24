import java.util.*;

// clarify: the stirng is an ASCII string (if Unicode will be 256 for extended ASCII)
// assumption: the string is an ASCII string (0~128)
// method 1:

boolean isUniqueChars(String str) {
	if (str == null || str.length() <= 1) {
		return true;
	}
	if (str.length() > 128) {
		return false;
	}
	boolean[] charSet = new boolean[128];
	for (int i = 0; i < str.length(); i++) {
		int val = str.charAt(i);
		if (charSet[val] == true) {
			return false;
		}
		charSet[val] = true;
	}
	return true;
}

// time O(n)
// space O(1) --> bc the space is fixed
// or space O(min(c, n)) --> c is the length of charSet

// ----------------------------------------------------------------------------------
// method 2: bitwise
boolean isUniqueChars(String str) {
	if (str == null || str.length() <= 1) {
		return true;
	} else if (str.length() > 128) {
		return false;
	}
	int[] vector = new int[4];
	for (int i = 0; i < str.length(); i++) {
		int val = str.charAt(i);
		int row = val / 32;
		int col = val % 32;
		if (vector[row] >> col & 1 == 1) {
			return false;
		}
		vector[row] |= 1 << col;
	}
}

// time O(n)
// space O(4) --> O(1)

// ----------------------------------------------------------------------------------
// follow up
// ---------
/*
 * if we can't use additional data structure, we can do the following:
 * 1. compare every char of the string to every other character of the stirng
 * 		time: O(n^2), space: O(1)
 * 
 * 2. if we are able to modify the input string, we could sort the string with O(nlogn) time
 *  and linearly check the string for neighboring characters that are identical
 *  there will be additional space with the sorting algorithm