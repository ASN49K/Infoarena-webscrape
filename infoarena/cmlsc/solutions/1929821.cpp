#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int lcs[1025][1025],i,j,n,m,a[1025],b[1025],l[1030],c[1030],nr;
int main()
{
  fin>>n>>m;
  for(i=1;i<=n;i++)
    fin>>a[i];
  for(i=1;i<=m;i++)
    fin>>b[i];
  lcs[0][1]=0;
  lcs[1][0]=0;
  if(a[1]==b[1])
    lcs[1][1]=1;
  for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {
      if(a[i]==b[j])
        lcs[i][j]=lcs[i-1][j-1]+1;
      else
      {
        lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
      }
    }
    fout<<lcs[n][m] << '\n';

      i=n;
    j=m;
    while(i>1 || j>1)
    {
      while(j>1 && lcs[i][j]==lcs[i][j-1])
        j--;
      while(i>1 && lcs[i][j]==lcs[i-1][j])
        i--;
      l[++nr]=i;
      i--;
      j--;
      if(lcs[i][j] == 0) break;
    }
    for(i=nr;i>=1;i--)
      fout<<a[l[i]]<<' ';
}
