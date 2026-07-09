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
	if (n == -1 || m == -1)
		return 0;
	if (matrix[n][m])
		return matrix[n][m];
	if (a[n] == b[m])
	{
		return matrix[n - 1][m - 1] = cmlsc(a, b, n - 1, m - 1) + 1;
	}
	else
		return max(cmlsc(a, b, n - 1, m), matrix[n][m - 1] = cmlsc(a, b, n, m - 1));
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

	matrix[n-1][m-1]=cmlsc(a, b, n-1, m-1);

	int k = matrix[n - 1][m - 1];
	int i = n - 1,j=m-1,sol[2000];
	while (k)
	{
		while (a[i] != b[j])
		{
			if (matrix[i - 1][j] > matrix[i][j - 1])
				i--;
			else
				j--;
		}
		sol[--k] = a[i];
		i--; j--;
	}
	fprintf(fout, "%d\n", matrix[n - 1][m - 1]);
	for (i=0; i <matrix[n-1][m-1]; i++)
		fprintf(fout,"%d ", sol[i]);
}