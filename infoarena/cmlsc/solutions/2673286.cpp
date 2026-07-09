#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int elem[1111];
int n, m;
int v[1111], w[1111];
int dp[1111][1111];
int k, ans;
/// dp[i][j] -> lungimea maxima a subsirului format din primele i elemente are vectorului w
/// si din primele j elemente alre vectorului v
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
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            ans = max(ans,dp[i][j]);
        }
    }
    fout << dp[m][n] << '\n';
    int k = 1;
    for(int i = 1; i <= m; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            if(dp[i][j] == k)
            {
                fout << v[j] << ' ';
                k++;
            }
        }
    }
}
