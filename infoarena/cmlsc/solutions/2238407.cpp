#include <bits/stdc++.h>
using namespace std;

const int N = 1030;
int A[N], B[N], c[1025];
short int dp[N][N];

int main() {
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int n, m, nr = 0, x, l = 0, y;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d", &B[i]);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (A[i] == B[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    nr = dp[n][m];

    x = n;
    y = m;
    while(x > 0 && y > 0) {
        if(A[x] == B[y]) {
            c[nr - l] = A[x];
            l++;
            x--;
            y--; }
        else {
            if(dp[x - 1][y] < dp[x][y - 1])
                y--;
            else
                x--; } }

    printf("%d\n", nr);
    for (int i = 1; i <= nr; i++)
        printf("%d ", c[i]);

    return 0;
}
