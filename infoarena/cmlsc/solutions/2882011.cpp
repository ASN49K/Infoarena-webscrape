#include <fstream>
#include <algorithm>

constexpr int SIZE = 1025;

int M, N, A[SIZE], B[SIZE];
int dp[SIZE][SIZE], substr[SIZE];

int main()
{
    std::ifstream in("cmlsc.in");
    in >> M >> N;
    for (int i = 1; i <= M; ++i)
        in >> A[i];
    for (int i = 1; i <= N; ++i)
        in >> B[i];

    for (int k1 = 1; k1 <= M; ++k1)
    {
        for (int k2 = 1; k2 <= N; ++k2)
        {
            if (A[k1] == B[k2])
                dp[k1][k2] = 1 + dp[k1 - 1][k2 - 1];
            else
                dp[k1][k2] = std::max(dp[k1 - 1][k2], dp[k1][k2 - 1]);
        }
    }

    std::ofstream out("cmlsc.out");
    out << dp[M][N] << '\n';

    int cnt = dp[M][N], size = cnt;
    while (M > 0 && N > 0 && dp[M][N] > 0)
    {
        if (A[M] == B[N])
            substr[cnt--] = A[M], --M, --N;

        else if (dp[M][N - 1] == dp[M][N])
            --N;
        else
            --M;
    }

    for (int i = 1; i <= size; ++i)
        out << substr[i] << ' ';
}