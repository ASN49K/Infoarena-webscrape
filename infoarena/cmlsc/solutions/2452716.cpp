#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[1025], b[1025], dp[1025][1025], n, m, best[1025], index;

int maxim(int a, int b) {
    if(a > b)
        return a;
    return b;
}

int main() {
    f >> n >> m;
    for(int i = 1; i <= n; i++)
        f >> a[i];
    for(int i = 1; i <= m; i++)
        f >> b[i];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = maxim(dp[i-1][j], dp[i][j-1]);
        }

    int i = n, j = m;
    while(i) {
        if(a[i] == b[j]) {
            best[index++] = a[i];
            i--;
            j--;
        } else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }

    g << dp[n][m] << '\n';
    for(int i = index-1; i >= 0 ; i--)
        g << best[i] << ' ';
}
