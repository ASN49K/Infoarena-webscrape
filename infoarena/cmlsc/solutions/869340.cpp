#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,v[1025],w[1025],a[1025][1025],p;
void citire()
{
	f>>n>>m;
	for (int i=1;i<=n;i++)
		f>>v[i];
	for (int i=1;i<=m;i++)
		f>>w[i];
}
int max(int a, int b)
{
	if (a>b) return a;
	return b;
}
void dinamica()
{
	int i,j;p=0;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
			if (v[i]==w[j])
				a[i][j]=a[i-1][j-1]+1;
			else a[i][j]=max(a[i][j-1],a[i-1][j]);
	}
	g<<a[n][m]<<'\n';
}
void afis()
{
	int vect[1025],k=0;
	int x,y;
	x=n;y=m;
	while (a[x][y]!=0)
	{
		if (v[x]==w[y])
		{
			vect[++k]=v[x];
			x--;y--;
		}
		else if (a[x-1][y]>a[x][y-1])
			x--;
		else y--;
	}
	for (int i=k;i>=1;i--)
		g<<vect[i]<<' ';
}
int main()
{
	citire();
	dinamica();
	afis();
	return 0;
}
