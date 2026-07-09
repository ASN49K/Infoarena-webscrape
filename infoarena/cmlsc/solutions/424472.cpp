#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025],b[1025],n,m,c[1025],maxim,maxl;
int main()
{
	int i,j,x,y,ok;
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>a[i];
	for(i=1;i<=m;i++)
		f>>b[i];
	for(i=1;i<=n;i++)
	{
		ok=0;
		for(j=1;j<=m;j++)
		{
			if(a[i]==b[j])
			{
				ok=1;
				j=m+1;
			}
		}
		if(!ok)
			a[i]=257;
	}
	for(i=n;i>=1;i--)
	{
		maxim=0;
		if(a[i]<257)
		{
			for(j=i+1;j<=n;j++)
			{
				if(a[i]<a[j]&&maxim<c[j])
				{
					maxim=c[j];
					if(maxl<c[j]+1)
					{
						maxl=c[j]+1;
						x=i;
					}
				}
			}
			c[i]=maxim+1;
		}
	}
	g<<maxl<<endl<<a[x]<<" ";
	y=a[x];
	for(i=x+1;i<=n;i++)
	{
		if(y<a[i]&&c[i]==maxl-1&&a[i]<257)
		{
			y=a[i];
			maxl--;
			g<<a[i]<<" ";
		}
	}
	return 0;
}
