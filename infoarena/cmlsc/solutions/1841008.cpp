#include <fstream>
#include <cmath>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

void solve(int n, int m, int** mat, int *v1, int *v2)
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (v1[i - 1] == v2[j - 1])
                mat[i][j] = mat[i - 1][j - 1] + 1;
            else
                mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
}

int main()
{
    int n, m;
    f >> n >> m;
    int **mat = new int*[n + 1];
    int *v1 = new int[n]();
    int *v2 = new int[m]();
    int *sol = new int[max(n, m)]();
    for (int i = 0; i <= n; ++i)
        mat[i] = new int[m + 1]();
    for (int i = 0; i < n; ++i)
        f >> v1[i];
    for (int i = 0; i < m; ++i)
        f >> v2[i];
    solve(n, m, mat, v1, v2);
    int lg = mat[n][m];
    for (int i1 = n; i1 >= 0 && lg > 0; --i1)
        for (int j1 = m; j1 >= 0 && lg > 0; --j1)
        if (mat[i1][j1] == lg && v1[i1 - 1] == v2[j1 - 1])
        {
            int mini = 257;
            int imin = i1, jmin = j1;
            for (int i2 = i1; i2 >= 0; --i2)
                for (int j2 = j1; j2 >= 0; --j2)
                if (mat[i2][j2] == lg && v1[i2 - 1] == v2[j2 - 1] && mini > v1[i2 - 1])
                {
                    mini = v1[i2 - 1];
                    imin = i2;
                    jmin = j2;
                }
            sol[--lg] = mini;
            i1 = imin;
            j1 = jmin;
        }
    g << mat[n][m] << "\n";
    for (int i = 0; i < mat[n][m]; ++i)
        g << sol[i] << " ";
    return 0;
}
