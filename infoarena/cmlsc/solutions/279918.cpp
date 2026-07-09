#include<fstream.h>
int nr=0,c[1025];
void ver(int a[1025],int b[1025],int n,int m)
{ int i,j;
 for(i=1;i<=m;i++)
  for(j=1;j<=n;j++)
   if(b[i]==a[j]) { nr++;
		    c[nr]=b[i];
		  }
}
int main()
{
int i,j,n,m,a[1024],b[1024];
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
f>>n>>m;
for(i=1;i<=n;i++)
 f>>a[i];
for(j=1;j<=m;j++)
 f>>b[j];
if(m>n)
 ver(b,a,m,n);
 else
  ver(a,b,n,m);
g<<nr<<"\n";
for(i=1;i<=nr;i++)
 g<<c[i]<<" ";
return 0;
}
