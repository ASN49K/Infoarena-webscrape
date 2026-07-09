#include <cstdio>

int const NMAX = 1025;

inline short max(short &x, short &y)
{
	return x > y ? x : y;
}

int main()
{
	short N, M, i, j, aux, r = 0;
	short x[NMAX] = {}, y[NMAX] = {}, rasp[NMAX];
	short lcs[NMAX][NMAX] = {};
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	scanf("%hd %hd\n", &N, &M);
	for (i = 1; i <= N; ++i) {
		scanf("%hd ", &aux);
		x[i] = aux;
	}
	for (i = 1; i <= M; ++i) {
		scanf("%hd ", &aux);
		y[i] = aux;
	}
	for (i = 1; i <= N; ++i)
		for (j = 1; j <= M; ++j)
			if (x[i] == y[j]) lcs[i][j] = 1 + lcs[i - 1][j - 1];
			else lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
	
	for (i = N, j = M; j && i;) {
		if ( x[i] == y[j] ) {
			rasp[r++] = x[i];
			--i; --j;
		}
		else
			if (lcs[i][j - 1] < lcs[i - 1][j]) --i;
			else --j;
	}
	
	printf("%hd\n", r);
	for (i = r - 1; i >= 0; --i)
		printf("%d ", (int)rasp[i]);
	printf("\n");
	return 0;
}
