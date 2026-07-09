#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
unsigned i,j,v[1025][1025],s1[1025],s2[1025],m,n,s,sol[1025];

int main()
{
	f>>m>>n;
	for(i=1;i<=m;i++)
		f>>s1[i];
	for(j=1;j<=n;j++)
		f>>s2[j];
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(s1[i]==s2[j])
				v[i][j]=v[i-1][j-1]+1;
			else v[i][j]=max(v[i-1][j],v[i][j-1]);
			g<<v[m][n]<<'\n';
	i=m;j=n;
	s=v[i][j];
	while(s)
	{
		if(s1[i]==s2[j])
			{
				sol[s]=s1[i];
				i--;
				j--;
				s--;
			}
		else
			if(v[i-1][j]>v[i][j-1])
				i--;
			else j--;
	}
		for(i=1;i<=v[m][n];i++)
			g<<sol[i]<<' ';
			g<<'\n';
	f.close();
	g.close();
	return 0;
}