#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int d[1025][1025],a[1025],b[1025],v[1025],k;
void intoarcere( int i,int j)
{
	if(i && j)
	{
		if(d[i][j]==d[i-1][j-1]+1 && a[i]==b[j])  { v[k++]=a[i]; intoarcere(i-1,j-1);}
		else 
		{ 
			if(d[i-1][j]<d[i][j-1]) intoarcere(i,j-1);
			else intoarcere(i-1,j);
		}
	}
}
		
int main()
{
	int n,m,i,j;
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>a[i];
	for(i=1;i<=m;i++)
		f>>b[i];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			if(a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
			else 
			{
				d[i][j]=d[i-1][j];
				if(d[i][j-1]>d[i][j]) d[i][j]=d[i][j-1];
			}
		}
	g<<d[n][m]<<'\n'; 
	intoarcere(n,m);
	for(i=d[n][m]-1;i>=0;i--)
		g<<v[i]<<' ';
}
	