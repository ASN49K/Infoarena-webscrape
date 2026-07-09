#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int i,m,n,nr,j,rez[1030],a[1030],b[1030],dp[1030][1030];
int main()
{
    fin>>n;
    fin>>m;

    for(i=1; i<=n; i++)
    {
        fin>>a[i];

    }
    for(i=1; i<=m; i++)
    {
        fin>>b[i];
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));
        }
    }
    fout<<dp[n][m]<<'\n';
    i=n;
    j=m;
    while(i>0&&j>0)
    {
        if(a[i]==b[j])
        {
            rez[++nr]=a[i];
            i--;
            j--;

        }
        else if(dp[i][j]==dp[i-1][j])
        {
            i--;
        }
        else j--;
    }
    for(i=nr; i>0; i--)
    {
        fout<<rez[i]<<" ";
    }
    return 0;
}
