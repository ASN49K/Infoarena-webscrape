#include <stdio.h>

using namespace std;

int n, m, a[1024], b[1024], c[1024], l[1024][1024], i, j;

int main() {
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d %d", &m, &n);
    for(i = 1; i <= m; i++)
        scanf("%d", &a[i]);
    for(i = 1; i <= n; i++)
        scanf("%d", &b[i]);

    for(i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            if(a[i] == b[j])
                l[i][j] = 1 + l[i-1][j-1];
            else
                l[i][j] = l[i-1][j] > l[i][j-1] ? l[i-1][j] : l[i][j-1];

    i = m;
    j = n;
    int p = l[m][n];
    while (p) {
        if(a[i] == b[j]) {
            c[p] = a[i];
            p--;
            i--;
            j--;
        } else if (l[i][j - 1] > l[i - 1][j])
            j--;
        else
            i--;
    }

    printf("%d\n", l[m][n]);
    for (i = 1; i <= l[m][n]; i++)
        printf("%d ", c[i]);
    printf("\n");
    return 0;
}
