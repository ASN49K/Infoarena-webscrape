#include <bits/stdc++.h>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,eMax=1<<11,a[1<<11],b[1<<11],dp[1<<11][1<<11];

inline void Afis(int x,int y,int lg)
{   for(int i=x; i<=n; i++)
        for(int j=y; j<=m; j++)
            if(a[i]==b[j] && dp[i][j]==lg)
            {   g<<a[i]<<' ';
                Afis(i+1,j+1,lg-1);
                return;
            }
}

int main()
{   f>>n>>m;
    for(int i=1; i<=n; i++)
        f>>a[i];
    for(int i=1; i<=m; i++)
        f>>b[i];
    for(int i=n; i; i--)
        for(int j=m; j; j--)
            dp[i][j]=(a[i]==b[j] ? dp[i+1][j+1]+1 : max(dp[i+1][j],dp[i][j+1]));
    g<<dp[1][1]<<'\n';
    Afis(1,1,dp[1][1]);
    g.close(); return 0;
}
