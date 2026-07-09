#include <stdio.h>
#include <string.h>

#define NMAX 1024
#define IN "cmlsc.in"
#define OUT "cmlsc.out"

static int sol[NMAX + 1][NMAX + 1];
static int A[NMAX + 1], B[NMAX + 1];

int lcs(int, int);
void lcs_print(int, int);

int lcs(int n, int m)
{
    int i, j;

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++) {
            if (A[i] == B[j])
                sol[i][j] = sol[i - 1][j - 1] + 1;
            else if (sol[i - 1][j] >= sol[i][j - 1])
                sol[i][j] = sol[i - 1][j];
            else
                sol[i][j] = sol[i][j - 1];
        }

    return sol[n][m];
}

void lcs_print(int i, int j)
{
    if (i == 0 || j == 0)
        return;

    if (sol[i][j] == sol[i - 1][j])
        lcs_print(i - 1, j);
    else if (sol[i][j] == sol[i][j - 1])
        lcs_print(i, j - 1);
    else {
        lcs_print(i - 1, j - 1);
        printf("%d ", A[i]);
    }
}

int main(void)
{
    int n, m, i;

    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);

    scanf("%d %d", &n, &m);

    for (i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    for (i = 1; i <= m; i++)
        scanf("%d", &B[i]);

    printf("%d\n", lcs(n, m));
    lcs_print(n, m);
    puts("");

    return 0;
}

