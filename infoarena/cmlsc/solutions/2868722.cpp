#include <algorithm>
#include <iostream>

#define NMAX 1025

using namespace std;

int n, m, a[NMAX], b[NMAX], dp[NMAX][NMAX]; //dp[i][j] = lungimea maxima comuna a subsirurilor a[1..i] si b[1..j]

inline void printAns(int x, int y) {
    if(!x || !y) return;
    if(a[x] == b[y]) printAns(x - 1, y - 1), printf("%d ", a[x]);
    else if(dp[x - 1][y] > dp[x][y - 1]) printAns(x - 1, y);
    else printAns(x, y - 1);
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for(int i = 1; i <= m; ++i)
        scanf("%d", &b[i]);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) {
            if(a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            dp[i][j] = max({dp[i][j], dp[i - 1][j], dp[i][j - 1]});
        }
    printf("%d\n", dp[n][m]);
    printAns(n, m);
    return 0;
}
