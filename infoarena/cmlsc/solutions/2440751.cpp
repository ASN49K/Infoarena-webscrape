#include <bits/stdc++.h>

#define DIM 1 << 10

int a[DIM + 1], b[DIM + 1], solution[DIM + 1], c[DIM + 1][DIM + 1];

inline void print(int n) {
	char snum[65];
	int i = 0;
	do {
		snum[i++] = n % 10 + '0';
		n /= 10;
	} while (n);

	--i;

	while (i >= 0) {
		putchar(snum[i--]);
	}

	putchar(' ');
}

inline int read() {
	int n = 0;
	char c = getchar_unlocked();

	while (!('0' <= c && c <= '9')) {
		c = getchar_unlocked();
	}

	while ('0' <= c && c <= '9') {
		n = (n << 3) + (n << 1) + (c - '0');
		c = getchar_unlocked();
	}

	return n;
}

inline int max(int a, int b) {
	if (a > b) {
		return a;
	} 

	return b;
}

int main() {
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	int m, n;
	m = read(), n = read();
	for (int i = 1 ; i <= m ; ++i) {
		a[i] = read();
	}

	for (int i = 1 ; i <= n ; ++i) {
		b[i] = read();
	}

	for (int i = 1 ; i <= m ; ++i) {
		for (int j = 1 ; j <= n ; ++j) {
			if (a[i] == b[j]) {
				c[i][j] = c[i - 1][j - 1] + 1;
			} else {
				c[i][j] = max(c[i - 1][j], c[i][j - 1]);
			}
		}
	}

	int i = m, j = n, k = 0;

	while (i && j) {
		if (a[i] == b[j]) {
			solution[k++] = a[i];
			--i;
			--j;
		} else if (c[i - 1][j] < c[i][j - 1]) {
			--j;
		} else {
			--i;
		}
	}

	printf("%d\n", k);
	for (int i = k - 1 ; i >= 0 ; --i) {
		print(solution[i]);
	}

	return 0;
}