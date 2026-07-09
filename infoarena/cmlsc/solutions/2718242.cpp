#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,a[1030],b[1030],dp[1030][1030],sir[1030],nr=0;

int main()
{
 f>>n>>m;
 for(int i=1;i<=n;i++) f>>a[i];
 for(int i=1;i<=m;i++) f>>b[i];

 for(int i=1;i<=n;i++)
  for(int j=1;j<=m;j++)
   if( a[i]==b[j] ) dp[i][j]=dp[i-1][j-1]+1;
   else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

 g<<dp[n][m]<<'\n';

 for(int i=n,j=m;i>=1&&j>=1;)
 {
  if( a[i]==b[j] ) sir[++nr]=a[i],i--,j--;
  else{
    if( dp[i-1][j]>=dp[i][j-1] ) i--;
    else j--;
  }
 }

 for(int i=nr;i>=1;i--) g<<sir[i]<<' ';
}
