
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILEIN  "cmlsc.in"
#define FILEOUT "cmlsc.out"

#define MAX(a,b)    ( (a) < (b) ? (b) : (a) )

int M, N, MAX;

int **C;
int *X, *Y, *SOL;

void printv(int *v, int len)
{
    for (int i=0; i < len; i++)
        printf("%d ", v[i]);
    printf("\n");
}

void printm(int **mat, int m, int n)
{
    for (int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void LCSlength()
{
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (X[i] == Y[j])
                C[i][j] = C[i-1][j-1] + 1;
            else
                C[i][j] = MAX(C[i][j-1], C[i-1][j]);
        }
    }
}

void backtrack(int i, int j, int sol_idx)
{
    if (i == 0 || j == 0)
    {
        printv(SOL, MAX);
        exit(0);
    }

    if (X[i] == Y[j])
    {
        SOL[MAX - 1 - sol_idx] = X[i];
        backtrack(i-1, j-1, sol_idx + 1);
    }
    else
    {
        if (C[i][j-1] > C[i-1][j])
            backtrack(i, j-1, sol_idx);
        else
            backtrack(i-1, j, sol_idx);
    }
}

int main(void)
{
    freopen(FILEIN,  "r", stdin);
    freopen(FILEOUT, "w", stdout);

    scanf("%d %d\n", &M, &N);

    // get resources
    C = (int **)calloc(M+1, sizeof(int*));
    for (int i = 0; i<=M; i++)
        C[i] = (int*)calloc(N+1, sizeof(int));

    X = (int*)calloc(M+1, sizeof(int));
    Y = (int*)calloc(N+1, sizeof(int));

    for (int i = 1; i<=M; i++)
        scanf("%d", &X[i]);

    for (int i = 1; i<=N; i++)
        scanf("%d", &Y[i]);

    // get max LCS length
    LCSlength();

    MAX = C[M][N];
    SOL = (int*)calloc(MAX, sizeof(int));

    printf("%d\n", MAX);
    backtrack(M, N, 0);

    return 0;
}
