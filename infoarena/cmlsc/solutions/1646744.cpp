#include <bits/stdc++.h>

using namespace std;

const int Nmax = (1 << 10) + 10;

int n , m , i , j;
int a[Nmax] , b[Nmax];
int dp[Nmax][Nmax];

vector < int > v;

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (i = 1; i <= m; ++i)
        scanf("%d", b + i);

    for (i = 1; i <= n; ++i)
        for (j = 1; j <= m; ++j)
        {
            dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            if (a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;
        }

    printf("%d\n", dp[n][m]);

    for (i = n, j = m; i && j ; )
        if (a[i] == b[j])
        {
            v.push_back(a[i]);
            i--; j--;
        }
        else if (dp[i][j-1] == dp[i][j]) j--; else i--;

    for (auto it = v.rbegin(); it != v.rend(); ++it)
        printf("%d ", *it);

    return 0;
}
