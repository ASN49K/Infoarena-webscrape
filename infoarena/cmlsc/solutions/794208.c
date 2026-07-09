#include <stdio.h>

char A[1025], B[1025], C[1025][1025];
int n, m;

int main()
{
	int i, j, x;
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	for(i = 1; i <= n; ++i) scanf("%d", &x), A[i] = x;
	for(i = 1; i <= m; ++i) scanf("%d", &x), B[i] = x;

	for(i = 1; i <= n; ++i)
		for(j = 1; j <= m; ++j)
			if(A[i] == B[j])
				C[i][j] = C[i-1][j-1]+1;
			else
				C[i][j] = (C[i-1][j] > C[i][j-1] ? C[i-1][j] : C[i][j-1]);

	printf("%d\n", C[n][m]);
	for(x = n, i = n, j = m; i && j; )
		if(A[i] == B[j]) 
		{
			A[x--] = A[i];
			i--, j--;
		}
		else if( C[i-1][j] == C[i][j])
			i--;
		else j--;

	for(i = x+1; i <= n; ++i)
		printf("%d ", A[i]);
	printf("\n");

	return 0;
}
