#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int v1[1027];
int v2[1027];
int dp[1027][1027];
int sir[1027];

int main()
{
    int n,m;
    f>>n>>m;
    int i,j;
    for(i=1;i<=n;i++)
        f>>v1[i];
    for(i=1;i<=n;i++)
        f>>v2[i];

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(v1[i]!=v2[j])
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            else
                dp[i][j]=dp[i-1][j-1]+1;
        }
    }

    int cnt=0;
    for (i=n,j=m;i;)
    {
        if(v1[i]==v2[j])
        {
            sir[++cnt]=v1[i];
            i--;
            j--;
        }
        else
            if(dp[i-1][j]<dp[i][j-1])
                j--;
            else
                i--;
    }

    g<<cnt<<endl;
    for(i=cnt;i>=1;i--)
        g<<sir[i]<<" ";
    return 0;
}
