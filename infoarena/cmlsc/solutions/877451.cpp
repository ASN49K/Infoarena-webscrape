#include<iostream>
#include <stdio.h>
#include <math.h>
#include <queue>
using namespace std;
#define NMAX 1024
int a[NMAX+1], b[NMAX+1], n, m, S[NMAX+1][NMAX+1];
int max(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}
void citire()
{
	FILE *f = fopen("cmlsc.in", "r");
	fscanf(f, "%d %d", &n, &m);
	for (int i=1; i<=n; i++)
	{
		fscanf(f, "%d", &a[i]);
	}
	for (int i=1; i<=m; i++)
	{
		fscanf(f, "%d", &b[i]);
	}
	fclose(f);
}
void drum()
{
	FILE *f = fopen("cmlsc.out", "w");
	fprintf(f, "%d\n", S[n][m]);
	int drum[NMAX];
	int i = n, j = m, nr = S[n][m], k = 0 ;
	while (nr)
	{
		if (a[i] == b[j])
		{
			drum[++k] = a[i];
			i--;
			j--;
			nr--;
		}
		else
			if (S[i][j] == S[i-1][j])
				i--;
			else
				j--;
	}
	for (int i=k; i>=1; i--)
		fprintf(f, "%d ", drum[i]);
	fclose(f);
}
int main()
{
	citire();
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (a[i] == b[j])
				S[i][j] = S[i-1][j-1] + 1;
			else
				S[i][j] = max(S[i-1][j], S[i][j-1]);
		}
	}
	drum();
	return 0;
}