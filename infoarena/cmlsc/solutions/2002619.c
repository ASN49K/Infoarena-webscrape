#include <stdio.h>
#include <stdlib.h>

#define NMax 1024

int M, N, a[NMax], b[NMax], mat[NMax][NMax], k[NMax], l;


int main(void)
{
	int i;
	int j;
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);


	scanf("%d %d", &M, &N);
	for (i = 0; i < M; i++)
		scanf("%d", &a[i]);
	for (i = 0; i < N; i++)
		scanf("%d", &b[i]);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) 
			if (a[j - 1] == b[i - 1])
				mat[i][j] = mat[i - 1][j - 1] + 1;
			else
				mat[i][j] = (mat[i][j - 1] > mat[i - 1][j] ? mat[i][j - 1] : mat[i - 1][j]);

	
	for (i = N, j = M; i; )
		if (a[j - 1] == b[i - 1]) {
			k[l++] = a[j - 1];
			i--; j--;
		}
		else if (mat[i][j] == mat[i - 1][j])
			i--;
		else
			j--;

	printf("%d\n", mat[N][M]);
	for (i = l - 1; i > -1; i--)
		printf("%d ", k[i]);

	return 0;
}