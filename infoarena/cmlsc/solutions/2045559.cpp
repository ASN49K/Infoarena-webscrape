#include <cstdio>
using namespace std;
FILE *f, *g;
int n,m,i,j,a[1025][1025],y[1025],x[1025];
int main()
{f=fopen ("cmlsc.in","r");
g=fopen ("cmlsc.out","w");
fscanf (f,"%d%d",&n,&m);
for (i=1;i<=n;++i)
fscanf (f,"%d",&x[i]);
for (i=1;i<=m;++i)
fscanf (f,"%d",&y[i]);
if (x[n]==y[m])
a[n][m]=1;
else
a[n][m]=0;
for (j=m-1;j>=1;--j)
if (x[n]==y[j])
a[n][j]=1;
else
a[n][j]=a[n][j+1];
for (i=n-1;i>=1;--i)
if (x[i]==y[m])
a[i][m]=1;
else
a[i][m]=a[i+1][m];
for (i=n-1;i>=1;--i)
for (j=m-1;j>=1;--j)
if (x[i]==y[j])
a[i][j]=a[i+1][j+1]+1;
else
{if (a[i+1][j]>a[i][j+1])
a[i][j]=a[i+1][j];
else
a[i][j]=a[i][j+1];
}
fprintf (g,"%d\n",a[1][1]);
i=j=1;
while (i<=n&&j<=m)
if (x[i]==y[j])
{fprintf (g,"%d ",x[i]);
++i;
++j;
}
else
{if (a[i][j]==a[i+1][j])
++i;
else
++j;
}
return 0;
}
