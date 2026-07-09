#include <stdio.h>
#include <stdlib.h>

#define NMax 260

int M, N, a[NMax], b[NMax], mat[NMax][NMax], k[NMax];


void back(int m, int n)
{
	int i;
	int j;
	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++) {
			if (a[j - 1] == b[i - 1])
				mat[i][j] = mat[i - 1][j - 1] + 1;
			else
				mat[i][j] = (mat[i][j - 1] > mat[i - 1][j] ? mat[i][j - 1] : mat[i - 1][j]);
		}

	printf("%d\n", mat[n - 1][m - 1]);
	i = n - 1;
	j = m - 1;
	int l = 0;
	while (mat[i][j] != 0) {
		if (a[j - 1] == b[i - 1]) {
			k[l++] = a[j - 1];
			i--; j--;
		}
		else if (mat[i][j] == mat[i - 1][j])
			i--;
		else
			j--;
	}

	for (i = l - 1; i > -1; i--)
		printf("%d ", k[i]);
}

int main(void)
{
	int i;

	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);


	scanf("%d %d", &M, &N);
	for (i = 0; i < M; i++)
		scanf("%d", &a[i]);
	for (i = 0; i < N; i++)
		scanf("%d", &b[i]);

	back(M + 1, N + 1);

	return 0;
}