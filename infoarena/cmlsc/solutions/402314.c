/*

@ Mihai Tabara, 2010
CMLSC
O( N*M ) - time
O( N + M + N*M ) - memory
*/

#include <stdio.h>

#define in "cmlsc.in"
#define out "cmlsc.out"

#define maxim(a,b) ((a)>(b)?(a):(b))
#define NMAX 1035

int A[NMAX], B[NMAX];
int C[NMAX][NMAX], N, M;

int main ( void )
{
	freopen ( in, "r", stdin );
	freopen ( out, "w", stdout );

	int i, j;

	scanf ( "%d%d", &N, &M );
	for ( i = 1; i <= N; scanf ( "%d", A+i++ ) );
	for ( i = 1; i <= M; scanf ( "%d", B+i++ ) );

	C[0][0] = 0;
	for ( i = 1; i <= N; ++i ) C[i][1] = 0;
	for ( i = 1; i <= M; ++i ) C[1][i] = 0;

	for ( i = 1; i <= N; ++i )
		for ( j = 1; j <= M; ++j ) {
			if ( A[i] == B[j] )
				C[i][j] = C[i-1][j-1] + 1;
			else
				C[i][j] = maxim ( C[i-1][j], C[i][j-1] );
		}

	printf ( "%d\n", C[N][M] );
	return 0;
}
