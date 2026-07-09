#include <fstream>

using namespace std;

ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");

const int LMAX = 1025;

int n, m, va[LMAX], vb[LMAX], d[LMAX][LMAX], sir[LMAX], bst;

int main()
{
    cin >> n >> m;
    int i, j;
    for (i = 1; i <= n; ++i)
        cin >> va[i];

    for (i = 1; i <= m; ++i)
        cin >> vb[i];

    for (i = 1; i <= n; ++i)
        for (j = 1; j <= m; ++j)
            if (va[i] == vb[j])
                d[i][j] = 1 + d[i-1][j-1];
            else
                d[i][j] = max(d[i-1][j], d[i][j-1]);

    for (i = n, j = m; i; )
    {
        if (va[i] == vb[j])
            sir[++bst] = va[i], --i, --j;
        else if (d[i-1][j] < d[i][j-1])
            --j;
        else
            --i;
    }
    cout << bst << '\n';
    for (i = bst; i; --i)
        cout << sir[i] << ' ';
    return 0;
}
