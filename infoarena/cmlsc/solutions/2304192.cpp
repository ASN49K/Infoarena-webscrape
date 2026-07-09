#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,a[1025],b[1025],i,j,dp[2006][2006],sir[10001],bst;
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(i==0||j==0)
                dp[i][j]=0;
            else if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    fout<<dp[n][m]<<'\n';
    i=n;
    bst=1;
    j=m;
    while(i&&j)
    {
        if(a[i]==b[j])
        {
            sir[bst++]=a[i];
            i--;
            j--;
        }
        else if (dp[i-1][j]<dp[i][j-1])
            j--;
        else
            i--;
    }
    for(i=bst-1;i>=1;i--)
        fout<<sir[i]<<" ";
    return 0;
}
