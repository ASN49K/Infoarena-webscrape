#include<iostream>
#include<fstream>
using namespace std;
int d[1025][1025],a[1025],b[1025],x[1025];
int maxim(int a, int b)
{
	if(a>=b)
		return a;
	return b;
}
int main ()
{
	int n,i,j,m,nr;
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>a[i];
	for(i=1;i<=m;i++)
		f>>b[i];
	f.close();
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i]==b[j])
				d[i][j]=1+d[i-1][j-1];
			else d[i][j]=maxim(d[i-1][j],d[i][j-1]);
	i=n;
	j=m;
	nr=0;
	while((i)&&(j)) 
		if(a[i]==b[j]) {
			nr++;
			x[nr]=a[i];
			i--;
			j--;
		}
		else if(d[i-1][j]>d[i][j-1])
			i--;
		else j--;
	g<<d[n][m]<<'\n';
	for(i=nr;i>=1;i--)
		g<<x[i]<<" ";
	g.close();
	return 0;
}