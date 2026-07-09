#include<fstream.h>
int a[1224],b[1224],i,k=0,j,z=1,n,m,c[1025];
int main()
{ifstream f("cmlsc.in");ofstream g("cmlsc.out");

f>>m;f>>n;
for(i=1;i<=m;i++)
f>>a[i];
for(j=1;j<=n;j++)
f>>b[j];
for(i=1;i<=m;i++)
  for(j=z;j<=n;j++)
  if(a[i]==b[j])
  {k++;z=j+1;c[k]=a[i];}
g<<k<<'\n';
for(i=1;i<=k;i++)
g<<c[i]<<" ";
return 0;}