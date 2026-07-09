#include <fstream>
#define DMAX 1030

std::ifstream fin("cmlsc.in");
std::ofstream fout("cmlsc.out");

int m, n;
char a[DMAX], b[DMAX];

int lgMax;
char sol[DMAX];
int dp[DMAX][DMAX];

int main() {
    int max;
    int I, J, newI, newJ;

    fin >> m >> n;
    for (int i = 1; i <= m; i++)
        fin >> a[i];
    for (int i = 1; i <= n; i++)
        fin >> b[i];

    for (int i = m; i >= 1; i--)
        for (int j = n; j >= 1; j--)
            if (a[i] == b[j])
                dp[i][j] = dp[i + 1][j + 1] + 1;
            else
                dp[i][j] = dp[i + 1][j] > dp[i][j + 1] ? dp[i + 1][j] : dp[i][j + 1];

    lgMax = dp[I = 1][J = 1];
    for (int it = lgMax; it >= 1; it--) {
        max = 0;
        for (int i = I; i <= m; i++)
            for (int j = J; j <= n; j++)
                if (dp[i][j] == it && a[i] == b[j] && a[i] > max) {
                    max = a[i];
                    newI = i;
                    newJ = j;
                }

        I = newI + 1;
        J = newJ + 1;
        sol[it] = max;
    }

    fout << dp[1][1] << '\n';
    for (int i = lgMax; i >= 1; i--)
        fout << sol[i] << ' ';

    fout << '\n';
    fout.close();
    return 0;
}
