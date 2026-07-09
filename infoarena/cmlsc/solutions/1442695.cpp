#include <bits/stdc++.h>
using namespace std;

int n,m,a[1025],b[1025],dp[1025][1025],outp[1025];

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1 ; i <= n ; i++) scanf("%d", &a[i]);
    for(int i = 1 ; i <= m ; i++) scanf("%d", &b[i]);

    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            dp[i][j] = ((a[i] == b[j]) ? dp[i-1][j-1] + 1 : max(dp[i-1][j], dp[i][j-1]));

    printf("%d\n", dp[n][m]);

    int i = n, j = m,counter = 0;
    while( i > 0 && j > 0)
        if(a[i] == b[j]) outp[counter++] = a[i], i--, j--;
        else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;

    for(int i = counter - 1 ; i >= 0; i--)
        printf("%d ", outp[i]);
    return 0;
}
