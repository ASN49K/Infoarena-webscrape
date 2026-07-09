#include <fstream>

using namespace std;

const int NMAX = 1024;

int a[1 + NMAX];
int b[1 + NMAX];

int dp[1 + NMAX][1 + NMAX];

int sol[1 + NMAX];

int main()
{
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    int n, m;

    in >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        in >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        in >> b[i];
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
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    out << dp[n][m] << '\n';

    int lung = dp[n][m];
    int l = n;
    int c = m;

    while (lung > 0)
    {
        if (a[l] == b[c])
        {
            sol[lung] = a[l];

            l--;
            c--;

            lung--;
        }
        else
        {
            if (dp[l - 1][c] > dp[l][c - 1])
            {
                l--;
            }
            else
            {
                c--;
            }
        }
    }

    for (int i = 1; i <= dp[n][m]; i++)
    {
        out << sol[i] << ' ';
    }

    return 0;
}
