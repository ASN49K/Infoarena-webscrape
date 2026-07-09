#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[1030][1030];
int a[2][1030], res[1030];

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
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int k = 0;
    for (int i = n, j = m; i > 0;) {
        if (a[0][i] == a[1][j]) {
            res[++k] = a[0][i];
            i--;
            j--;
        } else if (dp[i - 1][j] < dp[i][j - 1]) {
            j--;
        } else {
            i--;
        }
    }

    fout << k << '\n';
    for (int i = k; i; i--) {
        fout << res[i] << ' ';
    }



    return 0;
}
