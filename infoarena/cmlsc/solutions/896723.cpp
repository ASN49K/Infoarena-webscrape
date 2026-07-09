#include<iostream>
#include<fstream>
using namespace std;
int v1[1025],v2[1025],a[1025][1025],sir[1025];
 
int maxab(int a, int b)
{
	if(a>b)
		return a;
	return b;
}
int main()
{
	int i,j,n,m,nr=0;
	ifstream f("cmlsc.in");
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>v1[i];
	for(i=1;i<=m;i++)
		f>>v2[i];
	f.close();
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			if(v1[i]==v2[j])
				a[i][j]=a[i-1][j-1]+1;
			else 
				a[i][j]=maxab(a[i-1][j],a[i][j-1]);
		}
	i=n;
	j=m;
	while(i)
    {
        if(v1[i]==v2[j])
		{
			sir[++nr]=v1[i];
			i--;
			j--;
		}
        else if(a[i-1][j]<a[i][j-1])
			j--;
        else 
			i--;
    }
	ofstream g("cmlsc.out");
	g<<nr<<'\n';
	for(i=nr;i>=1;i--)
		g<<sir[i]<<' ';
	g<<'\n';
}