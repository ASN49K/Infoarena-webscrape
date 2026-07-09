#include<fstream>
using namespace std;
int a[1025][1025],v[1024],w[1024];
ofstream g("cmlsc.out");
void rec(int i, int j)
{if (i!=0 && j!=0)
	if(v[i]==w[j])
	{rec(i-1,j-1);
	g<<v[i]<<" ";}
	else
		if(a[i-1][j]>a[i][j-1])
			rec(i-1,j);
		else
			rec(i,j-1);}
int main()
{int i,j, n,m;
ifstream f("cmlsc.in");
f>>n>>m;

for(i=1;i<=n;i++)
	f>>v[i];
for(i=1;i<=m;i++)
	f>>w[i];
for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
		if(v[i]==w[j])
			a[i][j]=a[i-1][j-1]+1;
		else
			if(a[i-1][j]>a[i][j-1])
				a[i][j]=a[i-1][j];
			else
				a[i][j]=a[i][j-1];
	//for(i=1;i<=n;i++){
	//for(j=1;j<=m;j++) g<<a[i][j]<<" "; g<<endl;}	
			g<<a[n][m]<<'\n';
rec(n,m);
f.close();
g.close();

}
