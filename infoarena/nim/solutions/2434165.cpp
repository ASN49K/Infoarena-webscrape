#include <stdio.h>

inline int next_int() {
	int x = 0;
	register int c = getchar();

	for (; c < 48 || c > 57 ; c = getchar_unlocked());

	for (; c > 47 && c < 58 ; c = getchar_unlocked()) {
		x = (x << 3) + (x << 1) + (c & 15);
	}

	return x;
}

int main() {
	int t, n, element;
	freopen("nim.in", "r", stdin);
	freopen("nim.out", "w", stdout);
	t = next_int();

	for (; t ; --t) {
		n = next_int();
		int xorsum = 0;
		for (int i = 0 ; i < n ; ++i) {
			element = next_int();
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