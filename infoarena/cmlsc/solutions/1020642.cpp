#include <fstream>
using namespace std;
int m,n,nmx,a[1025],b[1025],pd[1025][1025],rez[1025],i,j;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int main()
{
	fin>>m>>n;
	for(i=1;i<=m;++i)
		fin>>a[i];
	for(i=1;i<=n;++i)
		fin>>b[i];
	for(i=1;i<=m;++i)
		for(i=1;i<=n;++i)
			if(a[i]==b[j])
				pd[i][j]=pd[i-1][j-1]+1;
			else
				pd[i][j]=max(pd[i-1][j],pd[i][j-1]);
	for (i=m,j=n;i;)
		if (a[i]==b[j])
		{
			rez[++nmx]=a[i];
			i--;
			j--;
		}
		else if(pd[i-1][j]<pd[i][j-1])
			j--;
		else
			i--;
	fout<<nmx<<"\n";
	for (i=nmx;i;--i)
		fout<<rez[i]<<" ";
	fout<<"\n";
	return 0;
}
