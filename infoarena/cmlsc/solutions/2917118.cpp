#include <stdio.h>
#include <vector>

#define MAX_N 1024

using namespace std;

int main() {
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    int m, n, a[MAX_N], b[MAX_N], dp[MAX_N][MAX_N], c[MAX_N];
    scanf("%d %d", &m, &n);

    for (int i = 0; i < m; ++i) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i] == b[j]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
	
    int k = 0;
    int i = m - 1;
    int j = n - 1;

    while (i >= 0 && j >= 0) {
        if (a[i] == b[j]) {
            c[k] = a[i];
            k++;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("%d\n", k);

    for (int i = k - 1; i >= 0; i--) {
        printf("%d ", c[i]);
    }

    return 0;
}