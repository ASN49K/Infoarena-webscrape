//Cel mai lung subsir comun
#include <stdio.h>
#define INPUT "cmlsc.in"
#define OUTPUT "cmlsc.out"
#define MAXN 1025

int M, N;
int A[MAXN], B[MAXN], l[MAXN][MAXN], p[MAXN];

int main()
{
	freopen(INPUT, "r", stdin);
	freopen(OUTPUT, "w", stdout);
	
	scanf("%d %d", &M, &N);
	int i,j;
	for(i = 1; i <= M; ++i) scanf("%d", &A[i]);
	for(i = 1; i <= N; ++i) scanf("%d", &B[i]);
	
	for(i = 1; i <= M; ++i)
		for(j = 1; j <= N; ++j)
			if(A[i] == B[j]) l[i][j] = l[i-1][j-1]+1;
			else
			{
				l[i][j] = l[i-1][j];
				if(l[i][j-1] > l[i][j]) l[i][j] = l[i][j-1];
			}
	

	printf("%d\n", l[M][N]);
	
	int nr = -1;
	for(i = M, j = N;i && j;)
		if(A[i] == B[j]) p[++nr] = A[i], --i, --j;
		else if(l[i-1][j] > l[i][j-1]) --i;
			else --j;
		
	for(i = nr; i; --i)
		printf("%d ", p[i]);
	printf("%d\n", p[0]);
	
	return 0;
}
