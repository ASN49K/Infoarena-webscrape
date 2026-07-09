#include <cstdio>
#include <algorithm>

#define NMAX 1005

using namespace std;

int A[NMAX], B[NMAX], M, N, dp[NMAX][NMAX], cmlsc[NMAX];

void citire()
{
    scanf("%d %d", &M, &N);
    for (int i = 1; i <= M; ++i)
        scanf("%d", &A[i]);
    for (int i = 1; i <= N; ++i)
        scanf("%d", &B[i]);
}

void dinamica()
{
    for (int i = 1; i <= M; ++i)
        for (int j = 1; j <= N; ++j)
            if (A[i] == B[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
}

void formare_cmlsc()
{
    for (int i = M, j = N; i >= 1 && j >= 1;)
    {
        if (A[i] == B[j])
        {
            cmlsc[++cmlsc[0]] = A[i];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
}

void afisare()
{
    printf("%d\n", dp[M][N]);
    for (int i = cmlsc[0]; i >= 1; --i)
        printf("%d ", cmlsc[i]);
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    citire();
    dinamica();
    formare_cmlsc();
    afisare();

    return 0;
}
