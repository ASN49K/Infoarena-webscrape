#include <fstream>
#define NMAX 1030

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

void citire();
void rezolvare();
void reconstituire();

int a[NMAX][NMAX], v1[NMAX], v2[NMAX], v[NMAX];
int n, m, x;

int main()
{
  citire();
  rezolvare();
  return 0;
}

void citire()
{
  int i;
  fin>>n>>m;
  for(i=1; i<=n; i++) fin>>v1[i];
  for(i=1; i<=m; i++) fin>>v2[i];
}

void rezolvare()
{
  int i, j;
  for(i=1; i<=n; i++)
  {
    for(j=1; j<=m; j++)
    {
      if(v1[i]==v2[j]) a[i][j]=a[i-1][j-1]+1;
      else a[i][j]=max(a[i-1][j], a[i][j-1]);
    }
  }
  fout<<a[n][m]<<'\n';
  reconstituire();
}

void reconstituire()
{
  int i, j;
  i=n; j=m;
  while(i!=0 && j!=0)
  {
    if(v1[i]!=v2[j])
    {
      if(a[i-1][j]>a[i][j-1]) i--;
      else j--;
    }
    else
    {
      x++;
      v[x]=v1[i];
      i--;
      j--;
    }
  }
  for(i=x; i>=1; i--) fout<<v[i]<<' ';
}
