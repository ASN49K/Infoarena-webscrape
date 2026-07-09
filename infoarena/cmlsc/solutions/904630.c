#include <stdio.h>

#define IN_FILE  "cmlsc.in"
#define OUT_FILE "cmlsc.out"

#define NMAX 1025

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int c[NMAX][NMAX];

int LCS(const int *a, int n, const int *b, int m, int *lcs)
{
    int i, j;

    /* Prima linie si prima coloana */
    for (i = 0; i <= n; i++) {
        c[i][0] = 0;
    }
    for (j = 1; j <= m; j++) {
        c[0][j] = 0;
    }

    /* Restul matricei */
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
            } else {
                c[i][j] = MAX(c[i - 1][j], c[i][j - 1]);
            }
        }
    }

    int len = c[n][m];
    i = n;
    j = m;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            lcs[c[i][j] - 1] = a[i - 1];
            i--;
            j--;
        } else if (c[i][j] == c[i - 1][j]) {
            i--;
        } else {
            j--;
        }
    }

    return len;
}

int main(void)
{
    freopen(IN_FILE, "r", stdin);
    freopen(OUT_FILE, "w", stdout);

    int a[NMAX], n, b[NMAX], m, i;

    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    for (i = 0; i < m; i++) {
        scanf("%d", b + i);
    }

    int lcs[NMAX];
    int len = LCS(a, n, b, m, lcs);

    printf("%d\n", len);
    for (i = 0; i < len; i++) {
        printf("%d ", lcs[i]);
    }
    
    return 0;
}
