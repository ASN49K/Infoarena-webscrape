#include <stdio.h>

const int N_MAX = 1030;

unsigned char a[N_MAX], b[N_MAX], sol[N_MAX];
short int din[N_MAX][N_MAX];

inline int MAX(int a, int b)
{
	return (a > b ? a : b);
}

int main()
{
	freopen("cmlsc.in", "r", stdin);
#ifndef _SCREEN_
	freopen("cmlsc.out", "w", stdout);
#endif

	int M, N;
	scanf("%d %d\n", &M, &N);
	for (int i = 1; i <= M; i ++) scanf("%d ", &a[i]);
	for (int i = 1; i <= N; i ++) scanf("%d ", &b[i]);

	for (int i = 1; i <= M; i ++) {
		for (int j = 1; j <= N; j ++) {

			if (a[i] == b[j]) din[i][j] = din[i - 1][j - 1] + 1;
			else din[i][j] = MAX(din[i - 1][j], din[i][j - 1]);
		}
	}

	printf("%d\n", din[M][N]);

	int x = M, y = N;
	while (sol[0] != din[M][N]) {

		if (a[x] == b[y]) {
			sol[++ sol[0]] = a[x];
			x --;
			y --;
		} else {
			if (din[x - 1][y] > din[x][y - 1]) x --;
			else y --;
		}
	}

	for (int i = sol[0]; i >= 1; i --) printf("%d ", sol[i]);
	printf("\n");

	return 0;
}
