#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m, a[1025], b[1025], dp[1025][1025];

void citire() {
    f >> n >> m;
    for (int i = 1; i <= n; ++i)
        f >> a[i];
    for (int i = 1; i <= m; ++i)
        f >> b[i];
}

void dinamica() {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
}

void afisare() {
    g << dp[n][m] << '\n';
    int i = n, j = m, sir[1025], ind = 0;
    while (i) {
        if (a[i] == b[j])
            sir[ind++] = a[i], i--, j--;
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    for (ind--; ind >= 0; --ind)
        g << sir[ind] << ' ';
}

int main() {
    citire();
    dinamica();
    afisare();
    return 0;
}
