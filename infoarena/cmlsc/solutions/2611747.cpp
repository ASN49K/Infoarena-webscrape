#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m;
int a[1025], b[1025], res[1025];
int mat[1025][1025];

int main()
{
    f >> n >> m;
    for (int i = 1; i <= n; i++)
        f >> a[i];
    for (int i = 1; i <= m; i++)
        f >> b[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
            {
                mat[i][j] = mat[i-1][j-1] + 1;
            }
            else
            {
                mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
            }
        }
    }

    g << mat[n][m] << '\n';

    for (int i = n, j = m; i > 0 && j > 0; )
    {
        if (a[i] == b[j])
        {
            res[ mat[i][j] ] = a[i];
            i--, j--;
        }
        else if (mat[i-1][j] < mat[i][j-1])
            j--;
        else
            i--;
    }

    for (int i = 1; i <= mat[n][m]; i++)
        g << res[i] << ' ';

    return 0;
}
