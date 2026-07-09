#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, dp[1030][1030], len;

int main()
{

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d%d", &n, &m);
    int a[n+1], b[m+1];

    for(int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for(int i = 1; i <= m; ++i)
        scanf("%d", b + i);

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(a[i] == b[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));

    vector<int> rez;
    for(int i = n, j = m; i; )
        if(a[i] == b[j])
            rez.push_back(a[i]), --i, --j;
        else if(dp[i-1][j] < dp[i][j-1])
            --j;
        else
            --i;

    len = rez.size();
    printf("%d\n", len);
    for(int i = len-1; i >= 0; --i)
        printf("%d ", rez[i]);

    return 0;
}
