#include <fstream.h>
short m,n,a[1025],b[1025],l[1025][1025],s[1025],lg,i,j;
int main()
{ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
f>>m>>n;
for(i=1;i<=m;++i)
 f>>a[i];
for(i=1;i<=n;++i)
 f>>b[i];
for(i=1;i<=m;++i)
 for(j=1;j<=n;++j)
  if(a[i]==b[j])
   l[i][j]=1+l[i-1][j-1];
  else
  {l[i][j]=l[i-1][j];
   if(l[i][j]<l[i][j-1])
    l[i][j]=l[i][j-1];
  }
i=m;j=n;
while(i)
 if(a[i]==b[j])
 {s[++lg]=a[i];
  --i;
  --j;}
 else
  if(l[i-1][j]<l[i][j-1])
   --j;
  else
   --i;
g<<lg<<"\n";
for(j=lg;j;--j)
 g<<s[j]<<' ';
return 0;
}