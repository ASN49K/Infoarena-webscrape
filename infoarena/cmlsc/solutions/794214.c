#include <stdio.h>

short A[1025], B[1025];
short C[1025][1025];
short n, m;

int main()
{
	short i, j, x;
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	
	scanf("%hd %hd", &n, &m);
	for(i = 1; i <= n; ++i) scanf("%hd", &A[i]);
	for(i = 1; i <= m; ++i) scanf("%hd", &B[i]);

	for(i = 1; i <= n; ++i)
		for(j = 1; j <= m; ++j)
			if(A[i] == B[j])
				C[i][j] = C[i-1][j-1]+1;
			else
				C[i][j] = (C[i-1][j] > C[i][j-1] ? C[i-1][j] : C[i][j-1]);

	printf("%hd\n", C[n][m]);
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
