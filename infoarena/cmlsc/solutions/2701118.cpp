#include <fstream>
using namespace std;
 
int dp[1025][1025];
int a[1025];
int b[1025];
int rez[1025];
 
#define max(a, b) (a > b) ? a : b
 
int main() {
    int n, m, i, j, l = 0;
 
    ifstream f("cmlsc.in");
    f >> n >> m;
    for (i = 1; i <= n; i++)
        f >> a[i];
    for (i = 1; i <= m; i++)
        f >> b[i];
    f.close();
 
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (a[i] == b[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
 
    ofstream g("cmlsc.out");
    g << dp[n][m] << '\n';
    i = n, j = m;
    while (i >= 1 && j >= 1) {
        if (dp[i - 1][j - 1] == dp[i][j] - 1 && dp[i - 1][j] == dp[i][j - 1])
            i--, j--, rez[++l] = a[i + 1];
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else j--;
    }
    for (i = l; i >= 1; i--)
        g << rez[i] << ' ';
    g.close();
    return 0;
}