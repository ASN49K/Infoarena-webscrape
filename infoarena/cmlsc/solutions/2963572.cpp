#include <fstream>
#include <cstdlib>

using namespace std;
const int N = 1025;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int dp[N][N], a[N], b[N];

void refs(int l, int c)
{
    if (l == 0 || c == 0)
        return;
    if (a[l] == b[c])
    {
        refs(l - 1, c - 1);
        out << a[l] << " ";
    }
    else
    {
        if (dp[l - 1][c] > dp[l][c - 1])
            refs(l - 1, c);
        else
            refs(l, c - 1);
    }
}

int main()
{
    int n, m;
    in >> n >> m;
    for (int i = 1; i <= n; i++)
        in >> a[i];
    for (int i = 1; i <= m; i++)
        in >> b[i];
    in.close();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i -1][j], dp[i][j - 1]);
        }
    }
    out << dp[n][m] << "\n";
    refs(n, m);
    out.close();
    return 0;
}
