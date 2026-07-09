#include<fstream>
#include<cmath>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,a[1025],b[1025],sir[1025],x(0),d[1025][1025],i,j;

int main()
{
	fin>>m;
	fin>>n;
	for(i=1;i<=m;++i)
		fin>>a[i];
	for(i=1;i<=n;++i)
		fin>>b[i];
	for(i=1;i<=m;++i)
		for(j=1;j<=n;++j)
			if(a[i]==b[j])
				d[i][j]=d[i-1][j-1]+1;
			else
				d[i][j]=max(d[i-1][j],d[i][j-1]);
	for(i=m,j=n;i;)
			if(a[i]==b[j])
				sir[++x]=a[i],
				--i,
				--j;
			else if(d[i-1][j]>d[i][j-1])
					--i;
				else --j;
	fout<<d[m][n]<<'\n';
	for(i=x;i>0;--i)fout<<sir[i]<<" ";
	return 0;
}
