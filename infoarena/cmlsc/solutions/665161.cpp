#include<fstream>
#include<algorithm>
using namespace std;
int v[1025],vv[1025],com[1025][1025],rez[1025];
int n,m,nrez;
int main()
{
	ifstream fin("cmlsc.in");
	ofstream fout("cmlsc.out");
	fin>>n>>m;
	for(int i=1;i<=n;++i)
		fin>>v[i];
	for(int i=1;i<=m;++i)
		fin>>vv[i];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(v[i]==vv[j])
				com[i][j]=com[i-1][j-1]+1;
			else
				com[i][j]=max(com[i-1][j],com[i][j-1]);
	int i=n,j=m;
	while(i)
		if(v[i]==vv[j])
		{
			++nrez;
			rez[nrez]=v[i];
			--i;
			--j;
		}
		else
			if(com[i-1][j]>com[i][j-1])
				--i;
			else
				--j;
	fout<<nrez<<"\n";
	for(int i=nrez;i>0;--i)
		fout<<rez[i]<<" ";
}