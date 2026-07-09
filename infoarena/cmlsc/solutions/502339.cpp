#include <cstdio>

#define MAX 1030

#define FIN "cmlsc.in"
#define FOUT "cmlsc.out"

int M, N;
int X[MAX], Y[MAX], V[MAX][MAX], R[MAX];

int max(int A, int B)
{
    return A > B ? A : B;
}

int main()
{
    int i, j, x1, y1;

    freopen(FIN, "r", stdin);
    freopen(FOUT, "w", stdout);

    scanf("%d%d", &M, &N);

    for (i = 1; i <= M; ++ i)
        scanf("%d", &X[i]);
    for (i = 1; i <= N; ++ i)
        scanf("%d", &Y[i]);

    for (i = 1; i <= M; ++ i)
        for (j = 1; j <= N; ++ j)
            V[i][j] = (X[i] == Y[j]) ? (V[i - 1][j - 1] + 1) : max(V[i - 1][j], V[i][j - 1]);

    for (i = 1, x1 = y1 = 0; i <= M; ++ i)
        for (j = 1; j <= N; ++ j)
            if (V[i][j] > V[x1][y1])    x1 = i, y1 = j;

    for (i = x1, j = y1; i && j;)
    {
        if (X[i] == Y[j])
            R[++ R[0]] = X[i], --i, -- j;
        else
            V[i][j - 1] > V[i - 1][j] ? -- j : -- i;
    }

    printf("%d\n", R[0]);

    for (i = R[0]; i; -- i)
        printf("%d ", R[i]);

    printf("\n");
}
