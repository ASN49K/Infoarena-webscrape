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
    //freopen("cmlsc.out", "w", stdout);

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


    // Get results and print
    // The result string is formed in reverse order
    int maxLength = 0;
    int result[MAXSIZE];
    for (i = m, j = n; i > 0 && j > 0 ; )
    {
        if (a[i - 1] == b[j - 1]) {
            result[maxLength] = a[i - 1];
            maxLength ++;
            i--;
            j--;
        } else if (LCSuff[i - 1][j] > LCSuff[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("%d\n", maxLength);
    for (i = maxLength - 1; i >= 0; i--) {
        printf("%d ", result[i]);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
