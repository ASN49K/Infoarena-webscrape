#include <stdio.h>
#define maxn 1030

int m, n, a[maxn], b[maxn], d[maxn][maxn], s[maxn];
FILE *fin = fopen("cmlsc.in", "rt"), *fout = fopen("cmlsc.out", "wt");

int main()
{
	int i=0, j=0, k=0;

	

	fscanf(fin, "%d %d", &m, &n);
	for (i=1; i <= m; i++) fscanf(fin, "%d", &a[i]);
	for (i=1; i <= n; i++) fscanf(fin, "%d", &b[i]);

	for (i=1; i <= m; i++)
		for (j=1; j <= n; j++)
			if (a[i] == b[j]) 
				d[i][j] = d[i-1][j-1] + 1;
			else
				if (d[i-1][j] > d[i][j-1])
					d[i][j] = d[i-1][j];
				else
					d[i][j] = d[i][j-1];

	fprintf(fout, "%d\n", d[m][n]);
	i=m,j=n;
	while (d[i][j] != 0)
	{
		if (d[i][j] == d[i-1][j-1] + 1)
		{
			s[++k]=a[i];
			i--, j--;
		}
		if (d[i-1][j] == d[i][j-1])
			i--;
		else
			j--;
	}
	
	for (i=k; i > 0; --i) fprintf(fout, "%d ", s[i]);

	fclose(fin), fclose(fout);

	return 0;
}
