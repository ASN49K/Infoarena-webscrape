/*
    Keep It Simple!
*/

#include <vector>
#include <fstream>
#include <queue>

using namespace std;

const int kMaxN = 1025;

int N,M;
int a[kMaxN],b[kMaxN],dp[kMaxN][kMaxN];
vector<int> sol;

void ReadInput() {
    ifstream fin("cmlsc.in");
    fin >> N >> M;
    for (int i(1); i <= N; ++i)
        fin >> a[i];
    for (int i(1); i <= M; ++i)
        fin >> b[i];
    fin.close();
}

void Solve() {
    ReadInput();

    for (int i(1); i <= N; ++i)
        for (int j(1); j <= M; ++j)
            if (a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    ofstream fout("cmlsc.out");
    fout << dp[N][M] << '\n';
    int x(N),y(M);
    while (x>0 && y>0) {
        if (a[x] == b[y]) {
            fout << a[x] << ' ';
            --x,--y;
        }
        else if (dp[x-1][y] > dp[x][y-1])
            --x;
        else
            --y;
    }
    fout << '\n';
    fout.close();
}

int main() {
    Solve();
    return 0;
}
