#include <cstdio>
#include <cstring>
#include <cassert>

#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

typedef long long LL;
typedef vector<int>::iterator it;

const int oo = 0x3f3f3f3f;
const int MAX_N = 1050;

int N, M, String[2][MAX_N], DP[MAX_N][MAX_N];

void Solve() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            if (String[0][i] == String[1][j])
                DP[i][j] = max(DP[i][j], DP[i - 1][j - 1] + 1);
        }
    }
}

void Read() {
    assert(freopen("cmlsc.in", "r", stdin));
    assert(scanf("%d %d", &N, &M) == 2);
    for (int i = 1; i <= N; ++i)
        assert(scanf("%d", &String[0][i]) == 1);
    for (int i = 1; i <= M; ++i)
        assert(scanf("%d", &String[1][i]) == 1);
}

void Trace(int n, int m) {
    if (n < 1 || m < 1)
        return;
    if (String[0][n] == String[1][m]) {
        Trace(n - 1, m - 1);
        printf("%d ", String[0][n]);
        return;
    }
    if (DP[n - 1][m] > DP[n][m - 1])
        Trace(n - 1, m);
    else
        Trace(n, m - 1);
}

void Print() {
    assert(freopen("cmlsc.out", "w", stdout));
    printf("%d\n", DP[N][M]);
    Trace(N, M);
}

int main() {
    Read();
    Solve();
    Print();
    return 0;
}
