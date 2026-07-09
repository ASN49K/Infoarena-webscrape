#include <fstream>

#define maxim(a, b) ((a > b) ? a : b)
using namespace std;

int a[1024],b[1024],m,n,d[1024][1024],i,j,nr,c[1024];
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");
int main ()
{
	f >>m>>n;
	for (i=1; i<=m; i++)
		f>>a[i];
	for (i=1; i<=n; i++)
		f>>b[i];
 
	for (i=1; i<=m; i++)
		for (j=1; j<=n; j++)
		if (a[i] == b[j]) d[i][j]=1+d[i-1][j-1];
		else
			d[i][j] = maxim(d[i-1][j],d[i][j-1]);
 
		for (i=m, j=n; i; )
			if (a[i] == b[j]) 
			{
				c[++nr]=a[i];
				i--;
				j--;
			}
			else if (d[i-1][j] < d[i][j-1]) j--;
			else i--;
 
		g<<nr<<'\n';
		for (i=nr; i>0; i--)
			g <<c[i]<<' ';
 
return 0;
}
