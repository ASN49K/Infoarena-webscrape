#include<fstream.h>
int main ()
{
int i,j,m,n,a[100],b[100],c[100],d[100],k,k2;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
f>>m>>n;
for(i=1;i<=m;i++)
 f>>a[i];
for(i=1;i<=n;i++)
 f>>b[i];
k=1;
for(i=1;i<=m;i++)
 for(j=i;j<=n;j++)
  if(a[i]==b[j])
   {
   c[k]=a[i];
   k++;
   if(i!=j)
    i=j+1;
   }
k2=1;
for(i=1;i<=n;i++)
  for(j=i;j<=m;j++)
   if(b[i]==a[j])
    {
    d[k2]=b[i];
    k2++;
    if(i!=j)
    i=j+1;
    }
if(k>k2)
 {
 g<<k<<"\n";
 for(i=1;i<=k;i++)
  g<<c[i]<<" ";
 }
 else
 {
 g<<k2<<"\n";
 for(i=1;i<=k2;i++)
  g<<d[i]<<" ";
 }
f.close();
g.close();
return 0;
}