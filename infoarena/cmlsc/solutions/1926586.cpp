#include <bits/stdc++.h>
#define maxN 1026
using namespace std;

FILE *fin = freopen("cmlsc.in", "r", stdin);
FILE *fout = freopen("cmlsc.out", "w", stdout);

/* ------------- */
int n, m;
int a[maxN], b[maxN];
/* ------------- */
int dp[2][maxN], p[2][maxN];
/* ------------- */
int len;
int ans[maxN];
/* ------------- */

void read()
{
    scanf("%d %d\n", &n, &m);
    for (int i = 1; i <= n; ++ i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; ++ i)
        scanf("%d", &b[i]);
}

void solve(int r1, int c1, int r2, int c2)
{
    if (r1 == r2)
    {
        for (int i = c1; i <= c2; ++ i)
            if (a[r1] == b[i])
            {
                ans[++ len] = a[r1];
                return ;
            }
        return ;
    }
    else
    {
        int mid = (r1 + r2) >> 1, t = 0;
        if (mid == 2)
        {
            int k = 0;
        }
        memset(dp, 0, sizeof(dp));
        memset(p, 0, sizeof(p));
        for (int i = r1; i <= r2; ++ i)
        {
            t = !t;
            memset(dp[t], 0, sizeof(dp[t]));
            memset(p[t], 0, sizeof(p[t]));

            for (int j = c1 - 1; j <= c2; ++ j)
            {
                p[t][j] = j;
                dp[t][j] = 0;
            }

            for (int j = c1; j <= c2; ++ j)
            {
                if (a[i] == b[j])
                {
                    dp[t][j] = dp[!t][j - 1] + 1;
                    if (i > mid) p[t][j] = p[!t][j - 1];
                }
                else if (dp[!t][j] >= dp[t][j - 1])
                {
                    dp[t][j] = dp[!t][j];
                    if (i > mid) p[t][j] = p[!t][j];
                }
                else
                {
                    dp[t][j] = dp[t][j - 1];
                    if (i > mid) p[t][j] = p[t][j - 1];
                }
            }
        }

        int col = p[t][c2];

        if (col >= c1)
            solve(r1, c1, mid, col);
        if (col + 1 <= c2 && mid + 1 <= r2)
            solve(mid + 1, col + 1, r2, c2);
    }
}

void write()
{
    printf("%d\n", len);
    for (int i = 1; i <= len; ++ i)
        printf("%d ", ans[i]);
}

int main()
{
    read();
    solve(1, 1, n, m);
    write();
    return 0;
}
