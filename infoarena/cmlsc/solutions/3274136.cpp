#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,v[2000],w[2000],dp[2000][2000];
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
        for(int j=1; j<=m; j++)
        {
            if(v[i]==w[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    for(int i=n, j=m; i and j; )
    {
        if(v[i]==w[j])
            rez.push(v[i]), i--, j--;
        else if(dp[i-1][j]<dp[i][j-1])
            j--;
        else
            i--;
    }
    g<<rez.size()<<'\n';
    while(!rez.empty())
        g<<rez.top()<<' ', rez.pop();
    return 0;
}
