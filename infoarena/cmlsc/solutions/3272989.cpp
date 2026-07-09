#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m;

const int NMAX = 1025;
int a[NMAX], b[NMAX], dp[NMAX][NMAX];

void print(int i, int j)
{
    if (dp[i][j] == 0)
        return;

    if (a[i] == b[j])
    {
        print(i - 1, j - 1);
        fout << a[i] << ' ';
        return;
    }

    if (dp[i - 1][j] > dp[i][j - 1])
    {
        print(i - 1, j);
        return;
    }

    print(i, j - 1);
}

int main()
{
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fin >> a[i];
    for (int i = 1; i <= m; ++i)
        fin >> b[i];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }

    fout << dp[n][m] << '\n';

    print(n, m);

    return 0;
}
