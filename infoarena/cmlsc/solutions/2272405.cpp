#include <fstream>
#define DMAX 1030

std::ifstream fin("cmlsc.in");
std::ofstream fout("cmlsc.out");

int m, n;
int a[DMAX], b[DMAX];

int lgMax;
int sol[DMAX];
int dp[DMAX][DMAX];

int main() {
    int i, j;

    fin >> m >> n;
    for (i = 1; i <= m; i++)
        fin >> a[i];
    for (j = 1; j <= n; j++)
        fin >> b[j];

    for (i = m; i >= 1; i--)
        for (j = n; j >= 1; j--)
            if (a[i] == b[j])
                dp[i][j] = dp[i + 1][j + 1] + 1;
            else
                dp[i][j] = dp[i + 1][j] > dp[i][j + 1] ? dp[i + 1][j] : dp[i][j + 1];

    for (i = 1, j = 1; i <= m && j <= n; )
        if (a[i] == b[j]) {
            sol[++lgMax] = a[i];
            i++; j++;
        }
        else if (dp[i + 1][j] < dp[i][j + 1])
            j++;
        else
            i++;

    fout << lgMax << '\n';
    for (i = 1; i <= lgMax; i++)
        fout << sol[i] << ' ';

    fout << '\n';
    fout.close();
    return 0;
}
