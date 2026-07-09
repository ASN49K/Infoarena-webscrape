#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,v[2000],w[2000],dp[2000];
stack <int> rez;

int main()
{
    f>>n>>m;
    for(int i=1; i<=n; i++)
        f>>v[i];
    for(int j=1; j<=m; j++)
        f>>w[j];
    for(int i=1; i<=n; i++)
    {
        int maxim=0;
        for(int j=1; j<=m; j++)
        {
            if(v[i]==w[j])
                dp[j]=maxim+1;
            maxim=max(maxim,dp[j]);
        }
    }
    int maxim=0;
    for(int i=1; i<=m; i++)
        maxim=max(maxim,dp[i]);
    g<<maxim<<'\n';
    for(int i=m; i>=1; i--)
        if(dp[i]==maxim)
            rez.push(w[i]), maxim--;
    while(!rez.empty())
        g<<rez.top()<<' ', rez.pop();
    return 0;
}
