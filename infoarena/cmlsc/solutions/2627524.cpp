/// Complexitate O(n * m)
#include <bits/stdc++.h>
using namespace std;

int a[1069], b[1069], dp[1069][1069],  n , m;
vector <int> longestSequence;

void getMaxLength() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
}

void findSequence() {
    int i = n, j = m;
    while(i && j) {
        if(a[i - 1] == b[j - 1]) {
            longestSequence.push_back(a[i - 1]);
            i--, j--;
        } else {
            if(dp[i - 1][j] < dp[i][j - 1]) {
                j--;
            } else {
                i--;
            }
        }
    }
    reverse(longestSequence.begin(), longestSequence.end());
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }

    getMaxLength();
    findSequence();

    printf("%d\n", dp[n][m]);
    for(auto e : longestSequence) {
        printf("%d ", e);
    }
    return 0;
}