#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int nMax = 1030;
int n, m, k;
int a[nMax], b[nMax], dp[nMax][nMax], ans[nMax];

inline void Read()
{
    int i;
    fin >> n >> m;
    for(i = 1; i <= n; i++)
        fin >> a[i];
    for(i = 1; i <= m; i++)
        fin >> b[i];
}

inline void Solve()
{
    int i, j;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    i = n;
    j = m;
    while(i && j)
    {
        if(a[i] == b[j])
        {
            ans[++k] = a[i];
            i--, j--;
        }
        else if(dp[i][j - 1] > dp[i - 1][j]) j--;
        else i--;
    }
    fout << dp[n][m] << "\n";
    for(i = k; i >= 1; i--)
        fout << ans[i] << " ";
}

int main()
{
    Read();
    Solve();
    return 0;
}
