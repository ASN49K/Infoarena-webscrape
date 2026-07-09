#include <stdio.h>

#define MN (1024+1)

short d[MN][MN];
short n1[MN], n2[MN], n[MN];

int main()
{
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	int N1, N2, N;
	int i, j;
	scanf("%d %d", &N1, &N2);
	for(i = 1; i <= N1; ++i)
		scanf("%hd", &n1[i]);
	for(i = 1; i <= N2; ++i)
		scanf("%hd", &n2[i]);

	for(i = 1; i <= N1; ++i) for(j = 1; j <= N2; ++j) {
		if(n1[i] == n2[j])
			d[i][j] = d[i-1][j-1]+1;
		if(d[i-1][j] > d[i][j])
			d[i][j] = d[i-1][j];
		if(d[i][j-1] > d[i][j])
			d[i][j] = d[i][j-1];
	}

	/*
	for(i = 0; i <= N1; ++i) {
		for(j = 0; j <= N2; ++j)
			printf("%d(%d,%d) ", d[i][j], p[i][j][0], p[i][j][1]);
		printf("\n");
	}
	*/

	for(N = 0, i = N1, j = N2; i > 0 && j > 0; ) {
		if(n1[i] == n2[j]) {
			n[N++] = n1[i];
			--i; --j;
		} else if(d[i-1][j] < d[i][j-1])
			--j;
		else --i;
	}

	printf("%d\n", N);
	for(i = N-1; i > 0; --i)
		printf("%d ", n[i]);
	printf("%d\n", n[i]);

	return 0;
}
