#include<fstream.h>
#define max(x,y) (x)>(y) ? (x):(y)
#define dim 1025
int n,m,a[dim][dim],v[dim],w[dim];
ofstream g("cmlsc.out");

void afisare(int i,int j)
{if((i>0)&&(j>0))
 {while((j>1)&&(a[i][j-1]==a[i][j]))j--;
  while((i>1)&&(a[i-1][j]==a[i][j]))i--;
  if(a[i-1][j])afisare(i-1,j);
  g<<v[i]<<" ";  }
}

int main()
{ifstream f("cmlsc.in");
int i,j;
f>>n>>m;
for(i=1;i<=n;i++)
 f>>v[i];
for(i=1;i<=m;i++)
 f>>w[i];
f.close();
for(i=1;i<=n;i++)
 for(j=1;j<=m;j++)
  {if(v[i]==w[j])a[i][j]=a[i-1][j-1]+1;
    else a[i][j]=max(a[i-1][j],a[i][j-1]);
  }
g<<a[n][m]<<'\n';
afisare(n,m);
g<<'\n';
/*g<<"matricea:"<<'\n';
for(i=1;i<=n;i++)
 {for(j=1;j<=m;j++)
   g<<a[i][j];
  g<<'\n';
 } */
g.close();
return 0;
}