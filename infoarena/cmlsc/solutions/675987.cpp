#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[1050],b[1050],x[1050][1050],v[1050],i,j,k,e;
void afisare(int i,int j)
{
	if(i!=0 && j!=0)
	{
		if(a[i]==b[j])
		{
			afisare(i-1,j-1);
			g<<a[i]<<' ';
		}
		else
		{
			if(x[i-1][j]<x[i][j-1])
			{
				afisare(i,j-1);
				//g<<a[i]<<' ';
			}
			else
			{
				afisare(i-1,j);
				//g<<b[j]<<' ';
			}
		}
	}
}
int main()
{
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>a[i];
	for(i=1;i<=m;i++)
		f>>b[i];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i]==b[j])
			{
				x[i][j]=x[i-1][j-1]+1;
			}
			else
			{
				if(x[i-1][j]>x[i][j-1])
				{
					x[i][j]=x[i-1][j];
				}
				else
				{
					x[i][j]=x[i][j-1];
				}
			}
		}
	}
	g<<x[n][m]<<'\n';
	afisare(n,m);
	return 0;
}
