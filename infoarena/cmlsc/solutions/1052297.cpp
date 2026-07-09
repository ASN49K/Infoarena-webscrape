#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[1025],b[1025],d[1025][1025],rez[1025],ct=0;
int maxim(int a,int b)
{
	if(a>b) return a;
	else return b;
} 
int main()
{
	f>>n>>m;
	int i,j;
	for(i=1;i<=n;i++)
		f>>a[i];
	for(i=1;i<=m;i++)
		f>>b[i];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			if(a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
			else d[i][j]=maxim(d[i-1][j],d[i][j-1]);
		}
	
	g<<d[n][m]<<'\n'; i=n;j=m;
	while(i&&j)
		if(a[i]==b[j])
		{
			rez[++ct]=a[i];
			i--; j--;
		}
		else if (d[i-1][j]>d[i][j-1]) i--;
			else j--;
	for(i=ct;i;i--)
		g<<rez[i]<<' ';
			
			
}
				