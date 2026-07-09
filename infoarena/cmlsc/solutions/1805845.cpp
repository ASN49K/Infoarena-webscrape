#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> A, B, ans;

vector<int> LCS(const vector<int> &first, const vector<int> &second) {
    int n = int(first.size()), m = int(second.size());
    vector< vector<int> > dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (first[i - 1] == second[j - 1])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    vector<int> sequence;
    for (int i = n, j = m; i > 0 && j > 0; ) {
        if (first[i - 1] == second[j - 1] && dp[i][j] == dp[i - 1][j - 1] + 1) {
            sequence.push_back(first[i - 1]);
            --i;
            --j;
            continue;
        }
        if (dp[i][j] == dp[i - 1][j]) {
            --i;
            continue;
        }
        if (dp[i][j] == dp[i][j - 1]) {
            --j;
            continue;
        }
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

void Solve() {
    ans = LCS(A, B);
}

void Read() {
    int n, m;
    cin >> n >> m;
    A = vector<int>(n);
    B = vector<int>(m);

    for (int i = 0; i < n; ++i)
        cin >> A[i];
    for (int i = 0; i < m; ++i)
        cin >> B[i];
}

void Print() {
    cout << int(ans.size()) << "\n";
    for (int i = 0; i < int(ans.size()); ++i)
        cout << ans[i] << " ";
    cout << "\n";
}

int main() {
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    Read();
    Solve();
    Print();

    return 0;
}
