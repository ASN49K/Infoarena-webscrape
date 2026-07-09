#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int M[1025][1025],a[1025],b[1025],n,m;
int c[1025];

void citire()
{   fin>>n>>m;
    int i;
    for(i=1;i<=n;i++)
      fin>>a[i];
    for(i=1;i<=m;i++)
      fin>>b[i];
}

int max(int x,int y)
{if(x>y) return x;
return y;
}

void solve()
{int i,j;
for(i=1;i<=m;i++)
  for(j=1;j<=n;j++)
    if(a[j]==b[i])
         M[i][j]=M[i-1][j-1]+1;
      else
         M[i][j]=max(M[i-1][j],M[i][j-1]);
fout<<M[m][n]<<'\n';
i=m;j=n;
int nr=0;
while(nr<M[m][n])
  {c[++nr]=a[j];
   if(a[j]==b[i])
     {i--;
      j--;
     }
    else
      {i--;j--;
       while(a[j]!=b[i])
         {j--;
         }
       c[++nr]=a[j];
       i--;
       j--;
      }
  }
for(i=nr-1;i>=1;i--)
  fout<<c[i]<<" ";
}

int main()
{   citire();
    solve();
    return 0;
}
