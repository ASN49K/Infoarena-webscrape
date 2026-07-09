#include <stdio.h>

#define MN (1024+1)

short d[MN][MN],
      p[MN][MN][2];
unsigned char n1[MN], n2[MN], n[MN];

int main()
{
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	int N1, N2, N;
	int i, j, k, l;
	scanf("%d %d", &N1, &N2);
	for(i = 1; i <= N1; ++i)
		scanf("%d", &n1[i]);
	for(i = 1; i <= N2; ++i)
		scanf("%d", &n2[i]);

	for(i = 1; i <= N1; ++i) for(j = 1; j <= N2; ++j) {
		if(n1[i] == n2[j]) {
			d[i][j] = d[i-1][j-1]+1;
			p[i][j][0] = i;
			p[i][j][1] = j;
		}
		if(d[i-1][j] > d[i][j]) {
			d[i][j] = d[i-1][j];
			p[i][j][0] = p[i-1][j][0];
			p[i][j][1] = p[i-1][j][1];
		}
		if(d[i][j-1] > d[i][j]) {
			d[i][j] = d[i][j-1];
			p[i][j][0] = p[i][j-1][0];
			p[i][j][1] = p[i][j-1][1];
		}
	}

	/*
	for(i = 0; i <= N1; ++i) {
		for(j = 0; j <= N2; ++j)
			printf("%d(%d,%d) ", d[i][j], p[i][j][0], p[i][j][1]);
		printf("\n");
	}
	*/

	n[0] = N = d[N1][N2];
	for(i = N1, j = N2; N > 0; --N) {
		k = p[i][j][0];
		l = p[i][j][1];
		i = k; j = l;
		n[N] = n1[i];
		--i; --j;
	}

	printf("%d\n", n[0]);
	for(i = 1; i < n[0]; ++i)
		printf("%d ", n[i]);
	printf("%d\n", n[i]);

	return 0;
}
