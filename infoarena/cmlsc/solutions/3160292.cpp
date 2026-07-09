#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

vector<short int> dp[1030][1030];
short int a[2][1030];

int main() {

    int n, m;
    fin >> n >> m;
    for (int i = 1;i  <= n; i++) {
        fin >> a[0][i];
    }
    for (int i = 1;i <= m; i++) {
        fin >> a[1][i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[0][i] == a[1][j]) {
                dp[i][j] = dp[i - 1][j - 1];
                dp[i][j].push_back(a[0][i]);
            } else {
                if (dp[i - 1][j].size() > dp[i][j - 1].size()) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }

            }
        }
    }

    fout << dp[n][m].size() << '\n';
    for (auto val : dp[n][m])
        fout << val << ' ';



    return 0;
}
