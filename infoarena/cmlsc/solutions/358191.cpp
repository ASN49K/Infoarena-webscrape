#include<fstream>
#define q 500
using namespace std;
int a[q], b[q], c[q][q], n, m, pma, ma, v[q];
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int max(int a, int b)
{ if(a>b) return a;
  return b;
}

void citire()
{ int i, j;
  f>>n>>m;
  for(i=1;i<=n;i++)
    f>>a[i];
  for(i=1;i<=m;i++)
    f>>b[i];
}

void solve()
{ int i, j;
  c[0][0];
  for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
      if(a[i]==b[j]) 
       {  c[i][j]=c[i-1][j-1]+1;
          v[j]=b[j];
       }
      else
        c[i][j]=max(c[i-1][j], c[i][j-1]);
  g<<c[n][m];
  g<<"\n";
  for(i=1;i<=n;i++)
    if(v[i]) g<<v[i]<<" ";
}

int main()
{   citire();
    solve();
    return 0;
}
