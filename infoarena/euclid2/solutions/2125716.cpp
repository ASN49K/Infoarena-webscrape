#include <stdio.h>

int gcd(int a, int b) {
	int t;
	while (b) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main(void) {
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	int T, a, b;
	scanf("%d", &T);

	for (; T; T--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", gcd(a, b));
		/*f >> a >> b;
		o << gcd(a, b) << std::endl;*/
	}
	return 0;
}