#include <stdio.h>

int main()
{
    int m, n;
    int a[1024], b[1024], sol[1024], din[1025][1025] = {0}, max, i, j, k;

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &m, &n);
    for (i = 0; i < m; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
        scanf("%d", &b[i]);

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (a[i] == b[j])
                din[i+1][j+1] = din[i][j] + 1;
            else if (din[i][j+1] > din[i+1][j])
                din[i+1][j+1] = din[i][j+1];
            else
                din[i+1][j+1] = din[i+1][j];
        }
    }

    max = k = din[i][j];

    while (i != 0 || j != 0) {
        if (i == 0) {
            j--;
        } else if (j == 0) {
            i--;
        } else if (a[i-1] == b[j-1]) {
            sol[--k] = a[i-1];
            i--;
            j--;
        } else if (din[i-1][j] > din[i][j-1]) {
            i--;
        } else {
            j--;
        }

    }

    printf("%d\n", max);
    for (i = 0; i < max; i++)
        printf("%d ", sol[i]);

    return 0;
}