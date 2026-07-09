#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

const int NMAX = (1 << 10) + 1;

int N, M;
int A[NMAX], B[NMAX];

int dp[NMAX][NMAX];

static inline void Read ()
{
    f.tie(nullptr);

    f >> N >> M;

    for(int i = 1; i <= N; ++i)
        f >> A[i];

    for(int j = 1; j <= M; ++j)
        f >> B[j];

    return;
}

static inline int my_max (int a, int b)
{
    return ((a > b) ? a : b);
}

static inline void Solve ()
{
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j)
            if(A[i] == B[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = my_max(dp[i - 1][j], dp[i][j - 1]);

    g << dp[N][M] << '\n';

    return;
}

static inline void Write (int Lg, int i, int j)
{
    if(!Lg || !i || !j)
        return;

    if(A[i] == B[j])
    {
        Write(Lg - 1, i - 1, j - 1);

        g << A[i];

        if(Lg == dp[N][M])
            g << '\n';
        else
            g << ' ';

        return;
    }

    if(dp[i - 1][j] > dp[i][j - 1])
        Write(Lg, i - 1, j);
    else
        Write(Lg, i, j - 1);

    return;
}

int main()
{
    Read();

    Solve();

    Write(dp[N][M], N, M);

    return 0;
}
