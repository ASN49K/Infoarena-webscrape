#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1030],b[1030],dp[1030][1030], f[1030];
int main()
{
    int m,n,i,j,t;
    fin>>n>>m;
    for(i=1;i<=n;i++)
    {
        fin>>a[i];
    }
    for(i=1;i<=m;i++)
    {
        fin>>b[i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
          dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
          if(a[i]==b[j])
          {
              dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
          }
        }
    }
    fout<<dp[n][m]<<'\n';
    i=n;
    j=m;
    t=1;
    while(dp[i][j]>0)
    {
        if(dp[i][j]>dp[i-1][j] && dp[i][j]>dp[i][j-1])
        {
           f[t]=a[i];
           t++;
           i--;
           j--;
        }
        else
            if(dp[i][j]>dp[i-1][j])
            j--;
            else
                if(dp[i][j]>dp[i][j-1])
                i--;
                else
                i--;
    }
    for(i=1;i<=t-1;i++)
    {
        fout<<f[i]<<" ";
    }
    return 0;
}
