#include <vector>
#include <fstream>
using namespace std;
ifstream fin ("cmlsc.in");

int main() {
    int n, m;
    fin >> n >> m;
    vector<int> v(n + 1), w(m + 1);
    for (int i = 1; i <= n; i++)
        fin >> v[i];
    for (int i = 1; i <= m; i++)
        fin >> w[i];

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<vector<pair<int, int>>> history(n + 1, vector<pair<int, int>>(m + 1, {0, 0}));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                dp[i][j] = dp[i - 1][j];
                history[i][j] = history[i - 1][j];
            } else {
                dp[i][j] = dp[i][j - 1];
                history[i][j] = history[i][j - 1];
            }

            if (v[i] == w[j]) {
                int t = 1 + dp[i - 1][j - 1];
                if (t > dp[i][j]) {
                    dp[i][j] = t;
                    history[i][j] = {i - 1, j - 1};
                }
            }
        }

    fin.close();

    int u = dp[n][m];
    vector<int> result(u);
    pair<int, int> s = {n, m};

    while (--u >= 0) {
        s = history[s.first][s.second];
        result[u] = v[1 + s.first];
    }

    ofstream fout("cmlsc.out");
    fout << result.size() << '\n';
    for (int x : result)
        fout << x << ' ';
}
