#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

static constexpr int NMAX = ((1 << 10) + 1);

int n, m;
int a[NMAX], b[NMAX];

int dp[NMAX][NMAX];

static inline void read()
{
    f.tie(nullptr);

    f >> n >> m;

    for (int i = 1; i <= n; ++i)
        f >> a[i];

    for (int j = 1; j <= m; ++j)
        f >> b[j];

    return;
}

static inline int my_max(const int &a, const int &b)
{
    return ((a > b) ? a : b);
}

static inline void solve_dp()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = my_max(dp[i - 1][j], dp[i][j - 1]);

    return;
}

static inline void go(const int &i, const int &j, const int &k, const int &last_one)
{
    if (!i || !j || !k)
        return;

    if (a[i] == b[j])
    {
        go(i - 1, j - 1, k - 1, 0);

        g << a[i];

        if (last_one)
            g << '\n';
        else
            g << ' ';
    }
    else
    {
        if (dp[i - 1][j] > dp[i][j - 1])
            go(i - 1, j, k, 0);
        else
            go(i, j - 1, k, 0);
    }

    return;
}

static inline void print()
{
    g << dp[n][m] << '\n';

    go(n, m, dp[n][m], 1);

    return;
}

int main()
{
    read();

    solve_dp();

    print();

    return 0;
}
