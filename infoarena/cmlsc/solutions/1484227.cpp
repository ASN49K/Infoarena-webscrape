#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>

#define INF ( (1 << 30) - 1 + (1 << 30) )
#define mod 666013

using namespace std;

int n, m, i, j, q;
int a[1050], b[1050], r[1050];
int dp[1050][1050];

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
        {
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }

    printf("%d\n", dp[n][m]);

    i = n;
    j = m;
    while(i >= 1 && j >= 1)
    {
        if(a[i] == b[j])
        {
            r[ ++q ] = a[i];
            i--;
            j--;
            continue;
        }

        if(dp[i - 1][j] >= dp[i][j - 1])
            i--;
        else
            j--;
    }
    for(i = q; i >= 1; i--)
        printf("%d ", r[i]);

    return 0;
}
