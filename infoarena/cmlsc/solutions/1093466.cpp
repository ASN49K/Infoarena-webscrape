#include<fstream>
using namespace std;
int maxim(int a , int b)
{
	if(a>b)
		return a;
	return b;
}
int a[1024],b[1024],m,n,d[1024][1024],i,j;
int main()
{
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>a[i];
	for(i=1;i<=m;i++)
		f>>b[i];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
			if(a[i]==b[j])
				d[i][j]=d[i-1][j-1]+1;
			else d[i][j]=maxim(d[i-1][j],d[i][j-1]);
	}
	g<<d[n][m]<<'\n';
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i]==b[j])
				g<<a[i]<<' ';
	f.close();
	g.close();
	return 0;
}

	