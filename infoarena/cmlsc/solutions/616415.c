#include <stdio.h>

#define MAX 1024
#define maxim(a, b) ((a > b) ? (a) : (b))

int A[MAX], B[MAX], LCS[MAX][MAX], result[MAX], k, M, N;

int
main(void)
{
	int i, j;
	
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	
	scanf("%d %d", &M, &N);
	
	for(i = 1; i <= M; ++i)
		scanf("%d", &A[i]);
		
	for(i = 1; i <= N; ++i)
		scanf("%d", &B[i]);
		
	for(i = 1; i <= M; ++i)
		for(j = 1; j <= N; ++j)
			if(A[i] == B[j])
				LCS[i][j] = 1 + LCS[i - 1][j - 1];
			else
				LCS[i][j] = maxim(LCS[i - 1][j], LCS[i][j - 1]);
	
	for(i = M, j = N; i; )
		if(A[i] == B[j])
			result[++k] = A[i], --j, --i;
		else if(LCS[i - 1][j] < LCS[i][j - 1])
			j--;
		else
			i--;
	
	printf("%d\n", k);
	for(i = k; i; --i)
		printf("%d ", result[i]);

	return 0;
}