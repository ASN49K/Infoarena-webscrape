#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int DIM = 1030;
int n, m;
int a[DIM], b[DIM];
int dp[DIM][DIM], sol[DIM];

int main() {
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> a[i];
    for (int i = 1; i <= m; i++)
        fin >> b[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int i = n, j = m, cnt = dp[n][m];
    while (i > 0 && j > 0) {
        if (a[i] == b[j]) {
            sol[cnt--] = a[i];
            i--, j--;
        } else if (dp[i - 1][j] < dp[i][j - 1]) {
            j--;
        } else {
            i--;
        }
    }

    fout << dp[n][m] << '\n';
    for (int index = 1; index <= dp[n][m]; index++)
        fout << sol[index] << ' ';

    return 0;
}