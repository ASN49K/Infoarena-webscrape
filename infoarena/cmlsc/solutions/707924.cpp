#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,i,j,nr,x[1100],y[1100],v[1100],a[1100][1100];
int main()
{f>>n>>m;
for(i=1;i<=n;++i)
	f>>x[i];
for(i=1;i<=m;++i)
	f>>y[i];
for(i=1;i<=m;++i)
	if(y[i]==x[1])
		a[1][i]=1;
	else
		a[1][i]=a[1][i-1];
for(i=2;i<=n;++i)
	if(x[i]==y[1])
		a[i][1]=1;
	else
		a[i][1]=a[i-1][1];
for(i=2;i<=n;++i)
	for(j=2;j<=m;++j)
		if(x[i]==y[j])
			a[i][j]=a[i-1][j-1]+1;
		else
			if(a[i][j-1]>a[i-1][j])
				a[i][j]=a[i][j-1];
			else
				a[i][j]=a[i-1][j];
g<<a[n][m]<<'\n';
i=n;
j=m;
nr=0;
while(i>=1&&j>=1)
	if(x[i]==y[j])
	{++nr;
	v[nr]=x[i];
	i--;
	j--;
	}
	else
		if(a[i-1][j]==a[i][j])
			--i;
		else
			--j;
for(i=nr;i>=1;--i)
	g<<v[i]<<" ";
f.close();
g.close();
return 0;
}