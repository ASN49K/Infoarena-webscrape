#include <bits/stdc++.h>

#define INF ((int)1e9)

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main(void) {
    int n, m;
    fin >> n >> m;

    vector<int> v, w;

    v.push_back(0);
    for (int i = 0; i < n; ++i) {
        int a;
        fin >> a;
        v.push_back(a);
    }

    w.push_back(0);
    for (int i = 0; i < m; ++i) {
        int a;
        fin >> a;
        w.push_back(a);
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = max(max(dp[i - 1][j - 1] + ((v[i] == w[j]) ? 1 : 0),
                    dp[i][j - 1]), dp[i - 1][j]);

            // cout << dp[i][j] << " ";
        }

        // cout << "\n";
    }

    fout << dp[n][m] << "\n";

    vector<int> subseq;
    int i = n, j = m;
    while (i >= 0 && j >= 0) {
        if (v[i] == w[j]) {
            subseq.push_back(v[i]);
            --i;
            --j;
        } else if (dp[i - 1][j] < dp[i][j - 1]) {
            --j;
        } else {
            --i;
        }
    }

    for (int i = subseq.size() - 2; i >= 0; --i) {
        fout << subseq[i] << " ";
    }

    fout << "\n";

    return 0;
}
