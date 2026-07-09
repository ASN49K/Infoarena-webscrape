#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

// 1 ≤ M, N ≤ 1024
// Numerele din cei doi vectori 
//nu depasesc 256

// 1024 + 1
const int MAX_N = 1025;

int dp[MAX_N][MAX_N];

int main() {

    int n, m;
    fin >> n >> m;

    int v1[MAX_N] = {0};
    int v2[MAX_N] = {0};

    for (int i = 1; i <= n; i++) {
        fin >> v1[i];
    }

    for (int i = 1; i <= m; i++) {
        fin >> v2[i];
    }

    // fiind declarată global
    // matricea e deja bordată cu 0
    // așa încât dp[i][0] == 0 și dp[0][j] == 0
    // oricare ar fi 0 <= i <= n
    // și            0 <= j <= m

    for (int idx1 = 1; idx1 <= n; idx1++) {
        for (int idx2 = 1; idx2 <= m; idx2++) {
            
            if (v1[idx1] == v2[idx2]) {
                dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
            } else {

                int sol1 = dp[idx1][idx2 - 1];
                int sol2 = dp[idx1 - 1][idx2];

                dp[idx1][idx2] = max(sol1, sol2);
            }
        }
    }

    fout << dp[n][m] << endl;

    for (int idx1 = 1; idx1 <= n; idx1++) {
        for (int idx2 = 1; idx2 <= m; idx2++) {

            int curr_val = dp[idx1][idx2];
            int top_val  = dp[idx1 - 1][idx2];
            int left_val = dp[idx1][idx2 - 1];

            if (curr_val > top_val && curr_val > left_val) {
                fout << v1[idx1] << ' ';
            }
        }
    }

    return 0;
}