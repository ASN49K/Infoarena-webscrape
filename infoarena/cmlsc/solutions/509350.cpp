#include<fstream>
using namespace std;
int a[1026],b[1026],c[1026][1026];
int i,j,k,h;
int n,m,nr=0;
int main()
{
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>a[i];
	for(j=1;j<=m;j++)
		f>>b[j];
	for(k=1;k<=n;k++)
	{
		for(h=1;h<=m;h++)
			if(a[k]==b[h])
				c[k][h]=c[k-1][h-1]+1;
			else
				if(c[k-1][h]>c[k][h-1])
					c[k][h]=c[k-1][h];
				else
					c[k][h]=c[k][h-1];
	}
	/*for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
			g<<c[i][j]<<" ";
			g<<"\n";
	}*/
	g<<c[n][m]<<"\n";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
			if(c[i][j]==nr+1)
			{
				g<<a[i]<<" ";
				nr++;
			}
			else
				if(nr==c[n][m])
					break;
	
	}
	return 0;
}
