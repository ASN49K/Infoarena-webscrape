#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int elem[1111];
int n, m;
int v[1111], w[1111];
int dp[1111][1111];
int k, ans;
int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i ++)
        fin >> v[i];
    for(int i = 1; i <= m; i ++)
        fin >> w[i];
    for(int i = 1; i <= m; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            if(w[i] == v[j])
            {
                elem[++k] = v[j];
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            ans = max(ans,dp[i][j]);
        }
    }
    fout << ans << '\n';
    for(int i = 1; i <= k; i ++)
        fout << elem[i] << ' ';
}
