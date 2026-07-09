#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[1050],b[1050],x[1050][1050],v[1050],i,j,k,maxim;
int main()
{
	f>>n>>m;
	for(i=1;i<=n;i++)
	{
		f>>a[i];
	}
	for(i=1;i<=m;i++)
	{
		f>>b[i];
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i]==b[j])
			{
				x[i][j]=1;
				if(i+j>maxim)
				{
					maxim=i+j;
					v[k++]=a[i];
				}
			}
		}
	}
	g<<k<<'\n';
	for(i=0;i<k;i++)
	{
		g<<v[i]<<' ';
	}
	return 0;
}
