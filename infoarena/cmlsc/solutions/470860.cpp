// CelMaiLungSubsirComun.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include "stdio.h"

FILE *f=fopen("cmlsc.in", "r");
FILE *g=fopen("cmlsc.out", "w");

int a[1025], b[1025], n, m, rec[1025];
int v[1025][1025];


void read()
{
	fscanf(f, "%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		fscanf(f, "%d", &a[i]);
	for (int j=1; j<=m; j++)
		fscanf(f, "%d", &b[j]);

}


int maxim(int x, int y)
{
	if (x>y) return x;
	return y;
}


void dinamica()
{
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
		{
			if (a[i]==b[j])
				v[i][j]=v[i-1][j-1]+1;
			else
				v[i][j]=maxim(v[i-1][j], v[i][j-1]);
		}
}


void program()
{
	read();
	dinamica();
	int max=0, maxi=0;
	for (int i=1; i<=m; i++)
		if (v[n][i]>max) 
		{
			max=v[n][i];
			maxi=i;
		}
	fprintf(g, "%d\n", max);

	int k=n, l=m;
	int ok=1;
	while (k>0 && l>0)
	{
		if (a[k]==b[l])
		{
			rec[++rec[0]]=a[k];
			k--;
			l--;
		}
		else
		{
			if (v[k][l-1]>v[k-1][l])
				l--;
			else 
				k--;
		}
	}
	for (int o=rec[0]; o>=1; o--)
		fprintf(g, "%d ", rec[o]);

}


int main()
{
	program();
	return 0;
}

