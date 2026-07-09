#include <cstdio>

inline long max(long a, long b) { return a>b?a:b; }

const long MAX = 1026;
long M[MAX][MAX];
long A[MAX], B[MAX];

long i,j,n,m;

void drum(long i, long j) { 
	if ( !i || !j )
		return ;
	if ( A[i]!=B[j] ) {
		if ( M[i-1][j]>M[i][j-1] ) 
			drum(i-1, j);
		else
			drum(i, j-1);
	} else {
		drum(i-1, j-1);
		printf("%ld ", A[i]);
	}
}

int main() {
	freopen("cmlsc.in", "r", stdin);
	scanf("%ld %ld", &n, &m);
	for (i=1; i<=n; ++i) scanf("%ld", A+i);
	for (i=1; i<=m; ++i) scanf("%ld", B+i);

	for (i=1; i<=n; ++i)
		for (j=1; j<=m; ++j)
			if ( A[i] == B[j] ) 
				M[i][j] = M[i-1][j-1] + 1;
			else
				M[i][j] = max(M[i][j-1], M[i-1][j]);

	freopen("cmlsc.out", "w", stdout);
	printf("%ld\n", M[n][m]);
	drum(n,m);
	return 0;
}
