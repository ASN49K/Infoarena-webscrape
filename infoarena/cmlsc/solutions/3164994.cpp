#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

static constexpr int NMAX = ((1 << 10) + 1);

int n, A[NMAX];
int m, B[NMAX];

int dp[NMAX][NMAX];

static inline void read()
{
    f.tie(nullptr);

    f >> n >> m;

    for (int i = 1; i <= n; ++i)
        f >> A[i];

    for (int i = 1; i <= m; ++i)
        f >> B[i];

    return;
}

static inline int my_max(const int &a, const int &b)
{
    return ((a > b) ? a : b);
}

static inline void go(const int &i, const int &j, const int &size, const bool &flag)
{
    if (i < 1 || j < 1)
        return;

    if (!size)
        return;

    if (A[i] == B[j])
    {
        go((i - 1), (j - 1), (size - 1), 0);

        g << A[i];

        if (flag)
            g << '\n';
        else
            g << ' ';

        return;
    }

    if (dp[i - 1][j] > dp[i][j - 1])
        go(i - 1, j, size, flag);
    else
        go(i, j - 1, size, flag);

    return;
}

static inline void reconstruct(const int &x)
{
    g << x << '\n';

    if (!x)
        return;

    go(n, m, x, 1);

    return;
}

int main()
{
    read();

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (A[i] == B[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = my_max(dp[i - 1][j], dp[i][j - 1]);

    reconstruct(dp[n][m]);

    return 0;
}
