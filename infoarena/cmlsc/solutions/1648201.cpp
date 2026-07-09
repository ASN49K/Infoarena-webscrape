#include <fstream>
#include <vector>
#include <algorithm>
#define NMAX 1030

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int dp[NMAX][NMAX], v[NMAX], x[NMAX], i, j, n, m, ans = 0, sol[NMAX];

int main()
{
    f >> n >> m;

    for (i = 1; i <= n; ++ i)
        f >> v[i];

    for (i = 1; i <= m; ++ i)
        f >> x[i];

    for (i = 1; i <= n; ++ i)
        for (j = 1; j <= m; ++ j)
            if (v[i] == x[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    i = n;
    j = m;

    while (i && j)
    {
        if (v[i] == x[j])
        {
            i --;
            j --;
            sol[++ ans] = v[i + 1];
        }
        else
            if (dp[i - 1][j] > dp[i][j - 1])
                i --;
        else
                j --;
    }

    g << dp[n][m] << '\n';

    for (i = ans; i >= 1; -- i)
        g << sol[i] << " ";
    return 0;
}
