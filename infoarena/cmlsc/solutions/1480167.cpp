#include <cstdio>
#define max(a,b) (a > b ? a : b)
using namespace std;

const int nmx = 1030;

int n, m, a[nmx], b[nmx], dp[nmx][nmx], r[nmx];

int main(){
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for(int i = 1; i <= m; ++i)
        scanf("%d", &b[i]);

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            dp[i][j] = (a[i] == b[j] ? dp[i-1][j-1] + 1 : max(dp[i-1][j],dp[i][j-1]));

    printf("%d\n", dp[n][m]);

    int p1 = n, p2 = m, p3 = 0;
    while(p1 > 0 && p2 > 0){
        if(a[p1] == b[p2]){
            r[++p3] = a[p1];
            -- p1;
            -- p2;
        }
        else if(p1 > p2)
            -- p1;
        else
            -- p2;
    }

    for(int i = p3; i; --i)
        printf("%d ", r[i]);

    return 0;
}
