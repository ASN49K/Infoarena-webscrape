#include<iostream>
#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int  t=0,v[1024][1024],x[1024],y[1024],d[1024],j,i,n,m;

void functie()
{
for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	{	if(x[i]==y[j]){t++;v[i][j]=v[i-1][j-1]+1;d[t]=x[i];}
	else
		if(v[i-1][j]>=v[i][j-1])v[i][j]=v[i-1][j];
	else v[i][j]=v[i][j-1];
	}
//	return v[n][m];
}



int main()
{f>>n>>m;
for(i=1;i<=n;i++)
	f>>x[i];
for(j=1;j<=m;j++)
	f>>y[j];
f.close();
//for(i=0;i<=n;i++)
//	v[i][0]=0;
//	for(i=0;i<=m;i++)
//		v[0][i]=0;

functie();
//cout<<functie();

g<<v[n][m]<<'\n';
for(i=1;i<=t;i++)g<<d[i]<<" ";
g.close();
return 0;
}