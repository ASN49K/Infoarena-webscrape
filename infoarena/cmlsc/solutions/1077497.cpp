#include <fstream>
#define maxim(a, b) ((a > b) ? a : b)
#define NX 1025
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,i,j,a[NX],b[NX],c[NX][NX],sir[NX],lg;
int main ()
{
	f>>n>>m;
	for (i=1;i<=n;i++)
		f>>a[i];
	for (i=1;i<=m;i++)
		f>>b[i];
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
		{
			if (a[i]==b[j])
				c[i][j]=c[i-1][j-1]+1;
			else c[i][j]=maxim(c[i-1][j],c[i][j-1]);
		}
	for (i=n,j=m;i;)
	{
		if (a[i]==b[j])
		{
			sir[++lg]=a[i];
			i--;
			j--;
		}
		else 
			{
				if (c[i-1][j]<c[i][j-1]) j--;
				else i--;
			}
	}
	g<<lg<<"\n";
	for (i=lg;i>=1;i--)
		g<<sir[i]<<" ";
}
			