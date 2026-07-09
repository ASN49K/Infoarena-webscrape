#include<bits/stdc++.h>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n, m, a[1050], b[1050], dp[1050][1050], k, c[1050];
int main()
{
    f>>n>>m;
    for(int i=1; i<=n; i++)
        f>>a[i];
    for(int i=1; i<=m; i++)
        f>>b[i];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    int i=n, j=m;
    while(i)
    {
        if(a[i]==b[j])
        {
            c[++k]=a[i];
            i--;
            j--;
        }
        else if(dp[i-1][j]<dp[i][j-1]) j--;
        else i--;
    }
    g<<dp[n][m]<<'\n';
    for(int i=k; i>=1; i--)
        g<<c[i]<<' ';
    return 0;
}
