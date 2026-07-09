#include<fstream>
#define Max 1026
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m;
int a[Max],b[Max],c[Max][Max];
int sir[Max],nsir;

#define max(a,b) ((a)>(b)?(a):(b))

int main()
{
	int i,j;
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>a[i];
	for(j=1;j<=m;j++)
		f>>b[j];
	for(i=n;i>0;i--)
		for(j=m;j>0;j--)
			if(a[i]==b[j])
				c[i][j]=1+c[i+1][j+1];
			else
				c[i][j]=max(c[i+1][j],c[i][j+1]);
	for(i=j=1;i<=n&&j<=m;)
		if(a[i]==b[j])
			sir[++nsir]=a[i],i++,j++;
		else
			if(c[i+1][j]>c[i][j+1]) i++;
			else j++;
	g<<nsir<<'\n';
	for(i=1;i<=nsir;i++)
		g<<sir[i]<<' ';
	g<<'\n';
	return 0;
}
