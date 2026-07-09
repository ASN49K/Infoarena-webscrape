#include <cstdio>
#define max(a, b) ((a>b)?a:b)
#define DIM 1030

int v1[DIM], v2[DIM], a[DIM][DIM], n, m;
FILE *out = fopen("cmlsc.out", "w");


void afis(int i, int j)
{
	if (i != 0 && j != 0)
		if (v1[i] == v2[j])
			 afis(i-1, j-1), fprintf(out, "%d ", v1[i]);
		else
			if (a[i-1][j] > a[i][j-1])
				afis(i-1, j);
			else
				afis(i, j-1);
}


int main()
{
	FILE *f = fopen("cmlsc.in", "r");
	fscanf(f, "%d%d", &n, &m);
	int i, j;
	for (i = 1; i <= n; i++)
		fscanf(f, "%d", &v1[i]);

	for (i = 1; i <= m; i++)
		fscanf(f, "%d", &v2[i]);

	fclose(f);

	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			if (v1[i] == v2[j])
				a[i][j] = a[i - 1][j - 1] + 1;
			else
				a[i][j] = max(a[i-1][j], a[i][j-1]);


	fprintf(out, "%d\n", a[n][m]);

	afis(n, m);

	fclose(out);
	return 0;
}

