/**
 * Per "Introduction to Algorithms", CLRS, 3rd edition
 * Solves http://infoarena.ro/problema/cmlsc
 *
 *  Input: n m <a1, a2, ..., aN> <b1, b2, ..., bM>
 * Output: p <c1, c2, ..., cP>
 *
 * n, m: number of elements
 * a, b: two arrays
 *    p: longest common subsequence
 *   cP: element of the subsequence
 */
#include <stdio.h>

#define NMAX 1024
#define IN "cmlsc.in"
#define OUT "cmlsc.out"

static int sol2[NMAX + 1];
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

int lcs2(int n, int m) /* O(n) space without recomputing solution */
{
    int i, j, r = 0;

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++) {
            if (A[i] == B[j] && sol2[i - 1] < j) {
                sol2[i] = j;
                ++r;
            }
        }

    return r;
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

    printf("%d\n", lcs2(n, m));
    lcs_print(n, m);
    puts("");

    return 0;
}

