#include <fstream.h>

int n, m, a[1025], b[1025], c[10], x[1025][1025], i, j, k;

int max(int i, int j)
{
	if(i>j) return i;
	else return j;
}

int main()
{
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	f>>n>>m;
	for(i=1; i<=n; i++)
		f>>a[i];
	for(j=1; j<=m; j++)
		f>>b[j];

	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++)
		{
			x[i][j]=max(x[i][j-1], x[i-1][j]);
			if(a[i] == b[j])
				x[i][j]=max(x[i][j], x[i-1][j-1]+1);
		}
	g<<x[n][m]<<"\n";

	i=n; j=m;
	while(x[i][j])
	{
		if(a[i]==b[j])
		{
			c[++k]=a[i];
			i--; j--;
			continue;
		}
		if(x[i-1][j]<x[i][j-1])
		{ j--; continue; }
		i--;
	}

	for(i=k; i>=1; i--)
		g<<c[i]<<" ";
return 0;
}
