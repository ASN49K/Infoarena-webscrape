#include <bits/stdc++.h>

using namespace std;

int n, m, v[1030], u[1030], dp[1030][1030], re[1030], k;

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");

    f >> n >> m;
    for(int i=1; i<=n; i++)
    {
        f >> v[i];
    }
    for(int i=1; i<=m; i++)
    {
        f >> u[i];
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(v[i] == u[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int i = n, j = m;
    while(i && j)
    {
        if(v[i] == u[j])
        {
            re[++k] = v[i];
            i --;
            j --;
        }
        else if (dp[i-1][j] < dp[i][j-1])
            j --;
        else
            i --;
    }
    g << k<< "\n";
    for(int i1=k; i1>=1; i1--) g << re[i1] << " ";
    return 0;
}
