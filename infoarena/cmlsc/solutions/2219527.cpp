#include <iostream>
#include <stdio.h>
using namespace std;

const int max_size = 1030;
int n, m, i, j, cnt, a[max_size], b[max_size], sol[max_size], dp[max_size][max_size];
int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d%d", &n, &m);

    for(i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for(i = 1; i <= m; i++)
        scanf("%d", &b[i]);
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
    printf("%d\n", dp[n][m]);
    i = n; j = m;
    while(i)
    {
        if(a[i] == b[j])
            {sol[++cnt] = a[i];i--;j--;}
        else if(dp[i][j-1] > dp[i-1][j])
            j--;
        else i--;
    }
    for(i = cnt; i; i--)
        printf("%d ", sol[i]);
    return 0;
}
