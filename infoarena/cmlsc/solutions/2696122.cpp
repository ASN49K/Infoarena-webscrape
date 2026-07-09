#include <fstream>

using namespace std;

const int N = 1025;

int a[N], b[N], dp[N][N];

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

void afisare(int i, int j) {
    if (!dp[i][j] || !i || !j)
        return;
    while (a[i] != b[j]) {
        if (dp[i - 1][j] > dp[i][j - 1])
            --i;
        else
            --j;
    }
    if (dp[i - 1][j] > dp[i][j - 1])
        afisare(i - 1, j);
    else
        afisare(i, j - 1);
    out << a[i] << ' ';
}

int main() {
    int na, nb;
    in >> na >> nb;
    for (int i = 1; i <= na; ++i)
        in >> a[i];
    for (int i = 1; i <= nb; ++i)
        in >> b[i];
    for (int i = 1; i <= na; ++i)
        for (int j = 1; j <= nb; ++j) {
            if (a[i] == b[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    out << dp[na][nb] << '\n';
    afisare(na, nb);

    in.close();
    out.close();
    return 0;
}