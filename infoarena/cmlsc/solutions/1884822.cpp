#include <cstdio>
#include <algorithm>
#include <stack>

#define NMAX 1025

using namespace std;

int m, n;
int a[NMAX], b[NMAX];
int dp[NMAX][NMAX];
stack<int> lcs;

void read() {
    scanf("%d%d", &m, &n);

    for (int i = 1; i <= m; ++i) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &b[i]);
    }
}

void solve() {
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    for (int i = m, j = n; i >= 1 && j >= 1;) {
        if (dp[i][j] == dp[i - 1][j]) {
            i--;
        } else if (dp[i][j] == dp[i][j - 1]) {
            j--;
        } else {
            lcs.push(a[i]);
            i--;
            j--;
        }
    }

    printf("%d\n", dp[m][n]);

    while (!lcs.empty()) {
        printf("%d ", lcs.top());
        lcs.pop();
    }
}

int main() {
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    read();
    solve();
}
