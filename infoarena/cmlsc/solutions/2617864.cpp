#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
int matrix[2000][2000];
int cmlsc(int a[], int b[], int n, int m)
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (a[i] == b[j])
				matrix[i + 1][j + 1] = matrix[i][j] + 1;
			else
				matrix[i + 1][j + 1] = max(matrix[i + 1][j], matrix[i][j + 1]);
		}
	}
	return matrix[n][m];
}

int main()
{
	FILE* fin = fopen("cmlsc.in", "r");
	if (fin == NULL)
		exit(0);
	FILE* fout = fopen("cmlsc.out", "w");
	if (fout == NULL)
		exit(0);

	int n, m, a[2000], b[2000];
	fscanf(fin, "%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		fscanf(fin, "%d", &a[i]);
	for (int i = 0; i < m; i++)
		fscanf(fin, "%d", &b[i]);

	cmlsc(a, b, n-1, m-1);

	int k = matrix[n][m];
	int i = n - 1,j=m-1,sol[2000];
	while (k)
	{
		while (a[i] != b[j])
		{
			if (matrix[i][j+1] > matrix[i+1][j])
				i--;
			else
				j--;
		}
		sol[--k] = a[i];
		i--; j--;
	}
	fprintf(fout, "%d\n", matrix[n][m]);
	for (i=0; i <matrix[n][m]; i++)
		fprintf(fout,"%d ", sol[i]);
}