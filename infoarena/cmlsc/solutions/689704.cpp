#include<fstream.h>
#define MAX(a,b) a>b?a:b
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
namespace std;
int c[1025][1025],n,m,i,j,max,a[1025],b[1025],sol[1025];

int main()
{
	fin>>n>>m;
	for(i=1;i<=n;i++)
		fin>>a[i];
	for(i=1;i<=m;i++)
		fin>>b[i];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i] == b[j])
				c[i][j] = c[i-1][j-1]+1;
			else
				c[i][j] = MAX(c[i-1][j],c[i][j-1]);
		}
	}
	int lg=0;
	for(i=n;i>=1;i--)
		for(j=m;j>=1;j--)
			if(a[i] == b[j])
				sol[++lg]=a[i];
			else
				if(c[i-1][j]<c[i][j-1])
					j--;
				else
					i--;
	fout<<c[n][m]<<'\n';
	for(i=lg;i>=1;i--)
		fout<<sol[i]<<' ';
	return 0;
}