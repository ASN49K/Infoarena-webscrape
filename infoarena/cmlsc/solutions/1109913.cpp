#include <cstdio>
#include <algorithm>

#define Nmax 1030

using namespace std;

int M, N, A[Nmax], B[Nmax], DP[Nmax][Nmax], S[Nmax];

void Citire()
{
    scanf("%d %d", &M, &N);
    for (int i = 1; i <= M; ++i)
        scanf("%d", &A[i]);
    for (int i = 1; i <= N; ++i)
        scanf("%d", &B[i]);
}

void Matrice()
{
    for (int i = 1; i <= M; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (A[i] == B[j])
                DP[i][j] = DP[i - 1][j - 1] + 1;
            else
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
        }
    }
}

void Sir()
{
    for (int i = M, j = N; i >= 1 && j >= 1;)
    {
        if (A[i] == B[j])
        {
            S[++S[0]] = A[i];
            i--;
            j--;
        }
        else if (DP[i - 1][j] >= DP[i][j - 1])
            i--;
        else
            j--;
    }
}

void Afisare()
{
    printf("%d\n", DP[M][N]);
    for (int i = DP[M][N]; i >= 1; --i)
        printf("%d ", S[i]);
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    Citire();
    Matrice();
    Sir();
    Afisare();

    return 0;
}
