#include <cstdio>
#include <cstdlib>
#include <cstring>

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	int T, a, b;
	for (scanf("%d", &T); T; T--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", gcd(a, b));
	}
	return 0;
}
