#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

constexpr size_t LIM = 1030;
int N, M, x[LIM], y[LIM], i, j;
int dp[LIM][LIM], sol[LIM];

int main() {
    fin >> N >> M;
    for (i = 1; i <= N; ++i)
        fin >> x[i];
    for (j = 1; j <= M; ++j)
        fin >> y[j];

    for (i = 1; i <= N; ++i)
        for (j = 1; j <= M; ++j)
            if (x[i] == y[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    for (i = N, j = M; i;)
        if (x[i] == y[j])
            sol[++sol[0]] = x[i], --i, --j;
        else if (dp[i - 1][j] < dp[i][j - 1]) --j;
        else --i;

    fout << sol[0] << '\n';
    for (i = sol[0]; i >= 1; --i)
        fout << sol[i] << ' ';

    fin.close();
    fout.close();
    return 0;
}
