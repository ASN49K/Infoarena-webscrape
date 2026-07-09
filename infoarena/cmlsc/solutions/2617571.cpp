#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int sol[1000];

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int cmlsc(int a[], int b[], int n, int m,int k)
{
	if (n == -1 || m == -1)
		return k;
	if (a[n] == b[m])
	{
		sol[k] = a[n];
		return cmlsc(a, b, n - 1, m - 1, k+1);
	}
	else
		return max(cmlsc(a,b,n-1,m,k),cmlsc(a, b,n, m - 1, k));
}

int main()
{
	FILE* fin = fopen("cmlsc.in", "r");
	if (fin == NULL)
		exit(0);
	FILE* fout = fopen("cmlsc.out", "w");
	if (fout == NULL)
		exit(0);

	int n, m, a[10000], b[10000];
	fscanf(fin, "%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		fscanf(fin, "%d", &a[i]);
	for (int i = 0; i < m; i++)
		fscanf(fin, "%d", &b[i]);

	int k = 0;
	k=cmlsc(a, b, n-1, m-1, k);

	fprintf(fout, "%d\n", k);
	for (int i = k-1; i >=0 ; i--)
		fprintf(fout,"%d ", sol[i]);
}