#include<fstream.h>
#include<stdio.h>
ifstream f("cmscl.in");
ofstream g("cmscl.out");
long a[1050],b[1050],poz[1050];
long v[1025][1025];
long i,j,k,h;
int main() {
	FILE * stefi;
	stefi=fopen("cmlsc.in","r");
	fscanf(stefi,"%u%u",&k,&h);
	for (i=1;i<=k;i++)
		fscanf(stefi,"%u",&a[i]);
	for (i=1;i<=h;i++)
		fscanf(stefi,"%u",&b[i]);
	for (i=1;i<=h;i++)
	{	for (j=1;j<=k;j++)
		{	if (b[i]==a[j]) v[i][j]=v[i-1][j-1]+1;
			else 
			{	if (v[i-1][j]>v[i][j-1]) v[i][j]=v[i-1][j];
				else v[i][j]=v[i][j-1];
			}
		}
	}
	g<<v[h][k]<<'\n';
	i=1;
	while (k&&h)
	{	if (a[k]==b[h]) 
		{	poz[i]=a[k]; k--; h--; i++; }
		else 
			if (v[h][k]==v[h][k-1]) k--;
			else h--;
	}
	for (k=i-1;k>0;k--)
		g<<poz[k]<<' ';
	g<<'\n';
	f.close();
	g.close();
	return 0;
}