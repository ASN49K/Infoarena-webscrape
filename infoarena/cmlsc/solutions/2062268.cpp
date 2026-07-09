#include <fstream>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int m, n, path[1025];
int dp[1025][1025];
int A[1030], B[1030];
int t[1025][1025];

int main()
{
    in >> m >> n;
    for (int i = 1; i <= m; ++i) in >> A[i];
    for (int i = 1; i <= n; ++i) in >> B[i];

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (A[i] == B[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                t[i][j] = 0;
            } else {
                if (dp[i-1][j] >= dp[i][j-1]) {
                    dp[i][j] = dp[i-1][j];
                    t[i][j] = 1;
                } else {
                    dp[i][j] = dp[i][j-1];
                    t[i][j] = 2;
                }
            }
        }
    }

    int i = m;
    int j = n;
    while (dp[i][j] != 0) {
        if (t[i][j] == 0) {
            path[++path[0]] = A[i];
            i--;
            j--;
        } else if (t[i][j] == 1) {
            i -= 1;
        } else {
            j -= 1;
        }
    }

    out << dp[m][n] << "\n";
    for (int k = path[0]; k >= 1; --k) out << path[k] << " ";

    return 0;
}
