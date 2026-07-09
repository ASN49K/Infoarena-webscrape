#include <cstdio>

int main(void) {
	freopen("euclid2.in", "rt", stdin);
	freopen("euclid2.out", "wt", stdout);

	int T, a, b, r;

	scanf(" %d", &T);

	while (T--) {
		scanf(" %d %d", &a, &b);

		while (b) {
			r = a % b;
			a = b;
			b = r;
		}

		printf("%d\n", a);
	}

	return 0;
}
