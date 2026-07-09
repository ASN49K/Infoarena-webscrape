#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

// 1 ≤ M, N ≤ 1024
// Numerele din cei doi vectori nu depasesc 256

const int MAX_N = 1024;


int main() {
    int n1;
    int n2;
    int elems1[MAX_N + 1];
    int elems2[MAX_N + 1];
    
    int dp[MAX_N + 1][MAX_N + 1] = {0};

    fin >> n1 >> n2;

    for (int i = 1; i <= n1; i++) {
        fin >> elems1[i];
    }

    for (int i = 1; i <= n2; i++) {
        fin >> elems2[i];
    }


    for (int i = 1; i <= n1; i++) {

        for (int j = 1; j <= n2; j++) {

            if (elems1[i] == elems2[j]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int idx1 = n1;
    int idx2 = n2;

    int poz = dp[n1][n2];

    int ans[MAX_N];

    while (idx1 > 0 && idx2 > 0) {
        if (elems1[idx1] == elems2[idx2]) {

            ans[poz] = elems1[idx1];
            
            idx1--;
            idx2--;
            poz--;
        } else if (dp[idx1 - 1][idx2] > dp[idx1][idx2 - 1]) {
            idx1--;
        } else {
            idx2--;
        }
    }

    fout << dp[n1][n2] << endl;

    for (int i = 1; i <= dp[n1][n2]; i++) {
        fout << ans[i] << " ";
    }
}