#include <stdio.h>

int gcd( int x, int y ) {
	int r;
	
	while( y ) {
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}

int main() {
	int T, x, y;
	
	freopen( "euclid2.in", "r", stdin );
	freopen( "euclid2.out", "w", stdout );

	scanf( "%d", &T );

	while( T-- ) {
		scanf( "%d%d", &x, &y );
		printf( "%d\n", gcd( x, y ) );
	}

	return 0;
}

