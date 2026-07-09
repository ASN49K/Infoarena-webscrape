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
       x[i][j]=x[i-1][j-1]+1;

    else
      if(x[i-1][j]>x[i][j-1])
        x[i][j]=x[i-1][j];
    else
        x[i][j]=x[i][j-1];
  }
  i=n; j=m;
  while(i>0 || j>0)
  { if(a[i]==b[j])
    { y[++k]=a[i];
      i--; j--;
    }
    else
     if(x[i-1][j]>x[i][j-1]) i--;
     else
        j--;
  }
  g<<k<<'\n';
  for(i=k;i>=1;i--)
   g<<y[i]<<" ";
    return 0;
}
