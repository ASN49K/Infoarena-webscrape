#include<iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
#define NMAX 256
int n, m, vn[NMAX+1], vm[NMAX+1], i, Min;
FILE *g = fopen("cmlsc.out", "w");
void citire()
{
	int x;
	FILE *f = fopen("cmlsc.in", "r");
	fscanf(f, "%d %d", &n, &m);
	for (int i=1; i<=n; i++)
		fscanf(f, "%d", &vn[i]);
	for (int i=1; i<=m; i++)
		fscanf(f, "%d", &vm[i]);
	fclose(f);
}
int main()
{
	citire();
	int rez[NMAX], k=1;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
			if(vn[i] ==  vm[j])
				rez[k++] = vn[i];
	}
	fprintf(g, "%d", k-1);
	fprintf(g, "\n");
	for(int i=1; i<k; i++)
		fprintf(g, "%d ", rez[i]);
	fclose(g);
	return 0;
}