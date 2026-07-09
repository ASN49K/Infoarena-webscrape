#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int s[260];

int dp[1025][1025], n, m, i, j, a, s1[1025], s2[1025], el=1, x, y;

int main()
{
    f>>m>>n;
    for(i=1; i<=m; i++)
    {
        f>>s1[i];
    }
    for(i=1; i<=n; i++)
    {
        f>>s2[i];
    }
    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
        {
            dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
            if(s1[i]==s2[j])
            {
                dp[i][j]=max(dp[i-1][j-1]+1, dp[i][j]);
            }
        }
    }
    g<<dp[m][n]<<'\n';
    int maxx=dp[m][n];
    i=m; j=n;
    a=0;
    while(dp[i][j]>0)
    {
        ///if(dp[i][j]>dp[i-1][j] && dp[i][j]>dp[i][j-1] && dp[i-1][j]==dp[i][j-1])
        if(dp[i][j]>dp[i][j-1] && dp[i][j]>dp[i-1][j])
        {
            a++;
            s[a]=s1[i];
            i--;
            j--;
        }
        if(dp[i][j]>dp[i-1][j])
            j--;
        else
        if(dp[i][j]>dp[i][j-1])
            i--;
        else
            i--;
    }

    for(i=a; i>=1; i--)
    {
        g<<s[i]<<' ';
    }

//    for(i=1; i<=m; i++)
//    {
//        for(j=1; j<=n; j++)
//        {
//            if(dp[i][j]==el)
//            {
//                g<<s1[i]<<' ';
//                el++;
//            }
//        }
//    }
    return 0;
}
