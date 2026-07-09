#include <bits/stdc++.h>

using namespace std;

int A[1300], B[1300];
int dp[1301][1301];

int main() {
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    for (int j = 1; j <= m; ++j) {
        cin >> B[j];
    }

    // dp[i][0] si dp[0][j] = 0

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (A[i] == B[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][m] << endl;
    vector <int> answer;

    int currentI = n, currentJ = m;

    while (currentI > 0 && currentJ > 0) {
        if (A[currentI] == B[currentJ]) {
            answer.push_back(A[currentI]);
            currentI--;
            currentJ--;
        } else if (dp[currentI][currentJ - 1] > dp[currentI - 1][currentJ]) {
            currentJ--;
        } else {
            currentI--;
        }
    }

    reverse(answer.begin(), answer.end());

    for (auto x : answer) {
        cout << x << " ";
    }
}