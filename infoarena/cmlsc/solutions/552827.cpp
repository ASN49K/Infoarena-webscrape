#include<fstream>
using namespace std;
ofstream g("cmlsc.out");

int i,j,n,m,a[1025],b[1025],l[1025][1025];
void det()
{
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i]==b[j])
				l[i][j]=l[i-1][j-1]+1;
			else
				l[i][j]=max(l[i-1][j],l[i][j-1]);
}
void afis()
{
	int i,j,t=1;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(l[i][j]==t&&a[i]==b[j])
				g<<a[i]<<" ",t+=1;
}
int main()
{
	ifstream f("cmlsc.in");
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>a[i];
	for(j=1;j<=m;j++)
		f>>b[j];
	det();
	g<<l[n][m]<<"\n";
	afis();
	return 0;
}