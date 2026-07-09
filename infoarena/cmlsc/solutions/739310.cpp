#include<stdio.h>
#define NMAX 1050
#define MMAX 1050
int n, m, i, j, v[ NMAX ], w[ MMAX ], A[ NMAX ][ MMAX ], s[ NMAX ];
int max(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;
}
void read()
{
	FILE *f = fopen("cmlsc.in", "r");
	fscanf(f, "%d %d", &n, &m);
	for(i = 1; i <= n; i++)
		fscanf(f, "%d", &v[i]);
	for(i = 1; i <= m; i++)
		fscanf(f, "%d", &w[i]);
	fclose(f);
}
void dynamic()
{
	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
			if(v[i] != w[j])
				A[i][j] = max(A[i-1][j], A[i][j-1]);
			else
				A[i][j] = A[i-1][j-1] + 1;
}
void build()
{
	i = n; j = m;
	while(i)
	{
		if(v[i] == w[j])
			s[0]++, s[ s[0] ] = v[i], i--, j--;
		else
			if(A[i-1][j] > A[i][j-1])
				i--;
			else
				j--;
	}
}
void write()
{
	FILE *g = fopen("cmlsc.out", "w");
	fprintf(g, "%d\n", A[n][m]);
	for(i = s[0]; i; i--)
		fprintf(g, "%d ", s[i]);
	fprintf(g, "\n");
	fclose(g);
}
int main()
{
	read();
	dynamic();
	build();
	write();
	return 0;
}

