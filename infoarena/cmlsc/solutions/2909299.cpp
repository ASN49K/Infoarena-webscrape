#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int p[1024][1024];
int main() {

    int a[1024], b[1024];
    int n; f >> n;
    int m; f >> m;
    for (size_t i = 1; i <= n; i++) f >> a[i];
    for (size_t i = 1; i <= m; i++) f >> b[i];

    for (size_t i = 1; i <= n; i++)
        for (size_t j = 1; j <= m; j++)
            if (a[i] == b[j]) p[i][j] = p[i - 1][j - 1] + 1;
            else p[i][j] = max(p[i - 1][j], p[i][j - 1]);

    g << p[n][m] << endl;

    int res[1024], in = -1;
    int i = n, j = m;
    while (p[i][j] != 0) {
        if (p[i][j] == p[i - 1][j]) i--;
        else if (p[i][j] == p[i][j - 1]) j--;
        else {
            res[++in] = b[j];
            i--; j--;
        }
    }
    for (int x = in; x >= 0; x--) g << res[x] << " ";
}