#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m,n,a[1050],b[1050],i,j,dp[1050][1050],c,rasp[1050];

int main()
{
    fin>>m>>n;
    for (i=1;i<=m;i++)
        fin>>a[i];
    for (i=1;i<=n;i++)
        fin>>b[i];
    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
        {
            if (a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    fout<<dp[m][n]<<endl;
    i=m;
    j=n;
    c=dp[m][n];
    while (i&&j)
    {
        if (a[i]==b[j])
        {
            rasp[c--]=a[i];
            i--;
            j--;
        }
        else if (dp[i-1][j]<dp[i][j-1])
            j--;
        else i--;
    }
    for (i=1;i<=dp[m][n];i++)
        fout<<rasp[i]<<" ";
    return 0;
}
