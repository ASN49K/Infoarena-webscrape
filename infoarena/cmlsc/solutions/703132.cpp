#include <fstream>
using namespace std;
int a[1025],b[1025],d[1025][1025],p[1025],c;
int main()
{
	int i,j,m,n;
	
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	
	f>>m>>n;
	for(i=1;i<=m;i++)
		f>>a[i];
	for(i=1;i<=n;i++)
		f>>b[i];
	
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		{
			if(a[i]==b[j]) d[i][j]=1+d[i-1][j-1];
			else d[i][j]=max(d[i-1][j],d[i][j-1]);
		}
	
	for(i=m,j=n;i; )
		if(a[i]==b[j]) 
			p[++c]=a[i],--i,--j;
		else if(d[i-1][j]<d[i][j-1]) 
			--j;
		else --i;
	
	g<<c<<'\n';
	for (i=c;i;i--)
		g<<p[i]<<' ';
	f.close();g.close();
	return 0;
}
