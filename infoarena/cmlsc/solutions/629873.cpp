#include <stdio.h>
#include <string.h>

#define UP          (0)
#define LEFT        (1)
#define DIAG        (2)

int m, n;
unsigned char a[1025], b[1025];

typedef struct _cost {
    unsigned char cost;
    unsigned char dir;
} cost;

int main() {
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &m, &n);

    int t, in, i, j;

    t = m;
    for (; t; --t) {
        scanf("%d", &in);
        a[m - t] = in;
    }

    t = n;
    for (; t; --t) {
        scanf("%d", &in);
        b[n - t] = in;
    }

    cost mat[m + 1][n + 1];

    for (i = 0; i <= n; ++i) {
        mat[0][i].cost = 0;
        mat[0][i].dir = -1;
    }

    for (i = 0; i <= m; ++i) {
        mat[i][0].cost = 0;
        mat[i][0].dir = -1;
    }

    for (i = 1; i <= m; ++i) {
        for (j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1]) {
                mat[i][j].cost = mat[i - 1][j - 1].cost + 1;
                mat[i][j].dir = DIAG;
            }
            else if (mat[i - 1][j].cost >= mat[i][j - 1].cost) {
                mat[i][j].cost = mat[i - 1][j].cost;
                mat[i][j].dir = UP;
            }
            else {
                mat[i][j].cost = mat[i][j - 1].cost;
                mat[i][j].dir = LEFT;
            }
        }
    }

    int len = mat[m][n].cost;
    printf("%d\n", len);

    unsigned char result[len];
    int pos = len -1;

    i = m;
    j = n;
    while (i > 0 && j > 0) {
        switch(mat[i][j].dir) {
            case DIAG:
                result[pos] = a[i - 1];
                pos--;

                i -= 1;
                j -= 1;
                break;

            case UP:
                i -= 1;
                break;

            case LEFT:
                j -= 1;
        }
    }

    for (i = 0; i < len - 1; ++i) {
        printf("%d ", result[i]);
    }
    printf("%d", result[len - 1]);

    fclose(stdin);
    fclose(stdout);
    return 0;
}