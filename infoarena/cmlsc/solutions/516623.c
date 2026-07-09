#include <stdio.h>
#include <assert.h>

#define NRMAX 	1024
#define NMAX	256

#define maxim(a, b)	(((a)>(b))? (a):(b))

int M, N, A[NRMAX], B[NRMAX], D[NRMAX][NRMAX], LCS[NRMAX], len;

int main()
{
	freopen("cmlsc.in", "rt", stdin);
	freopen("cmlsc.out", "wt", stdout);
	
	scanf("%d %d", &M, &N);
	assert( 1 <= M && M <= NRMAX);
	assert( 1 <= N && N <= NRMAX);
	
	int i, j;
	
	for (i = 1; i <= M; i++)
	{
		scanf("%d", A+i);
		assert( 0 <= A[i] && A[i] <= NMAX);
	}
	for (i = 1; i <= N; i++)
	{
		scanf("%d", B+i);
		assert( 0 <= B[i] && B[i] <= NMAX);
	}

	for ( i = 1; i <= M; i++)
		for ( j = 1; j <= N; j++)
			if (A[i] == B[j])
                D[i][j] = 1 + D[i-1][j-1];
            else
                D[i][j] = maxim(D[i-1][j], D[i][j-1]);
	
	for (i = M, j = N; i; )
		if (A[i] == B[j])
		{
            LCS[++len] = A[i];
			--i;
			--j;
		}
        else if (D[i-1][j] < D[i][j-1])
            --j;
        else
            --i;
			
	printf("%d\n", len);
	for (i = len; i; --i)
		printf("%d ", LCS[i]);
				
	return 0;
}
