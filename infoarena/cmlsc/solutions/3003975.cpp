#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    int m, n;
    fin >> m >> n;

    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    vector<int> v1(m + 1), v2(n + 1);

    for (int i = 1; i <= m; i++)
    {
        fin >> v1[i];
    }
    for (int i = 1; i <= n; i++)
    {
        fin >> v2[i];
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (v1[i] == v2[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    fout << dp[m][n] << "\n";

    vector<int> sir;

    for (int i = m, j = n; i;)
    {
        if (v1[i] == v2[j])
        {
            sir.push_back(v1[i]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] < dp[i][j - 1])
        {
            j--;
        }
        else
        {
            i--;
        }
    }

    reverse(sir.begin(), sir.end());

    for (auto it: sir)
    {
        fout << it << " ";
    }
    return 0;
}
