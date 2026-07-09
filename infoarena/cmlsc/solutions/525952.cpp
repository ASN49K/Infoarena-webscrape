#include<fstream>
#define dim 1026
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[dim],b[dim];
int c[dim][dim];
int d[dim];
int i,j;
int n,m;
int nr=1;
int main()
{
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>a[i];
	for(j=1;j<=m;j++)
		f>>b[j];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i]==b[j])
				c[i][j]=c[i][j-1]+1;
			else
				if(c[i][j-1]>c[i-1][j])
					c[i][j]=c[i][j-1];
				else
					c[i][j]=c[i-1][j];
				
		/*for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
				g<<c[i][j]<<" ";
			g<<"\n";
		}
		g<<"\n";*/
		g<<c[n][m]<<"\n";
		i=n;
		j=m;
		while(i!=0&&j!=0)
		{
			if(a[i]==b[j])
			{
				d[nr]=a[i];
				nr++;
				i--;
				j--;
			}
			else
				if(c[i][j]==c[i-1][j])
					i--;
				else
					j--;
		}
		for(i=nr-1;i>0;i--)
			g<<d[i]<<" ";
				
		return 0;
}		
