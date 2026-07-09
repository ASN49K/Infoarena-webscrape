#include <cstdio>
#define max(a,b) (a > b ? a : b)
#define nmx 1030
using namespace std;

int n,m,a[nmx],b[nmx],dp[nmx][nmx];

void afish(int n1, int n2){
    if(not n1 || not n2)
        return;
    if(a[n1] == b[n2]){
        afish(n1-1,n2-1);
        printf("%d ", a[n1]);
    }
    else if(dp[n1-1][n2] > dp[n1][n2-1])
        afish(n1-1,n2);
    else
        afish(n1,n2-1);
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
            if(a[i] == b[j])
                  dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);

    printf("%d\n", dp[n][m]);
    afish(n,m);

    return 0;
}
