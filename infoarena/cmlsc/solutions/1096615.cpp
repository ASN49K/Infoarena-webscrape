#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 1025

int N, M, Bst[MAX][MAX], A[MAX], B[MAX];

void DP()
{
    for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++)
    {
        if (A[i] == B[j])
            Bst[i][j] = 1 + Bst[i-1][j-1];
        else
            Bst[i][j] = max(Bst[i-1][j], Bst[i][j-1]);
    }
}

void Afis(int N, int M)
{
    if (Bst[N][M] == 0)
    {
        return;
    }
    else
    {
        if (A[N] == B[M])
        {
            Afis(N - 1, M - 1);
            printf("%d ", A[N]);
        }
        else
        {
            if (Bst[N - 1][M] > Bst[N][M - 1])
                Afis(N - 1, M);
            else
                Afis(N, M - 1);
        }
    }
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= M; i++) scanf("%d", &B[i]);

    DP();
    printf("%d\n", Bst[N][M]);
    Afis(N, M);
}
