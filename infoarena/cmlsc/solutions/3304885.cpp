#include <bits/stdc++.h>
#define NMAX 1024
#define ll long long

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m;
int a[NMAX + 2], b[NMAX + 2];
int dp[NMAX + 2][NMAX + 2];
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(false);
    fin.tie(NULL);
    fout.tie(NULL);

    fin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        fin >> b[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    fout << dp[n][m] << '\n';

    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i] == b[j]) {
            ans.emplace_back(a[i]);
            i--;
            j--;
        }
        else {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            }
            else {
                j--;
            }
        }
    }

    reverse(ans.begin(), ans.end());
    for (int num : ans) {
        fout << num << ' ';
    }
    return 0;
}