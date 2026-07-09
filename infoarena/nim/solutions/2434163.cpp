#include <assert.h>
#include <fstream>

inline int next_int() {
	int n = 0;
	char c = getchar_unlocked();
	
	while (!('0' <= c && c <= '9')) {
		c = getchar_unlocked();
	}
	
	while ('0' <= c && c <= '9') {
		n = n * 10 + c - '0';
		c = getchar_unlocked();
	}

	return n;
}

int main() {
	int t, n, element;
	freopen("nim.in", "r", stdin);
	freopen("nim.out", "w", stdout);
	t = next_int();
	assert(1 <= t && t <= 100);

	for (; t ; --t) {
		n = next_int();
		int xorsum = 0;
		for (int i = 0 ; i < n ; ++i) {
			element = next_int();
			xorsum ^= element;
		}

		if (xorsum) {
			printf("DA\n");
		} else {
			printf("NU\n");
		}
	}

	return 0;
}