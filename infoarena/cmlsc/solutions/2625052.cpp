#include <cstdio>
#include <algorithm>

int a[1032], b[1032], sol[1032];
int dp[1032][1032];
int n, m, l;



int main(){

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    for (int i = 0; i < m; ++i)
        scanf("%d", &b[i]);

 
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    printf("%d\n", dp[n][m]);

    for (int i = n, j = m; i && j;)
    {
        if (a[i - 1] == b[j - 1])
        {
            sol[l++] = a[i - 1];
            --i;
            --j;
        }
        else
        {
            if (dp[i][j - 1] < dp[i - 1][j])
                --i;
            else
                --j;
        }
    }

    for (int i = l - 1; i >= 0; --i)
        printf("%d ", sol[i]);

		
	return 0;
}