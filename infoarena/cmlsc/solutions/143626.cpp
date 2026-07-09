#include <stdio.h>

#define NMax 1024
#define FOR(i, a, b) for (i = a; i <= b; ++i)
#define maxim(a, b) ((a > b) ? a : b)

int M, N, A[NMax], B[NMax], D[NMax][NMax], sir[NMax], cnt;

int main(void)
{
	int i, j;
	
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	scanf("%d %d", &M, &N);
	FOR (i, 1, M) 
		scanf("%d", &A[i]);
	FOR (i, 1, N)
		scanf("%d", &B[i]);

	FOR (i, 1, M)
		FOR (j, 1, N)
			if (A[i] == B[j])
				D[i][j] = 1 + D[i-1][j-1];
			else
				D[i][j] = maxim(D[i-1][j], D[i][j-1]);

	for (i = M, j = N; i && j; )
		if (A[i] == B[j])
			sir[++cnt] = A[i], --i, --j;
		else if (D[i][j-1] < D[i-1][j])
			--i;
		else
			--j;

	printf("%d\n", cnt);
	for (i = cnt; i; --i)
		printf("%d ", sir[i]);
	printf("\n");
	
	
	return 0;
}

