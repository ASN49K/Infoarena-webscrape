#include<fstream.h>
int main ()
{
int i,j,m,n,a[100],b[100],c[100],d[100],k,k2,ind1[100],ind2[100];
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
f>>m>>n;
for(i=1;i<=m;i++)
 f>>a[i];
for(i=1;i<=n;i++)
 f>>b[i];
k=0;
for(i=1;i<=m;i++)
 {int ok=0;
  for(j=i;j<=n&&!ok;j++)
  if(a[i]==b[j]) ok=1;
  if(ok)
   {if(ind1[k]<i)
   {k++;
   c[k]=a[i];ind1[k]=i;
    }
    }
  }
k2=0;
for(i=1;i<=n;i++)
 {int ok=0;
  for(j=1;j<=m&&!ok;j++)
   if(b[i]==a[j]) ok=1;
    if(ok)
    {if(ind2[k2]<i)
    {k2++;
    d[k2]=b[i];ind2[k2]=i;
    }
   }
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
 g<<"\n";
f.close();
g.close();
return 0;
}