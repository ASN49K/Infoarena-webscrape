#include <fstream>
#include <cstring>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int N = 1024;

unsigned char a[N + 2], b[N + 2];
int dp[N + 2][N + 2];

void afis(int x, int y) {
    if (!x || !y)
        return;
    if (a[x] == b[y]) {
        afis(x - 1, y - 1);
        out << a[x] << ' ';
    }
    else {
        if (dp[x][y - 1] > dp[x - 1][y])
            afis(x, y - 1);
        else
            afis(x - 1, y);
    }
}

int main() {
    int n, m;
    in >> n >> m;
    for (int i = 1; i <= n; ++i)
        in >> a[i];
    for (int i = 1; i <= m; ++i)
        in >> b[i];
    n = max(n, m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    out << dp[n][n] << '\n';
    afis(n, n);
    in.close();
    out.close();
    return 0;
}