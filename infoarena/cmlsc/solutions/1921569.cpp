#include <bits/stdc++.h>

using namespace std;
int a[1050], b[1050];
int dp[1050][1050];
int n, m;
vector <int> solve;
int main()
{
    ifstream fin ("cmlsc.in");
    ofstream fout ("cmlsc.out");
    fin >> n >> m;
    for (int i = 1; i<=n; ++i)
        fin >> a[i];
    for (int i = 1; i<=m; ++i)
        fin >> b[i];
    for (int i = 1; i<=n; ++i)
    {
        for (int j = 1; j<=m; ++j)
        {
            dp[i][j] = dp[i-1][j-1]+(a[i]==b[j]);
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            dp[i][j] = max(dp[i][j], dp[i][j-1]);
        }
    }
    fout << dp[n][m] << '\n';
    int i = n, j = m;
    while (i && j)
    {
        if (a[i] == b[j])
        {
            solve.push_back(a[i]);
            --i;
            --j;
            continue;
        }
        if (dp[i][j]==dp[i-1][j])
        {
            --i;
            continue;
        }
        --j;
    }
    for (int i = solve.size()-1; i>=0; --i)
        fout << solve[i] << " ";
    return 0;
}
