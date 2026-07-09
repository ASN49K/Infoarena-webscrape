#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
#define NMAX 1030
int a[NMAX],b[NMAX],n,m,x[NMAX][NMAX];
void afis(int i,int j)
{
	if(i!=0 && j!=0)
	{
	if(a[i]==b[j])
		{
			afis(i-1,j-1);
			g<<a[i]<<' ';
		}
	else 
		if(x[i-1][j]>x[i][j-1])
			afis(i-1,j);
		else
			afis(i,j-1);
	}
}
int main()
{
	int i,j;
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>a[i];
	for(i=1;i<=m;i++)
		f>>b[i];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			if(a[i]==b[j])x[i][j]=x[i-1][j-1]+1;
			else
				x[i][j]=max(x[i-1][j],x[i][j-1]);
		}
	g<<x[n][m]<<'\n';
	afis(n,m);
	return 0;
}
