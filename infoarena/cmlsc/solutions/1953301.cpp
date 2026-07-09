#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m, a[1030], b[1030], sol[1030][1030];
int out[1030], lg, i, j;

int main() {
    f >> n >> m;
    for (i = 1; i <= n; i++)
        f >> a[i];
    for (i = 1; i <= m; i++)
        f >> b[i];
   // g << n << ' ' << m << '\n';
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (a[i] == b[j])
                sol[i][j] = sol[i-1][j-1]+1;
            else sol[i][j] = max(sol[i-1][j], sol[i][j-1]);
    g << sol[n][m] << '\n';
    i = n, j = m;
    while (i && j) {
        while (sol[i][j]==sol[i-1][j]) i--;
        while (sol[i][j]==sol[i][j-1]) j--;
        out[++lg] = a[i];
        i--, j--;
    }
    for (i = lg; i > 0; i--)
        g << out[i] << " ";
    return 0;
}
