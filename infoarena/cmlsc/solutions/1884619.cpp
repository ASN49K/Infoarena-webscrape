#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 1026;

int n, m;
int dp[N_MAX][N_MAX];
vector <int> a, b, solution;

void read() {
    ifstream fin("cmlsc.in");

    fin >> n >> m;
    a.resize(n + 1);
    b.resize(m + 1);
    for (int i = 1; i <= n; ++i) {
        fin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        fin >> b[i];
    }

    fin.close();
}

void solve() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = (a[i] != b[j]) ? max(dp[i - 1][j], dp[i][j - 1]) : dp[i - 1][j - 1] + 1;
        }
    }

    int i = n, j = m;
    while (i && j) {
        if (a[i] == b[j]) {
            solution.emplace_back(a[i]);
            --i;
            --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }

    reverse(solution.begin(), solution.end());
}

void write() {
    ofstream fout("cmlsc.out");

    fout << dp[n][m] << '\n';

    for (const auto &it : solution) {
        fout << it << ' ';
    }

    fout.close();
}

int main() {
    read();
    solve();
    write();
    return 0;
}
