#include <fstream>
#include <stack>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

const int NMAX = (1 << 10) + 1;

int N, A[NMAX];
int M, B[NMAX];

int dp[NMAX][NMAX];

stack < int > St;

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

static inline void Build_DP ()
{
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j)
            if(A[i] == B[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = my_max(dp[i - 1][j], dp[i][j - 1]);

    return;
}

static inline void Go (int i, int j)
{
    if(i < 1 || j < 1)
        return;

    if(A[i] == B[j])
    {
        St.push(A[i]);

        Go(i - 1, j - 1);

        return;
    }

    if(dp[i - 1][j] > dp[i][j - 1])
        Go(i - 1, j);
    else
        Go(i, j - 1);

    return;
}

static inline void Write ()
{
    int Lg = dp[N][M];

    for(int x = 1; x <= Lg; ++x)
    {
        g << St.top(), St.pop();

        if(x < Lg)
            g << ' ';
    }

    g << '\n';

    return;
}

static inline void Solve ()
{
    g << dp[N][M] << '\n';

    Go(N, M);

    Write();

    return;
}

int main()
{
    Read();

    Build_DP();

    Solve();

    return 0;
}
