#include <fstream>
#include <vector>

using namespace std;

int main() {

    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");

    int n, m; in >> n >> m;
   
    vector<int> a(n + 1, 0), b(m + 1, 0);

    for (int i = 1; i <= n; i += 1) {
        in >> a.at(i);
    }

    for (int i = 1; i <= m; i += 1) {
        in >> b.at(i);
    }

    int dp[1200][1200];

    for (int i = 0; i < 1200; i += 1) {
        for (int j = 0; j < 1200; j += 1) {
            dp[i][j] = 0;
        }
    }

    
    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j <= m; j += 1) {
            if (a.at(i) == b.at(j)) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int len = dp[n][m];
    int i = n, j = m;
    vector<int> seq(len);
    while (len > 0) {
        if (a.at(i) == b.at(j)) {
            len -= 1;
            seq.at(len) = a.at(i);
            i -= 1;
            j -= 1;
        } else {
            if (dp[i][j - 1] < dp[i - 1][j]) {
                i -= 1;
            } else {
                j -= 1;
            }
        }
    }

    out << dp[n][m] << "\n";
    for (int k = 0; k < dp[n][m]; k += 1) {
        out << seq.at(k) << " ";
    }
    out << "\n";

    return 0;
}
