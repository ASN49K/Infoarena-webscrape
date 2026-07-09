#include <stdio.h>
#define IN "cmlsc.in"
#define OUT "cmlsc.out"
#define NMAX 1030

FILE * fin = fopen(IN, "r");
FILE * fout = fopen(OUT, "w");

int a[NMAX], b[NMAX], v[NMAX];
int lcs[NMAX][NMAX];

int maxim(int, int);
int main()
{
	int n, m, i, j, nr = 0;

	fscanf(fin, "%d%d", &n, &m);
	for (i = 1; i <= n; i++)
		fscanf(fin, "%d", &a[i]);
	for (i = 1; i <= m; i++)
		fscanf(fin, "%d", &b[i]);

	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
		{
			if (a[i] == b[j])
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else
				lcs[i][j] = maxim(lcs[i][j - 1], lcs[i - 1][j]);
		}

	fprintf(fout, "%d\n", lcs[n][m]);

	i = n; j = m;
	while (i>0 && j>0)
	{
		if (a[i] == b[j])
		{
			v[++nr] = a[i];
			i--;
			j--;
		}
		else
		{
			if (lcs[i][j - 1]>lcs[i - 1][j])
				j--;
			else
				i--;
		}
	}

	fprintf(fout, "%d", v[nr]);
	for (i = nr - 1; i >= 1; i--)
		fprintf(fout, " %d", v[i]);
	fprintf(fout, "\n");

	fclose(fin);
	fclose(fout);
	return 0;
}

int maxim(int a, int b)
{
	if (a>b) return a;
	return b;
}