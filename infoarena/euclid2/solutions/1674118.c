#include <stdio.h>

static int gcd(int a, int b)
{
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int main(void)
{
	int t, i, a, b;
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	scanf("%i", &t);
	for (i = 0; i < t; ++i) {
		scanf("%i%i", &a, &b);
		printf("%i\n", gcd(a, b));
	}
	return 0;
}
