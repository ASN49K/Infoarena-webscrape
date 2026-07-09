#include<fstream.h>
#include<iostream.h>
ifstream f("cmlsc.in") ;
ofstream g("cmlsc.out");
int n,m,a[1050],b[1050],i,j,k,l[1050];

int main()
{f>>n>>m;
for(i=1;i<=n;i++)
f>>a[i];
for(i=1;i<=m;i++)
     f>>b[i];
for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	if(a[i]==b[j])
		{k++;
		 l[k]=a[i];

		}

     g<<k<<endl;
for(i=1;i<=k;i++)
	g<<l[i]<<' ';


f.close();
g.close();
return 0;
}