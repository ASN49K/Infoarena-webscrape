#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, dp[1025][1025];
int a[1025], b[1025];
int c[1025];
int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++)
        scanf("%d ", &a[i]);
    for(int j=1; j<=m; j++)
        scanf("%d ", &b[j]);

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1]+1;
            else{
                dp[i][j] = max(max(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j]);
            }
        }
    }
    int o=0;
    int i=n, j=m;
    while(i > 0 && j > 0 && dp[i][j] != 0)
    {
        if(a[i] == b[j])
        {
            c[o++] = a[i];
            i--;
            j--;
        }
        else{
            if(dp[i][j-1] > dp[i-1][j])
                j--;
            else i--;
        }
    }
    printf("%d\n", o);
    for(i=o-1; i>=0; i--)
        printf("%d ", c[i]);
    return 0;
}
