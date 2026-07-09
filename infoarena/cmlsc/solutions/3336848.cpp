#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m;
vector<int> a, b;

vector<vector<int>> dp;

void read()
{
    fin >> n >> m;
    a.assign(n + 1, 0);
    b.assign(m + 1, 0);

    dp.assign(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
        fin >> a[i];

    for (int j = 1; j <= m; j++)
        fin >> b[j];
}

void len()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i] == b[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    fout << dp[n][m] << '\n';
}

void rec()
{
    vector<int> ans;
    int i = n, j = m;
    while (i && j)
    {
        if (a[i] == b[j])
        {
            ans.push_back(a[i]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    reverse(ans.begin(), ans.end());
    for(auto &x:ans)
        fout << x << ' ';
}

int main()
{
    read();
    len();
    rec();

    return 0;
}