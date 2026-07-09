#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
long n,m,i,j,v[1300],maxx,v2[1300],sav,k,nr[1300],l[1300];
int main()
{
	f>>n>>m;
	for (i=1;i<=n;i++)
		f>>v[i];
	for (i=1;i<=m;i++)
		f>>v2[i];
	for (i=n;i>=1;i--)
	{
		for (j=m;j>=1;j--)
			if (v[i]==v2[j])
			{
				sav=maxx=0;
				for (k=j+1;k<=m;k++)
					if (nr[k]>maxx)
					{
						maxx=nr[k];
						sav=k;
					}
				maxx++;
				nr[j]=maxx;
				if (sav!=0)
					l[j]=sav;
				else
					l[j]=-1;
			}
	}
	maxx=0;
	for (i=1;i<=m;i++)
	{
		if (nr[i]>maxx)
		{
			maxx=nr[i];
			sav=i;
		}
	}
	g<<maxx<<'\n';
	while (sav!=-1)
	{
		g<<v2[sav]<<' ';
		sav=l[sav];
	}
	f.close();
	g.close();
	return 0;
}
