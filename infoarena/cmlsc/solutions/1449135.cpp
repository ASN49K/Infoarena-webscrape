#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int MAX = 1025;
int dp[MAX][MAX], n, m, a[MAX], b[MAX];
vector<int> v;

int main() {
    fin >> n >> m;

    for (int i = 1; i <= n; i++)
        fin >> a[i];
    for (int i = 1; i <= m; i++)
        fin >> b[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }

    fout << dp[n][m] << '\n';
    int sol = dp[n][m], i = n, j = m;

    if (!sol) return 0;

    while (sol) {
        if (a[i] == b[j]) {
            v.push_back(a[i]);
            i--, j--, sol--;
        } else if (dp[i][j] == dp[i - 1][j])
            i--;
        else j--;
    }

    while (v.size()) {
        fout << v.back() << ' ';
        v.pop_back();
    }
    return 0;
}
