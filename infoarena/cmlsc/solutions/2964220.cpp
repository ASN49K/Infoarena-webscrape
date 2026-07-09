#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int N = 1024;
int dp[N+1][N+1];
int n, m, a[N+1], b[N+1];

void reconst(int l, int c)
{
    if (l == 0 || c == 0)
    {
        return ;
    }
    if (a[l] == b[c])
    {
        reconst(l - 1, c - 1);
        out << a[l] << " ";
    }
    else
    {
        if (dp[l - 1][c] > dp[l][c - 1])
        {
            reconst(l - 1, c);
        }
        else
        {
            reconst(l, c - 1);
        }
    }
}

int main()
{
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
            if (a[i] != b[j])
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            else
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
        }
    }
    out << dp[n][m] << "\n";
    reconst(n, m);
    return 0;
}
