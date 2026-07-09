#include <cstdio>

int gcd (int a, int b){
	int r;
	for (; b; r = a % b, a = b, b = r);

	return a;
}

int main () {
	freopen ("euclid2.in", "r", stdin);
	freopen ("euclid2.out", "w", stdout);

	int T, a, b;
	for (scanf("%d", &T); T; -- T){
		scanf ("\n%d %d", &a, &b);
		printf ("%d\n", gcd(a, b));
	}

	return 0;
}
