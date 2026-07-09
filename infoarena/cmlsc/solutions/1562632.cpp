#include <cstdio>
#define max(a,b) (a > b ? a : b)
using namespace std;

const int nmx = 1030;

int n,m,a[nmx],b[nmx];
int dp[nmx][nmx];

void afish(int i, int j) {
    if(a[i] == b[j]) {
        afish(i-1,j-1);
        printf("%d ", a[i]);
    } else if(i > 1 && dp[i-1][j] > dp[i][j-1])
        afish(i-1,j);
    else if(j > 1)
        afish(i,j-1);
}

int main() {
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for(int i = 1; i <= m; ++i)
        scanf("%d", &b[i]);

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);

    printf("%d\n", dp[n][m]);

    afish(n,m);

    return 0;
}
