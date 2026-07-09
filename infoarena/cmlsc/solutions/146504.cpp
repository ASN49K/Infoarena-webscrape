#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int A[MAX], B[MAX], D[MAX][MAX], N, M, sir[MAX];

int max (int a, int b)
{
	if ( a> b) return a; else return b;
}

void solve()
{
	for (int i=1; i<=N;i++)
		for( int j =1; j<=M; j++)
			if ( A[i] == B[j])
				D[i][j] = 1 + D[i-1][j-1];
			else
				D[i][j] = max ( D[i-1][j], D[i][j-1]);

}

void afis()
{
	int x=N, y = M;
	for ( int k = D[N][M]; k>0; )
	{
		if ( A[x] == B[y] )
		{
			sir[k] = A[x];
			x--; y--; k--;
		}
		else
		if ( D[x-1][y] == k )
			x--;
		else
			y--;
	}
	for (int i = 1; i<= D[N][M]; i++)
		printf("%d ", sir[i]);

}


int main()
{
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	scanf("%d %d", &N, &M);

	int i;

	for (i = 1; i<=N; i++)
		scanf("%d", A+i);
	for (i = 1; i<=M; i++)
		scanf("%d", B+i);

	solve();
	printf("%d\n", D[N][M]);
	afis();


	return 0;
}