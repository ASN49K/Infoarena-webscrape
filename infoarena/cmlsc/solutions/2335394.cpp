#include <bits/stdc++.h>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[1025],b[1025],i,j,x[1025][1025],y[1025],k;
int main()
{ f>>n>>m;
  for(i=1;i<=n;i++)
    f>>a[i];
  for(i=1;i<=m;i++)
    f>>b[i];
  for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
  { if(a[i]==b[j])
      { x[i][j]=x[i-1][j-1]+1;
        y[++k]=a[i];
      }
    else
      if(x[i-1][j]>x[i][j-1])
        x[i][j]=x[i-1][j];
    else
        x[i][j]=x[i][j-1];
  }
  g<<k<<'\n';
  for(i=1;i<=k;i++)
    g<<y[i]<<" ";
    return 0;
}
