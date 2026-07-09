#include<fstream.h>
#define dim 1025
#define max(x,y) (x)>(y)?(x):(y)
int a[dim],b[dim],d[dim];
int c[dim][dim];
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int main()
{int n,m;
f>>n>>m;
int i,j;
for(i=1;i<=n;i++) f>>a[i];
for(j=1;j<=m;j++) f>>b[j];
f.close();

for(i=1;i<=n;i++)
 for(j=1;j<=m;j++)
  if(a[i]==b[j])
    c[i][j]=1+c[i-1][j-1];
   else c[i][j]=max(c[i-1][j],c[i][j-1]);

int lin,col;
lin=n;col=m;
i=0;
while(c[lin][col])
{if(a[lin]==b[col])
  {i++;
   d[i]=a[lin];
   lin--;col--;
  }
  else if(c[lin][col]==c[lin][col-1]) col--;
   else if(c[lin][col]==c[lin-1][col]) lin--;
}

g<<c[n][m]<<'\n';
for(j=1;j<=i;j++) g<<d[j]<<" ";
g<<'\n';
g.close();
return 0;
}
