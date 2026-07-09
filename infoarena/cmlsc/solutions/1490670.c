#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
void main()
{
	int n, m, a[100], x, i, j;
	FILE *f, *g;
	f = fopen("cmlsc.in", "r");
	g = fopen("cmlsc.out", "w");
	fscanf(f, "%d%d", &n, &m);
	for (i = 0; i < n; i++)
		fscanf(f, "%d", &a[i]);
	for (i = 0; i < m; i++)
	{
		fscanf(f, "%d", &x);
		for (j = 0; j < m; j++)
		if (a[j] == x)
			fprintf(g, "%d ", x);
	}
}