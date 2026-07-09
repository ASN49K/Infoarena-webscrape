#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

vector<int> ans;

int m, n;
int dp[1025][1025], a[1025], b[1025];

int main() {
    fin >> m >> n;
    for (int i = 1; i <= m; i++) {
        fin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        fin >> b[i];
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = max(dp[i-1][j-1] + 1, max(dp[i-1][j], dp[i][j-1]));
            }
            else {
                dp[i][j] = max(dp[i-1][j-1], max(dp[i-1][j], dp[i][j-1]));
            }
        }
    }

    int i = m;
    int j = n;
    while (i >= 1 && j >= 1) {
        if (a[i] == b[j]) {
            ans.push_back(a[i]);
            i--;
            j--;
        }
        else {
            if (dp[i-1][j] == dp[i][j]) {
                i--;
            }
            else {
                j--;
            }
        }
    }

    fout << dp[m][n] << "\n";
    while (!ans.empty()) {
        fout << ans.back() << " ";
        ans.pop_back();
    }
    return 0;
}