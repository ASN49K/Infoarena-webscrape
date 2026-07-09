#include<fstream>
using namespace std;
long long a[1025],b[10025],c[1025][1025],d[1025];
int main()
{
	long long i,j,m,n;
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	f>>n;
	f>>m;
	for(i=1; i<=n; i++)
		f>>a[i];
	for(i=1; i<=m; i++)
		f>>b[i];
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++)
		{
			if(a[i]==b[j])
				c[i][j]=c[i-1][j-1]+1;
			else
				if(c[i][j-1]>c[i-1][j])
					c[i][j]=c[i][j-1];
				else
					c[i][j]=c[i-1][j];
		}
		
	g<<c[n][m]<<'\n';
	for(i=0; c[n][m];)
	{
		if(a[n]==b[m])
		{
			d[i++]=a[n];
			n--;
			m--;
		}
		else
			if(c[n][m]==c[n-1][m])
			{
				n--;
			}
			else
				m--;
	}
	for(j=i-1; j>=0; j--)
		g<<d[j]<<" ";

}