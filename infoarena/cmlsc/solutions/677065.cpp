#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
unsigned i,j,v[1025][1025],s1[1025],s2[1025],m,n,s,var;
unsigned max(unsigned x, unsigned y)
{
	if(x>y)
		return x;
	return y;
}
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
			for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(s<v[i][j])s=v[i][j];
		g<<s<<'\n';
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(v[i][j]>var&&s1[i]==s2[j])
				var=v[i][j],g<<s1[i]<<' ';
			g<<'\n';
	f.close();
	g.close();
	return 0;
}