#include <fstream>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int n, m, v[1025], w[1025], dp[1025][1025];

void reconst(int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (v[i] == w[j])
    {
        reconst(i - 1, j - 1);
        cout << v[i] << " ";
    }
    else
    {
        if (dp[i - 1][j] > dp[i][j - 1])
            reconst(i - 1, j);
        else
            reconst(i, j - 1);
    }
}

int main()
{
    cin >> n >> m;
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        dp[i][0] = 0;
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> w[i];
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (v[i] == w[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][m] << "\n";
    reconst(n, m);
    return 0;
}
