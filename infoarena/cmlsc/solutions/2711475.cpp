#include <fstream>
#include <queue>

using namespace std;

ifstream inf("cmlsc.in");
ofstream outf("cmlsc.out");

const int NMAX = 1024;

int v1[NMAX];
int v2[NMAX];
int dp[NMAX][NMAX];
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
    dp[0][0] = (v1[0] == v2[0]);
    for(int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0], (int)(v1[i] == v2[0]));
    }
    for(int i = 1; i < m; i++) {
        dp[0][i] = max(dp[0][i - 1], (int)(v1[0] == v2[i]));
    }
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(v1[i] == v2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    outf << dp[n - 1][m - 1] << '\n';
    int len = dp[n - 1][m - 1] - 1;
    int i = n - 1, j = m - 1;
    while(i >= 0 && j >= 0 && len >= 0) {
        if(dp[i - 1][j - 1] + 1 == dp[i][j]) {
            rez[len] = v1[i];
            len--;
            i--;
            j--;
        }
        else if(dp[i - 1][j] == dp[i][j]) {
            i--;
        }
        else {
            j--;
        }
    }
    len = dp[n - 1][m - 1];
    for(int i = 0; i < len; i++) {
        outf << rez[i] << ' ';
    }
    return 0;
}
