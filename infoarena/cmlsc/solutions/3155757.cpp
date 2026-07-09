#include <fstream>

using namespace std;

ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");

const int max_size = 1026;

int dp[max_size][max_size], a[max_size], b[max_size], ans[max_size];

int main ()
{
    int n, m;
    in >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        in >> a[i];
    }
    for (int j = 1; j <= m; j++)
    {
        in >> b[j];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    out << dp[n][m] << '\n';
    int poz = dp[n][m], i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (a[i] == b[j])
        {
            ans[poz] = a[i];
            i--;
            j--;
            poz--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    for (int i = 1; i <= dp[n][m]; i++)
    {
        out << ans[i] << " ";
    }
    in.close();
    out.close();
    return 0;
}
