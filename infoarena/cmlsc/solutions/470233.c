#include <stdio.h>
#define DEBUG 0
int cost[1030][1030];
int n, m, i, j;
int a[1030];
int b[1030];

void recwrite(int i, int j) {
    if (i==0 || j==0) return;
    if (a[i]==b[j]) {
        recwrite(i-1, j-1);
        printf("%d ", a[i]);
    } else {
        if (cost[i][j] = cost[i-1][j])
            recwrite(i-1, j);
        else 
            recwrite(i, j-1);
    }
}
int main() {
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for (i=0;i<n;i++) {
        scanf("%d", &a[i+1]);
    }
    for (i=0;i<m;i++) {
        scanf("%d", &b[i+1]);
    }
    for (j=0;j<=m;j++) cost[0][j] = 0;
    for (i=0;i<=n;i++) cost[i][0] = 0;
    for (i=1;i<=n;i++) {
        for (j=1;j<=m;j++) {
            if (a[i]==b[j]) {
                cost[i][j] = cost[i-1][j-1]+1;
            } else {
                if (cost[i-1][j]>=cost[i][j-1]) {
                    cost[i][j] = cost[i-1][j];
                } else {
                    cost[i][j] = cost[i][j-1];
                }
            }
        }
    }
    printf("%d\n", cost[n][m]);
    recwrite(n, m);
    return 0;
}