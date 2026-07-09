#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1025;

int a[NMAX + 1], b[NMAX + 1], n, m,
    dp[NMAX + 1][NMAX + 1];

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for(int i = 1; i <= m; ++i) scanf("%d", &b[i]);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) {
            if(a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    printf("%d\n", dp[n][m]);

    //for(int i = 1; i <= n; ++i, printf("\n"))
        //for(int j = 1; j <= m; ++j) printf("%4d ", dp[i][j]);
    //printf("\n\n");

    stack<int> st;
    int x = n, y = m;
    while(x && y) {
        if(a[x] == b[y]) st.push(a[x]);
        if(dp[x - 1][y] > dp[x][y - 1]) x--;
        else y--;
    }
    while(!st.empty()) printf("%d ", st.top()), st.pop();
    return 0;
}
