#include<fstream>
#define nmax 1025

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int M[nmax][nmax],a[nmax],b[nmax],n,m;

void citire()
{fin>>m>>n;
int i;
for(i=1;i<=m;i++)
  fin>>a[i];
for(i=1;i<=n;i++)
  fin>>b[i];
}

int maxim(int x,int y)
{if(x>y) return x;
return y;
}

void solve()
{int i,j;
for(i=1;i<=n;i++)
 for(j=1;j<=m;j++)
   if(a[j]==b[i])
      M[i][j]=M[i-1][j-1]+1;
    else
      M[i][j]=max(M[i-1][j],M[i][j-1]);
fout<<M[n][m]<<'\n';
}

int main()
{citire();
solve();
return 0;
}
