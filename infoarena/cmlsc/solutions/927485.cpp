#include <cstdio>
#include <algorithm>

#define MAX 1024

using namespace std;

int N, M;
int X[MAX], Y[MAX], C[MAX + 1][MAX + 1];
int Res[MAX], ResP = 0;

void backtrack(int i, int j)
{
    if (i == 0 || j == 0)
        return; //  Nimic de facut.
    else if (X[i - 1] == Y[j - 1])
    {
        backtrack(i - 1, j - 1);
        Res[ResP++] = X[i - 1];
    }
    else
    {
        if (C[i][j - 1] > C[i - 1][j])
            backtrack(i, j - 1);
        else
            backtrack(i - 1, j);
    }
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &N, &M);

    int i, j;

    for (i = 0; i < N; i++)
        scanf("%d", &X[i]);
    for (i = 0; i < M; i++)
        scanf("%d", &Y[i]);

    for (i = max(N, M); i >= 0; i--)
    {
        C[0][i] = 0;
        C[i][0] = 0;
    }

    for (i = 1; i <= N; i++)
        for (j = 1; j <= M; j++)
            if (X[i - 1] == Y[j - 1])
                C[i][j] = C[i - 1][j - 1] + 1;
            else
                C[i][j] = max(C[i][j - 1], C[i - 1][j]);

    printf("%d\n", C[N][M]);

    backtrack(N, M);

    for (i = 0; i < ResP; i++)
        printf("%d ", Res[i]);

    return 0;
}
