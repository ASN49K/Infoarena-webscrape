#include <cstdio>
#include <iostream>
FILE *fin=fopen("cmlsc.in", "r"), *fout=fopen("cmlsc.out", "w");

using namespace std;

int m, n, i, b[1025], a[1025], lung[1025][1025], j, x, maxi, v[1025];
int main()
{
	fscanf(fin, "%d%d", &m, &n);
	for(i=0;i<=m-1;i++)
		fscanf(fin, "%d", &a[i]);
	for(i=0;i<=n-1;i++)
		fscanf(fin, "%d", &b[i]);


	if(a[0]==b[0])
		lung[0][0]=1;
	for(i=1;i<=m-1;i++)
		if(a[i]==b[0])
			lung[i][0]=1;
		else lung[i][0]=lung[i-1][0];
	for(i=1;i<=n-1;i++)
		if(a[0]==b[i])
			lung[0][i]=1;
		else lung[0][i]=lung[0][i-1];

	for(i=1;i<=m-1;i++)
		for(j=1;j<=n-1;j++)
		{
			x=0;
			if(a[i]==b[j])
				x=lung[i-1][j-1]+1;
			maxi=x;
			if(lung[i-1][j]>maxi)
				maxi=lung[i-1][j];
			if(lung[i][j-1]>maxi)
				maxi=lung[i][j-1];
			lung[i][j]=maxi;
		}
	fprintf(fout, "%d\n", lung[m-1][n-1]);

	i=m-1;
	j=n-1;
	x=0;
	while(i>=0&&j>=0)
	{
		if(a[i]==b[j])
		{
			v[x]=a[i];
			x++;
			i--; j--;
		}
		else if(i-1>=0&&lung[i][j]==lung[i-1][j])
			i--;
		else j--;
	}
	for(i=x-1;i>=0;i--)
		fprintf(fout, "%d ", v[i]);
	return 0;
}
