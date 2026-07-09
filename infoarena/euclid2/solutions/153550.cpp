#include <cstdio>

long gcd(long x, long y) {
	if ( y==0 )
		return x;
	return gcd(y, x%y);
}


int main() {
	long x,y, T;

	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	scanf("%ld", &T);
	while ( T-- ) {
		scanf("%ld %ld", &x, &y);
		printf("%ld\n", gcd(x,y));
	}
	return 0;
}
