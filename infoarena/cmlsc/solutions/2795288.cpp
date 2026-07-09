#include <iostream>
#include <stack>

#define NMAX 1030

using namespace std;

int n, m, a[NMAX], b[NMAX], dp[NMAX][NMAX];

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for(int i = 1; i <= m; ++i) scanf("%d", &b[i]);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    printf("%d\n", dp[n][m]);
    stack<int> ans;
    for(int i = n, j = m; i && j;) {
        if(a[i] == b[j]) {
            ans.push(a[i]);
            --i, --j;
        } else {
            if(dp[i - 1][j] > dp[i][j - 1]) --i;
            else --j;
        }
    }
    while(!ans.empty()) printf("%d ", ans.top()), ans.pop();
    return 0;
}
