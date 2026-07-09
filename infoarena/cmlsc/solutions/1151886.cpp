#include <fstream>
#include <algorithm>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int v[1024];
int w[1024];
int d[1024][1024];
int s[1024];

int main ()
{
	int n, m;
	int i, j;
	
	f>>n>>m;
	for(i=1;i<=n;i++) f>>v[i];
	for(j=1;j<=m;j++) f>>w[j];
	
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(v[i]==w[j])
				d[i][j]=d[i-1][j-1]+1;
			else
				d[i][j]=max(d[i-1][j],d[i][j-1]);
	
	g<<d[n][m]<<'\n';
	
	i=n;
	j=m;
	int q=0;
	while(d[i][j]!=0)
		if(v[i]==w[j])
		{ s[++q]=v[i]; i--; j--; }
		else
			if(d[i][j]==d[i-1][j]) i--;
			else j--;
	for(i=q;i>=1;i--)
		g<<s[i]<<' ';
	return 0;
}
