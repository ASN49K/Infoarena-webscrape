#include<fstream.h>
#include<iostream.h>
ifstream f("cmlsc.in") ;
ofstream g("cmlsc.out");
int n,m,a[257],b,i,j;

int main()
{f>>n>>m;
for(i=1;i<=n;i++)
f>>a[i];
for(i=1;i<=m;i++)
     {f>>b;
     for(j=1;j<=n;j++)
	if(a[j]==b)
		g<<b<<' ';}
f.close();
g.close();
return 0;
}