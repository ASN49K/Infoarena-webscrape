#include <stdio.h>

#define size 65536
int position = size - 1;
char buffer[size];

inline void next_int(int &n) {
	n = 0;

	while ('0' > buffer[position] || buffer[position] > '9') {
		if (++position == size) {
			fread(buffer, 1, size, stdin);
			position = 0;
		}
	}

	while('0' <= buffer[position] && buffer[position] <= '9') {
		n = (n << 3) + (n << 1) + buffer[position] - 48;
		if (++position == size) {
			fread(buffer, 1, size, stdin);
			position = 0;
		}
	}
}

int main() {
	int t, n, element;
	freopen("nim.in", "r", stdin);
	freopen("nim.out", "w", stdout);
	next_int(t);

	for (; t ; --t) {
		next_int(n);
		int xorsum = 0;
		for (int i = 0 ; i < n ; ++i) {
			next_int(element);
			xorsum ^= element;
		}

		if (xorsum) {
			putchar('D'), putchar('A'), putchar('\n');
		} else {
			putchar('N'), putchar('U'), putchar('\n');
		}
	}

	return 0;
}