#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int L[1025][1025], a[1025],b[1025],c[1025];

int k;

void Construire(int i, int j)
{
    if(L[i][j] > 0)
    {
     if(a[i]==b[j])
     {
      Construire(i-1, j-1);
      k += 1;
      c[k] = a[i];
     }
     else
     {
      if(L[i-1][j] > L[i][j-1])
      {
       Construire(i-1,j);
      }
      else
      {
       Construire(i,j-1);
      }
     }
    }
}

int main()
{
    int n,m,i,j;
    f>>n>>m;
    for(i = 1; i <= n; i++)
    {
     L[i][0] = 0;
     f>>a[i];
    }
    for(j = 1; j <= m; j++)
    {
     L[0][j] = 0;
     f>>b[j];
    }
    for(i = 1; i <= n; i++)
    {
     for(j = 1; j <= m; j++)
     {
      if(a[i] == b[j])
      {
       L[i][j] = L[i-1][j-1] + 1;
      }
      else
      {
       L[i][j] = max(L[i-1][j],L[i][j-1]);
      }
     }
    }
    k=0;
    Construire(n,m);
    g<<k<<'\n';
    for(i=1; i<=k; i++)
    {
     g<<c[i]<<" ";
    }
    return 0;
}
