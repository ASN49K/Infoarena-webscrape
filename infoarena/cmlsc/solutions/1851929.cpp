#include <bits/stdc++.h>
#define nmax 1030
using namespace std;
ifstream fin("cmslc.in");
ofstream fout("cmslc.out");
int a[nmax],dp[nmax][nmax],n,m,b[nmax],sol[nmax];
void Citire()
{
    int i;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
}
void DP()
{
    int i,j,cnt=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
          if(a[i]==b[j])
              dp[i][j]=dp[i-1][j-1]+1;
    else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    fout<<dp[n][m]<<"\n";
    i=n;
    j=m;
    while(i>=1 && j>=1)
    {
        if(a[i]==b[j])
        {
            sol[++cnt]=a[i];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
             i--;
        else j--;
    }
    for(i=cnt;i>=1;i--)
        fout<<sol[i]<<" ";
}
int main()
{
    Citire();
    DP();
    fin.close();
    fout.close();
    return 0;
}
