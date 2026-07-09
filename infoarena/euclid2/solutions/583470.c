#include <stdio.h>

int main()
{
	freopen( "euclid2.in", "r", stdin );
	freopen( "euclid2.out", "w", stdout );

	int T, A,B, r;

	for ( scanf( "%d", &T ); T; T-- ) {
		scanf( "%d%d", &A, &B );
		while ( B ) {
			r = A % B;
			A = B;
			B = r;
		}
		printf( "%d\n", A );
	}

	return 0;
}
