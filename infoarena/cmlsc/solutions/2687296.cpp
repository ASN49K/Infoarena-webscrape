#include <bits/stdc++.h>

using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");
int n,m;
int a[1050];
int b[1050];
int dp[1050][1050];
int main()
{
    f>>n>>m;
    for(int i=1; i<=n; ++i)
        f>>a[i];
    for(int i=1; i<=n; ++i)
        cout<<a[i]<<" ";
    for(int j=1; j<=m; ++j)
        f>>b[j];
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
    }
    g<<dp[n][m]<<"\n";

    int i = n, j = m;
    int l=0;
    int r[10000];
    while (i >= 1 && j >= 1)
    {
        if (a[i] == b[j])
        {
            r[++l] = a[i];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    while(l>0)
    {
        g << r[l] << " " ;
        --l;
    }
    return 0;
}
