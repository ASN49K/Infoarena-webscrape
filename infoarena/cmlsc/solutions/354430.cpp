#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAXN		1024

int A[MAXN + 1], B[MAXN + 1];
int maxlen[MAXN + 1][MAXN + 1];

int printsol(int i, int j)
{
	int ret;

	if (!i || !j)
		return 0;

	if (A[i] == B[j]) {
		ret = printsol(i - 1, j - 1);
		if (ret)
			printf(" ");
		printf("%d", A[i]);
		ret++;
	} else {
		if (maxlen[i][j - 1] == maxlen[i][j])
			ret = printsol(i, j - 1);
		else
			ret = printsol(i - 1, j);
	}

	return ret;
}

int main()
{
	int M, N, i, j;

	freopen("cmlsc.in", "rt", stdin);
	freopen("cmlsc.out", "wt", stdout);

	scanf("%d %d", &M, &N);
	for (i = 1; i <= M; i++)
		scanf("%d", A + i);
	for (i = 1; i <= N; i++)
		scanf("%d", B + i);

	for (i = 1; i <= M; i++) {
		for (j = 1; j <= N; j++) {
			maxlen[i][j] = max(maxlen[i][j - 1], maxlen[i - 1][j]);
			if (A[i] == B[j] && maxlen[i][j] < maxlen[i - 1][j - 1] + 1)
				maxlen[i][j] = maxlen[i - 1][j - 1] + 1;
		}
	}

	printf("%d\n", maxlen[M][N]);
	printsol(M, N);
	printf("\n");

	return 0;
}
