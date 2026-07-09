#include <bits/stdc++.h>
#define MAXN 1030

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, q, v[MAXN], w[MAXN], dp[MAXN][MAXN], sol[MAXN];

int main()
{
    int i, j, x, y;
    fin>>n>>m;
    for(i=1; i<=n; i++) fin>>v[i];
    for(i=1; i<=m; i++) fin>>w[i];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(v[i]==w[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    x=n, y=m;
    while(dp[x][y]!=0)
    {
        if(dp[x][y]==dp[x-1][y]) x-=1;
        else if(dp[x][y]==dp[x][y-1]) y-=1;
        else sol[++q]=x, x-=1, y-=1;
    }
    fout<<q<<'\n';
    for(i=q; i>=1; i--) fout<<v[sol[i]]<<' ';
    return 0;
}
