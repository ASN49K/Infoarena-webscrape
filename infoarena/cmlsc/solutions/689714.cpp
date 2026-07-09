#include<stdio.h>
#define MAX(a,b) a>b?a:b
#define NMAX 1025

FILE *fin = fopen("cmlsc.in","r");
FILE *fout = fopen("cmlsc.out","w");

int c[NMAX][NMAX],n,m,i,j,max,a[NMAX],b[NMAX],sol[NMAX];

int main()
{
	fscanf(fin,"%d%d",&n,&m);
	for(i=1;i<=n;i++)
		fscanf(fin,"%d",&a[i]);
	for(i=1;i<=m;i++)
		fscanf(fin,"%d",&b[i]);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i] == b[j])
				c[i][j] = c[i-1][j-1]+1;
			else
				c[i][j] = MAX(c[i-1][j],c[i][j-1]);
		}
	}
	int lg=0;
	for(i=n;i>=1;i--)
		for(j=m;j>=1;j--)
			if(a[i] == b[j])
				sol[++lg]=a[i];
			else
				if(c[i-1][j]<c[i][j-1])
					j--;
				else
					i--;
	fprintf(fout,"%d\n",c[n][m]);
	for(i=lg;i>=1;i--)
		fprintf(fout,"%d ",sol[i]);
	return 0;
}