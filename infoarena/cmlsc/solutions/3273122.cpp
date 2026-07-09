#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    int n, m;
    fin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; fin >> a[i++])
        ;
    for (int i = 0; i < m; fin >> b[i++])
        ;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // for (int i = 0; i <= n; i++, cout << '\n')
    // {
    //     for (int j = 0; j <= m; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    // }

    fout << dp[n][m] << '\n';

    int x, y;
    x = n;
    y = m;

    vector<int> secv;

    while (x > 0 and y > 0)
    {
        // cout << x << " " << y << '\n';
        if (a[x - 1] == b[y - 1])
        {
            secv.push_back(a[x - 1]);
            x--;
            y--;
        }
        else
        {
            if (dp[x - 1][y] > dp[x][y - 1])
            {
                x--;
            }
            else
                y--;
        }
    }
    for (int i = (int)secv.size() - 1; i >= 0; i--)
    {
        fout << secv[i] << " ";
    }

    return 0;
}
