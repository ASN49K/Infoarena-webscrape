#include <bits/stdc++.h>

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
		n = (n << 3) + (n << 1) + c - '0';
		c = getchar_unlocked();
	}

	return n;
}

int main() {
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	int m, n;
	m = read(), n = read();
	std::vector<int> solution, a(m + 1), b(n + 1);
	for (int i = 1 ; i <= m ; ++i) {
		a[i] = read();
	}

	for (int i = 1 ; i <= n ; ++i) {
		b[i] = read();
	}

	std::vector<std::vector<int>> c(m + 1, std::vector<int>(n + 1));
	for (int i = 1 ; i <= m ; ++i) {
		for (int j = 1 ; j <= n ; ++j) {
			if (a[i] == b[j]) {
				c[i][j] = c[i - 1][j - 1] + 1;
			} else {
				c[i][j] = std::max(c[i - 1][j], c[i][j - 1]);
			}
		}
	}

	int i = m, j = n;

	while (i && j) {
		if (a[i] == b[j]) {
			solution.push_back(a[i]);
			--i;
			--j;
		} else if (c[i - 1][j] < c[i][j - 1]) {
			--j;
		} else {
			--i;
		}
	}

	printf("%ld\n", solution.size());
	for (auto it = solution.rbegin(); it != solution.rend() ; ++it) {
		print(*it);
	}

	return 0;
}