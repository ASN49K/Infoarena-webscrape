#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int m,n,j,a[10],b[10],i,c[20],k;
int main ()
{
	f>>m>>n;
	for(i=1;i<=m;i++)
		f>>a[i];
	for(j=1;j<=n;j++)
		f>>b[j];
	for(i=1;i<=m;i++)
	{
		int ok=0;
		for(j=1;j<=n&& !ok;j++)
			if(a[i]==b[j])
				ok=1;
		if(ok==1)
				c[++k]=a[i];
	}
	g<<k<<'\n';
	for(i=1;i<=k;i++)
		g<<c[i]<<" ";
	return 0;
}