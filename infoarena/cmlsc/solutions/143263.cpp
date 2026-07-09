#include <fstream.h>
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int x,v[1024],i,n,m,rez[1024],k;
int main()
{f>>n>>m;
for (i=1;i<=n;i++)
	f>>v[i];
k=0;
for (i=1;i<=m;i++)
	{f>>x;
	for (int j=1;j<=n;j++)
		if (x==v[j])
			rez[++k]=x;
	}
g<<k<<endl;
for (i=1;i<=k;i++)
	g<<rez[i]<<" ";
g<<endl;
return 0;
}