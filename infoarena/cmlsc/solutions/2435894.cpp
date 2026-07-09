#include<bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int lg,sir[1030];
int n,m,i,j,a[1030],b[1030],c[1030][1030];
int main()
{
  fin>>n>>m;
  for (i=1;i<=n;i++)
   fin>>a[i];
  for (i=1;i<=m;i++)
   fin>>b[i];
  for (i=1;i<=n;i++)
   for (j=1;j<=m;j++)
    {
      if (a[i] == b[j])
      {
        c[i][j] = c[i-1][j-1] + 1;
      }
      else
      {
        c[i][j] = max(c[i][j-1],c[i-1][j]);
      }
    }
  for (i=n,j=m; i;)
  {
    if (a[i] == b[j])
      sir[++lg] = a[i] , i--, j--;
    else if (c[i-1][j] < c[i][j-1])
      j--;
    else
      i--;
  }
  fout<<lg<<'\n';
  for (i=lg;i>=1;i--)
   fout<<sir[i]<<" ";
  return 0;
}
