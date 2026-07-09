#include <cstdio>

int gcd(int a, int b) {
	if (b) {
		return(gcd(b, a % b));
	} else {
		return(a);
	}
}

int main() {
	freopen("euclid2.in", "rt", stdin);
	freopen("euclid2.out", "wt", stdout);

	int n;
	scanf("%d", &n);
	while (n--) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", gcd(a, b));
	}
}
