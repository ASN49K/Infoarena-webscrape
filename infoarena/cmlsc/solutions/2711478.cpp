#include <fstream>
#include <queue>

using namespace std;

ifstream inf("cmlsc.in");
ofstream outf("cmlsc.out");

const int NMAX = 1024;

int v1[NMAX];
int v2[NMAX];
int dp[NMAX + 1][NMAX + 1];
int rez[NMAX];

int main() {
    int n, m;
    inf >> n >> m;
    for(int i = 0; i < n; i++) {
        inf >> v1[i];
    }
    for(int i = 0; i < m; i++) {
        inf >> v2[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v1[i] == v2[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    outf << dp[n][m] << '\n';
    int len = dp[n][m] - 1;
    int i = n - 1, j = m - 1;
    while(i >= 0 && j >= 0) {
        if(v1[i] == v2[j]) {
            rez[len] = v1[i];
            len--;
            i--;
            j--;
        }
        else if(dp[i][j + 1] < dp[i + 1][j]) {
            j--;
        }
        else {
            i--;
        }
    }
    len = dp[n][m];
    for(int i = 0; i < len; i++) {
        outf << rez[i] << ' ';
    }
    return 0;
}
