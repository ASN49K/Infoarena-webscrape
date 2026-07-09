#include <stdio.h>

long gcd(long a, long b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main() {

	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	int t;
	long a, b;
	for (scanf("%d", &t); t > 0; -- t) {
		scanf("%ld %ld", &a, &b);
		printf("%ld\n", gcd(a, b));
	}

	return 0;
}