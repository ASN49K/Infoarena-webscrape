#include <stdio.h>

#define nmax 1025
#define mmax 1025

short N, M;

short A[nmax], B[mmax];

short ANS[nmax][mmax], WHE[nmax][mmax];

void read()
{
	int i, j;

	freopen("cmlsc.in", "r", stdin);

	scanf("%d%d", &N, &M);

	for (i = 1; i <= N; ++i)
		scanf("%d", &A[i]);

	for (j = 1; j <= M; ++j)
		scanf("%d", &B[j]);
}

void solve()
{
	int i, j;

	for (i = 1; i <= N; ++i)
		for (j = 1; j <= M; ++j)
		{
			if (ANS[i-1][j] >= ANS[i][j])
			{
				ANS[i][j] = ANS[i-1][j];
				WHE[i][j] = 1;
			}

			if (ANS[i][j-1] >= ANS[i][j])
			{
				ANS[i][j] = ANS[i][j-1];
				WHE[i][j] = 2;
			}

			if (A[i] == B[j] && ANS[i-1][j-1] + 1 >= ANS[i][j])
			{
				ANS[i][j] = ANS[i-1][j-1] + 1;
				WHE[i][j] = 3;
			}
		}
}

void back(int i, int j)
{
	if (!i || !j)
		return;

	if (WHE[i][j] == 3)
	{
		back(i-1, j-1);
		printf("%d ", A[i]);
	}
	else if (WHE[i][j] == 1)
		back(i-1, j);
	else
		back(i, j-1);
}

void write()
{
	freopen("cmlsc.out", "w", stdout);

	printf("%d\n", ANS[N][M]);

	back(N, M);
}

int main()
{
	read();

	solve();

	write();

	return 0;
}
