#include <fstream>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

    const int NMAX = 1024;
    int c[NMAX + 1][NMAX + 1], sir1[NMAX + 1], sir2[NMAX + 1];
    int sol[NMAX + 1];
    int n, m, k;

int main()
{
    int i, j;
    cin >> n >> m;

    for (i = 1; i <= n; ++i)
            cin >> sir1[i];

    for (j = 1; j <= m; ++j)
            cin >> sir2[j];

    for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j)
        if (sir1[i] == sir2[j])
            c[i][j] = c[i - 1][j - 1] + 1;
        else c[i][j] = max(c[i - 1][j], c[i][j - 1]);

    for (i = n, j = m; i; )
        if (sir1[i] == sir2[j])
            sol[++k] = sir1[i], --i, --j;
        else if (c[i - 1][j] < c[i][j - 1])
                --j;
        else --i;

    cout << k << '\n';
    for (i = k; i > 0; --i)
        cout << sol[i] << ' ';

    return 0;
}
