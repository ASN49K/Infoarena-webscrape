#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAXN 1500
using namespace std;

int n, m, a[MAXN], b[MAXN], dp[MAXN][MAXN], bk[MAXN][MAXN];
vector<int> sol;

void print(int i, int j) {
    while(i && j) {
        if(bk[i][j] == 1) --i;
        else if(bk[i][j] == 2) --j;
        else {
            sol.push_back(a[i]);
            --i, --j;
        }
    }
    reverse(sol.begin(), sol.end());
    for(auto x: sol)
        printf("%d ", x);
    printf("\n");
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);


    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= m; i++)
        scanf("%d", &b[i]);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            dp[i][j] = -1;
            if(dp[i - 1][j] > dp[i][j]) {
                dp[i][j] = dp[i - 1][j];
                bk[i][j] = 1;
            }
            if(dp[i][j - 1] > dp[i][j]) {
                dp[i][j] = dp[i][j - 1];
                bk[i][j] = 2;
            }
            if(a[i] == b[j] && dp[i - 1][j - 1] + 1 > dp[i][j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                bk[i][j] = 3;
            }
        }

    printf("%d\n", dp[n][m]);
    print(n, m);

    return 0;
}
