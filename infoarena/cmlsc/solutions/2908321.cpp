#include <fstream>

using namespace std;

ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");

const int max_size = 1025;

int dp[max_size][max_size], a[max_size], b[max_size], r[max_size];

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
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int i = n, j = m, k = 0;
    while (i)
    {
        if (a[i] == b[j])
        {
            r[++k] = a[i];
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] < dp[i][j - 1])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
    out << k << '\n';
    for (k = k; k > 0; k--)
    {
        out << r[k] << " ";
    }
    in.close();
    out.close();
    return 0;
}
