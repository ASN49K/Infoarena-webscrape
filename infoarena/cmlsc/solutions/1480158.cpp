#include <cstdio>
#define max(a,b) (a > b ? a : b)
using namespace std;

const int nmx = 1030;

int n, m, a[nmx], b[nmx], dp[nmx][nmx];

void rec(const int i, const int j){
    if(i < 1 || j < 1)
        return;
    if(a[i] == b[j]){
        rec(i-1,j-1);
        printf("%d ", a[i]);
    }
    else if(i > j)
        rec(i-1,j);
    else
        rec(i,j-1);
}

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
    rec(n,m);

    return 0;
}
