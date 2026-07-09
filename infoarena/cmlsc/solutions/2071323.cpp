#include <bits/stdc++.h>

using namespace std;
const int NMAX=1e3 + 50;
int a[NMAX],b[NMAX],n,m,dp[NMAX][NMAX];
void find_road(int i, int j)
{
    if (!i || !j) return;
    if (a[i]==b[j]) find_road(i-1,j-1),printf("%d ",a[i]);
    else if ( dp[i][j-1] > dp[i-1][j] ) find_road(i,j-1);

    else  find_road(i-1,j);

}
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d", &n, &m);
    int k=0;
    for (int i = 1; i <= n; ++i)
        scanf("%d ", &a[i]);
    for (int i = 1; i <= m; ++i)
        scanf("%d ", &b[i]);
    for (int i = 1; i <= n; ++i)
        dp[i][0]=0;
    for (int j = 1; j <= m; ++j)
        dp[0][j]=0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)


            if (a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    printf("%d", dp[n][m]);
    printf("\n");

    find_road(n,m);
    return 0;
}
