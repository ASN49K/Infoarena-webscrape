#include <stdio.h>
#include <stdlib.h>
#define N 1024

int a[1+N], b[1+N], dp[1+N][1+N];

int max(int x, int y){
    return (x > y ? x : y);
}

void refac_subsir(int l, int c){
    if( l == 0 || c == 0){
        return;
    }
    if(a[l] == b[c]){
        refac_subsir(l-1, c-1);
        printf("%d ", a[l]);
    }
    else if (dp[l-1][c] > dp[l][c-1])
    {
        refac_subsir(l-1, c);
    }
    else
    {
        refac_subsir(l, c-1);
    }
}

int main()
{
    int m, n, i, j;
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d%d", &m, &n);
    for(i = 1; i <= m; i++){
        scanf("%d", &a[i]);
    }
    for(j = 1; j <= n; j++){
        scanf("%d", &b[j]);
    }
    //construiesc matricea dp;
    //cu dp[i][j] = lung max a unu subsir comun prefixelor de lungime i si a
    //si respectiv j din b
    for(i = 1; i <= m; i++){
        for(j = 1; j <= n; j++){
             if (a[i] == b[j])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    printf("%d\n", dp[m][n]);
    refac_subsir(m, n);
    return 0;
}
