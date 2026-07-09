#include <cstdio>
#include <iostream>
#include <fstream>
#include <list>
#include <limits.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stdio.h>
#include <algorithm>
#include <deque>
#include <string.h>
//#include <math.h>
#define NMAX 1025

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
int a[NMAX],b[NMAX];
int mat[NMAX][NMAX];
int dir[NMAX][NMAX];//0-diag; 1-up;-1-left
int secv[NMAX];
int main()
{
	FILE *f=fopen("cmlsc.in", "r");
	FILE *g=fopen("cmlsc.out","w+");
	int n,m;
	fscanf(f,"%d %d",&n,&m);	
	for (int i=1;i<=n;i++)
		fscanf(f, "%d",&a[i]);
	for (int j=1;j<=m;j++)
		fscanf(f,"%d",&b[j]);
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			mat[i][j] = 0;
    for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			if (a[i] == b[j])
			{
				mat[i][j] = mat[i-1][j-1]+1;
				dir[i][j] = 0;
			}
			else
			{
				int k =MAX(mat[i-1][j],mat[i][j-1]);
				if (mat[i-1][j]>mat[i][j-1]){
					mat[i][j] = mat[i-1][j];
					dir[i][j] = 1;
				}
				else
				{
					mat[i][j] = mat[i][j-1];
					dir[i][j] = -1;
				}
			}			
		}
	fprintf(g,"%d\n",mat[n][m]);
	int nr = mat[n][m];
	int x=n;int y=m;
	int i =nr-1;
	while(i>=0)
	{
		if (dir[x][y]==0)
		{
			secv[i] = a[x];
			i--;
			x--;
			y--;
		}
		else if (dir[x][y]==-1)
		{
			y--;
		}
		else x--;
	}
	for (int i=0;i<nr;i++)
		fprintf(g,"%d ",secv[i]);
	fprintf(g,"\n");
	fclose(f);
	fclose(g);
	return 0;
}