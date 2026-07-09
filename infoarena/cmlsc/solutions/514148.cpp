#include<fstream>
#define dim 1026
using namespace std;
int a[dim],b[dim],c[dim][dim],d[dim];
int n,m;
int i,j;
int h,k;
int nr;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int main()
{
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>a[i];
	for(j=1;j<=m;j++)
		f>>b[j];
	for(h=1;h<=n;h++)
	{
		for(k=1;k<=m;k++)
			if(a[h]==b[k])
				c[h][k]=c[h-1][k-1]+1;
			else
				if(c[h-1][k]<c[h][k-1])
					c[h][k]=c[h][k-1];
			else
				c[h][k]=c[h-1][k];
	}
	/*for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
			g<<c[i][j]<<" ";
		g<<"\n";
	}*/
	i=n;
	j=m;
	while(i!=0&&j!=0)
	{
		if(a[i]==b[j])
		{
			nr++;
			d[nr]=a[i];
			i--;
			j--;
		}
		else
			if(c[i-1][j]==c[i][j])
				i--;
			else
				j--;
	}
	for(i=nr;i>=1;i--)
		g<<d[i]<<" ";
	return 0;
}

				