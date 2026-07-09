#include <fstream>

using namespace std;

const int N = 1024;
int a[N + 1], b[N + 1];
int dp[N + 1][N + 1];

void afis_subsir(int m, int n, ofstream &out)
{
    if (m == 0 || n == 0)
    {
        return;
    }
    if (dp[m][n] == dp[m - 1][n] && dp[m][n] == dp[m][n - 1])
    {
        afis_subsir(m, n - 1, out);
    }
    else if (dp[m - 1][n] > dp[m][n - 1])
    {
        afis_subsir(m - 1, n, out);
    }
    else if (dp[m][n - 1] > dp[m - 1][n])
    {
        afis_subsir(m, n - 1, out);
    }
    else
    {
        afis_subsir(m - 1, n - 1, out);
        out << a[m] << ' ';
    }
}
int main()
{
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");

    int m, n;
    in >> m >> n;
    for (int i = 1; i <= m; i ++)
    {
        in >> a[i];
    }
    for (int j = 1; j <= n; j ++)
    {
        in >> b[j];
    }

    for (int i = 1; i <= m; i ++)
    {
        for (int j = 1; j <= n; j ++)
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

    out << dp[m][n] << '\n';
    afis_subsir(m, n, out);

    in.close();
    out.close();

    return 0;
}
