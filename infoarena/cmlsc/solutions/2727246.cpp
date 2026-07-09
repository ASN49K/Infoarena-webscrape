#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1024;

int a[NMAX + 1], b[NMAX + 1], al, bl;
vector<int> dp[NMAX + 1][NMAX + 1];

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d%d", &al, &bl);
    for(int i = 1; i <= al; ++i) scanf("%d", &a[i]);
    for(int i = 1; i <= bl; ++i) scanf("%d", &b[i]);
    for(int i = 1; i <= al; ++i)
        for(int j = 1; j <= bl; ++j)
            if(a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1];
                dp[i][j].push_back(a[i]);
            } else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    printf("%d\n", (int)dp[al][bl].size());
    for(const auto el : dp[al][bl]) printf("%d ", el);
    return 0;
}
