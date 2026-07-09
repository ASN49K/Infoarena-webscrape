#include <bits/stdc++.h>
#define nmax 1026

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int n, m, x[nmax], y[nmax], dp[nmax][nmax];
vector <int> v;

int main()
{
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> x[i];
    for (int i = 1; i <= m; i++)
        fin >> y[i];
    for (int i = 1; i <= n; i++)
    {
        if (x[1] == y[i])
            dp[1][i] = 1;
        else
            dp[1][i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        if (x[i] == y[1])
            dp[i][1] = 1;
        else
            dp[i][1] = 0;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= m; j++)
        {
            if (x[i] == y[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max (dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int i = n;
    int j = m;
    while (i > 0 && j > 0)
    {
        if (dp[i][j] > dp[i - 1][j] && dp[i][j] > dp[i][j - 1])
        {
            v.push_back(x[i]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
            else j--;
    }
    fout << dp[n][m] << '\n';
    for (int i = v.size() - 1; i >= 0; i--)
        fout << v[i] << ' ';
    return 0;
}
