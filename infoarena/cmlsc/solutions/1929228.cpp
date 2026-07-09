#include <fstream>
#include <iostream>
#include <string>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int dp[1025][1025],i,j,n,m,a[1025],b[1025],l[1030],c[1030],nr;
int main()
{
  fin>>n>>m;
  for(i=1;i<=n;i++)
    fin>>a[i];
  for(i=1;i<=m;i++)
    fin>>b[i];
  dp[0][1]=0;
  dp[1][0]=0;
  if(a[1]==b[1])
    dp[1][1]=1;
  for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {
      if(a[i]==b[j])
        dp[i][j]=dp[i-1][j-1]+1;
      else
      {
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
      }
    }

//    for(int i=0;i<=n;i++)
//    {
//      for(int j=0;j<=m;j++)
//        cout << dp[i][j] << ' ';
//      cout << '\n';
//    }

    fout<<dp[n][m] << '\n';
    //return 0;
    i=n;
    j=m;
    while(i>1 || j>1)
    {
      while(j>1 && dp[i][j]==dp[i][j-1])
        j--;
      while(i>1 && dp[i][j]==dp[i-1][j])
        i--;
      l[++nr]=i;
      i--;
      j--;
      if(dp[i][j] == 0) break;
    }
    for(i=nr;i>=1;i--)
      fout<<a[l[i]]<<' ';
}
