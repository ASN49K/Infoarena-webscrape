#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m;
int a[1025], b[1025];
int lsc[1025];
int dp[1025][1025];

// int lsc (int i, int j) {
//     if(i == n || j == m)
//         return 0;
//     else if (a[i] == b[j])
//         return 1 + lsc(i + 1, j + 1);
//     else
//         return max(lsc(i + 1, j), lsc(i, j + 1));
// }

int main() {

    f >> n >> m;
    for (int i = 1; i <= n; i++)
        f >> a[i];
    for (int i = 1; i <= m; i++)
        f >> b[i];
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    g << dp[n][m] << "\n";
    int cnt = 0;
    int i = n, j = m;
    while (i >= 1 && j >= 1) {
        if (a[i] == b[j]) {
            lsc[cnt++] = a[i];
            i--;
            j--;
        } else { 
            int x = dp[i - 1][j];
            int y = dp[i][j - 1];
            if(dp[i - 1][j] >= dp[i][j - 1]){
                i--;
            } else {
                j--;
            }
        }
    }
    for (int i = cnt - 1; i >= 0; i--)
        g << lsc[i] << " ";
}