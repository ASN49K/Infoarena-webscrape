#include <iostream>
#include <fstream>

using namespace std;

#define MAXN 1010

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int v[MAXN],w[MAXN],dp[MAXN][MAXN],n,m,sir[MAXN],nr;

int main()
{
    f >> n >> m;
    for (int i = 1; i <= n; ++i) {
        f >> v[i];
    }
    for (int i = 1; i <= m; ++i) {
        f >> w[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (v[i] == v[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    for (int i = n, j = m;j;) {
        if (v[i] == w[j]) {
            sir[++nr] = v[i];
            --i;
            --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }

    g << nr << '\n';
    for (int i = nr; i; --i) {
        g << sir[i] << ' ';
    }

    return 0;
}
