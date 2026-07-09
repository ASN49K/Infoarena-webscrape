/* CMLSC Infoarena (Cel mai lung subsir crescator) http://infoarena.ro */
#include <stdio.h>

#define SIZE 1100

int n, m, a[SIZE], b[SIZE], len[SIZE][SIZE];

void afis(int i, int j)
{
    if (i && j) {
        if (a[i] == b[j] && len[i][j] == len[i - 1][j - 1] + 1) {
            afis(i - 1, j - 1);
            printf("%d ", a[i]);
        } else if (len[i][j] == len[i - 1][j]) {
            afis(i - 1, j);
        } else {
            afis(i, j - 1);
        }
    }
}

int main(void)
{
    int i, j;

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (i = 1; i <= m; i++)
        scanf("%d", &b[i]);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            len[i][j] = len[i - 1][j];
            if (len[i][j - 1] > len[i][j])
                len[i][j] = len[i][j - 1];
            if (a[i] == b[j] && len[i - 1][j - 1] >= len[i][j])
                len[i][j] = len[i - 1][j - 1] + 1;
        }
    }

    printf("%d\n", len[n][m]);
    afis(n, m);
    printf("\n");

    return 0;
}
