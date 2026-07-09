#include <iostream>
#include <cstdio>

using namespace std;

const int NMAX = (1 << 10) + 1;

int N, A[NMAX];
int M, B[NMAX];

int dp[NMAX][NMAX];

namespace InParser
{
static const int BSIZE = (1 << 16);

static int pos = (BSIZE - 1);
static char buff[BSIZE];

static inline char Char ()
{
    ++pos;

    if(pos == BSIZE)
    {
        pos = 0;

        int n = fread(buff, 1, BSIZE, stdin);

        if(n != BSIZE)
            for(int i = n; i < BSIZE; ++i)
                buff[i] = 0;
    }

    return buff[pos];
}

inline int Int ()
{
    int ans = 0;

    for( ; ; )
    {
        char Ch = Char();

        if(Ch >= '0' && Ch <= '9')
        {
            ans = (int)(Ch - '0');

            break;
        }
    }

    for( ; ; )
    {
        char Ch = Char();

        if(Ch >= '0' && Ch <= '9')
            ans = ans * 10 + (int)(Ch - '0');
        else
            break;
    }

    return ans;
}
};

static inline void Read ()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    N = InParser :: Int(), M = InParser :: Int();

    for(int i = 1; i <= N; ++i)
        A[i] = InParser :: Int();

    for(int j = 1; j <= M; ++j)
        B[j] = InParser :: Int();

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

    return;
}

static inline void Go (int i, int j, int Lg)
{
    if(Lg < 1)
        return;

    if(A[i] == B[j])
    {
        Go(i - 1, j - 1, Lg - 1);

        printf("%d", A[i]);

        if(Lg == dp[N][M])
            printf("\n");
        else
            printf(" ");

        return;
    }

    if(dp[i - 1][j] > dp[i][j - 1])
        Go(i - 1, j, Lg);
    else
        Go(i, j - 1, Lg);

    return;
}

static inline void Write ()
{
    printf("%d\n", dp[N][M]);

    Go(N, M, dp[N][M]);

    return;
}

int main()
{
    Read();

    Solve();

    Write();

    return 0;
}
