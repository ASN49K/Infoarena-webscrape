#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

typedef long long ll;

void Solve() {
    int n, m;
    fin >> n >> m;
    vector<int> a(n + 1), b(m + 1), sequence;
    for (int i = 1; i <= n; ++i) {
        fin >> a[i];
    }
    for (int j = 1; j <= m; ++j) {
        fin >> b[j];
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = max(dp[i - 1][j], max(dp[i][j - 1], dp[i - 1][j - 1] + (a[i] == b[j])));
        }
    }
       
    int i = n, j = m;
    while (dp[i][j]) {
        if (a[i] == b[j]) {
            sequence.push_back(a[i]);
            --i;
            --j;
        }
        else {
            if (dp[i][j] == dp[i - 1][j]) {
                --i;
            }
            else {
                --j;
            }
        }
    }

    reverse(sequence.begin(), sequence.end());

    fout << dp[n][m] << '\n';
    for (auto x : sequence) {
        fout << x << ' ';
    }
}

int main() {

    ios_base::sync_with_stdio(false);

    Solve();

    return 0;
}