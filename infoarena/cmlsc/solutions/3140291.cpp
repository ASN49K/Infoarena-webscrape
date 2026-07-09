#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

static constexpr int NMAX = ((int)(1 << 10) + 1);

int n, m;
int A[NMAX], B[NMAX];

int dp[NMAX][NMAX];

static inline void Read()
{
    f.tie(nullptr);

    f >> n >> m;

    for (int i = 1; i <= n; ++i)
        f >> A[i];

    for (int j = 1; j <= m; ++j)
        f >> B[j];

    return;
}

static inline int my_max(int a, int b)
{
    return ((a > b) ? a : b);
}

static inline void Go(int i, int j, int rem)
{
    if (i < 1 || j < 1)
        return;

    if (!rem)
        return;

    if (A[i] == B[j])
    {
        Go(i - 1, j - 1, rem - 1);

        g << A[i];

        if (rem == dp[n][m])
            g << '\n';
        else
            g << ' ';
    }
    else
    {
        if (dp[i - 1][j] > dp[i][j - 1])
            Go(i - 1, j, rem);
        else
            Go(i, j - 1, rem);
    }

    return;
}

int main()
{
    Read();

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (A[i] == B[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = my_max(dp[i][j - 1], dp[i - 1][j]);

    g << dp[n][m] << '\n';

    Go(n, m, dp[n][m]);

    return 0;
}
