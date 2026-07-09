#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef max
    #define max( a, b ) ( ( (a) > (b) ) ? (a) : (b))
#endif
#define MAXSIZE 1024

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    int n, m;
    int a[MAXSIZE], b[MAXSIZE];
    int i, j;

    int LCSuff[MAXSIZE][MAXSIZE];

    scanf("%d", &m);
    scanf("%d", &n);
    for (i = 0; i < m; i ++) {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i ++) {
        scanf("%d", &b[i]);
    }

    for (i = 0; i <= m; i ++) {
        LCSuff[i][0] = 0;
    }
    for (j = 0; j <= n; j ++) {
        LCSuff[0][j] = 0;
    }

    for (i = 1; i <= m; i ++) {
        for (j = 1; j <= n; j ++) {
            LCSuff[i][j] = max(LCSuff[i - 1][j], LCSuff[i][j - 1]);
            if (a[i - 1] == b[j - 1]) {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
            }
        }
    }

    int maxLength = 0;
    for (i = 1; i <= m; i ++) {
        for (j = 1; j <= n; j ++) {
            if (LCSuff[i][j] > maxLength) {
                maxLength = LCSuff[i][j];
            }
        }
    }

    printf("%d", maxLength);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
