#include<fstream>
#define max(a,b) (a>b?a:b)
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int v[1025][1025];
int a[1025],b[1025];
int i,j,n,m;
void afiseaza(int i,int j)
{
	if(v[i][j])
	if(a[i]==b[j])
	{
		afiseaza(i-1,j-1);
		out<<a[i]<<' ';
	}
	else if(v[i][j]==v[i-1][j])
		afiseaza(i-1,j);
	else if(v[i][j]==v[i][j-1])
		afiseaza(i,j-1);
}
int main ()
{
	in>>n>>m;
	for(i=1;i<=n;i++)
		in>>a[i];
	for(i=1;i<=m;i++)
		in>>b[i];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
			if(a[i]==b[j])
				v[i][j]=v[i-1][j-1]+1;
			else
				v[i][j]=max(v[i-1][j],v[i][j-1]);
	}
	out<<v[n][m]<<'\n';
	afiseaza(n,m);
	return 0;
}