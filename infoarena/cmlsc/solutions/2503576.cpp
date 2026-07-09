#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int xx,y,max1,i,j,ok,x[5],n,m,a[1025],b[1025],k,v[1025];



int main()
{
 f>>n>>m;
 for(i=1;i<=n;i++)f>>a[i];
  for(i=1;i<=m;i++)f>>b[i];
  for(i=1;i<=n;i++)
  {ok=0;
      for(j=1;j<=m&&!ok;j++)
        if(a[i]==b[j])

      {
          ok=1;
          k++;
          v[k]=a[i];
      }
  }
  g<<k<<'\n';
  for(i=1;i<=k;i++)
    g<<v[i]<<" ";
    return 0;
}
