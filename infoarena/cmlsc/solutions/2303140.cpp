#include <fstream>
#include <algorithm>
#include <list>

using namespace std;

const char *INPUT_FILE_PATH = "cmlsc.in";
const char *OUTPUT_FILE_PATH = "cmlsc.out";

int main() {
    ifstream cin(INPUT_FILE_PATH);
    ofstream cout(OUTPUT_FILE_PATH);
    int n, m;
    cin >> n >> m;
    int *a = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int *b = new int[m];
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    int **dp = new int *[n];
    for (int row = 0; row < n + 1; ++row) {
        dp[row] = new int[m + 1];
        fill(dp[row], dp[row] + m + 1, 0);
    }
    for (int row = 1; row <= n; ++row) {
        for (int col = 1; col <= m; ++col) {
            if (a[row - 1] == b[col - 1]) {
                dp[row][col] = dp[row - 1][col - 1] + 1;
            } else {
                dp[row][col] = max(dp[row - 1][col - 1], max(dp[row][col - 1], dp[row - 1][col]));
            }
        }
    }
    cout << dp[n][m] << "\n";
    int row = n;
    int col = m;
    list<int> result;
    while (row > 0 && col > 0) {
        if (a[row - 1] == b[col - 1]) {
            result.emplace_back(a[row - 1]);
            --row;
            --col;
        } else if (dp[row - 1][col] > dp[row][col - 1]) {
            --row;
        } else {
            --col;
        }
    }
    reverse(result.begin(), result.end());
    for_each(result.begin(), result.end(), [&](int it) -> void {
        cout << it << " ";
    });
    return 0;
}
