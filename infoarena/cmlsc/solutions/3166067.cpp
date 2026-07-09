#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int DIM = 1030;

int n, m, sol;
int a[DIM], b[DIM];
int dp[DIM][DIM];

void getSolution(int i, int j) {
    if (dp[i][j] > 0) {
        if (a[i] == b[j]) {
            getSolution(i - 1, j - 1);
            fout << a[i] << ' ';
        } else if (dp[i][j] == dp[i - 1][j]) {
            getSolution(i - 1, j);
        } else {
            getSolution(i,j - 1);
        }
    }
}

int main() {
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> a[i];
    for (int i = 1; i <= m; i++)
        fin >> b[i];

    // dp[i][j] = lung celui mai lung subsir format cu primele i valori din a si primele j valori din b
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    fout << dp[n][m] << '\n';
    getSolution(n, m);

    return 0;
}