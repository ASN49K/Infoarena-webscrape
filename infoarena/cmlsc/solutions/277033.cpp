#include<fstream.h>
int main ()
{
int a[100], b[100], c[100];
int i, j, n, m, OK, OK1, k, q, ind1[100], ind2[100];
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
f>>n>>m;
for(i=1;i<=n;i++)
f>>a[i];
for(i=1;i<=m;i++)
f>>b[i];
k=0;
for(i=1;i<=n;i++)
 {
 OK=0;
 for(j=1;j<=n&&OK==0;j++)
  if(a[i]==b[j])
   OK=1;
  if(OK==1)
   {OK1=0;
    for(q=1;q<=k-1;q++)
     if(c[q]==a[i])
      OK1=1;
    if(OK1==0)
     if(ind1[k-1]<=i&&ind2[k-1]<=j)
      {
      k++;
      ind1[k]=i;
      ind2[k]=j;
      c[k]=a[i];
      }
    }
  if(k>0)
  {
  g<<k<<'\n';
   for(i=1;i<=k;i++)
    g<<c[i];
  }
    else
    g<<0;}
f.close();
g.close();
return 0;}
 