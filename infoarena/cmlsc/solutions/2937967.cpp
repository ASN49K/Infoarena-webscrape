#include <fstream>

using namespace std;

const int N = 10000;
int a[N + 1], b[N + 1], n, m;
int dp[N + 1][N + 1];

void subsir(ofstream &out, int l, int c)
{
    if (l == 0 || c == 0)
    {
        return;
    }
    if (a[l] == b[c])
    {
        subsir(out, l - 1, c - 1);
        out << a[l] << ' ';
    }
    else if (dp[l - 1][c] > dp[l][c - 1])
    {
        subsir(out, l - 1, c);
    }
    else
    {
        subsir(out, l, c - 1);
    }
}
int main()
{
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");

    in >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
        in >> a[i];
    }
    for (int j = 1; j <= m; j ++)
    {
        in >> b[j];
    }

    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= m; j ++)
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

    subsir(out, n, m);

    in.close();
    out.close();

    return 0;
}
