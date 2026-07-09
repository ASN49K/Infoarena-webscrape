#include <stdio.h>

#define MAXN 1030

int N, M, a[MAXN], b[MAXN];

int bst[MAXN][MAXN];

inline void rebuild( int N, int M )
{
	if (N == 0 || M == 0)
		return;

	if (a[N - 1] == b[M - 1])
		rebuild( N - 1, M - 1 ),
		printf("%d ", a[N - 1]);
	else
		if (bst[N - 1][M] > bst[N][M - 1])
			rebuild(N - 1, M);
		else
			rebuild(N, M - 1);
}

int main()
{
	freopen("cmlsc.in", "rt", stdin);
	freopen("cmlsc.out", "wt", stdout);

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
	for (int j = 0; j < M; j++)
		scanf("%d", b + j);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (a[i - 1] == b[j - 1])
				bst[i][j] = bst[i - 1][j - 1] + 1;
			else
				if (bst[i - 1][j] > bst[i][j - 1])
					bst[i][j] = bst[i - 1][j];
				else
					bst[i][j] = bst[i][j - 1];

	printf("%d\n", bst[N][M]);
	rebuild( N, M );
	printf("\n");
	return 0;
}
