#include <fstream>
using namespace std;
ifstream fi ("cmlsc.in");
ofstream fo ("cmlsc.out");
int dp[1050][1050],a[1050],b[1050],i,j,n,m,k,sol[1050];
int main()
{
    fi>>n>>m;
    for (i=1;i<=n;i++) fi>>a[i];
    for (i=1;i<=m;i++) fi>>b[i];
    for (i=1;i<=n;i++)
    {
      for (j=1;j<=m;j++)
      {
        if (a[i]==b[j]) dp[i][j]=1+dp[i-1][j-1];
        else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
      }
    }
//    for (i=1;i<=n;i++)
//    {
//      for (j=1;j<=m;j++) fo<<dp[i][j]<<' ';
//      fo<<'\n';
//    }
    i=n;
    j=m;
    for (i>=1;j>=1;)
    {
      if (a[i]==b[j]) {k++;sol[k]=a[i];i--;j--;}
      else if (dp[i-1][j]>dp[i][j-1]) i--;
      else j--;
    }
    fo<<k<<'\n';
    for (i=1;i<=k;i++) fo<<sol[k-i+1]<<' ';
    return 0;
}
