#include <iostream>
#include <cstdio>

int a, b;

int gcd(int a, int b) {
	int c;
	while (b != 0) {
		b = a % (c = b);
		a = c;
	}
	return a;
}

int t;

int main() {
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", gcd(a,b));
	}
	
	return 0;
}
