#include <fstream>

using namespace std;

const int NMAX = 1024;
int vn[NMAX], vm[NMAX], mat[NMAX+1][NMAX+1], n, m, len, so[NMAX];
int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    fin >> n >> m;
    for (int i = 0; i < n; i++)
        fin >> vn[i];
    for (int i = 0; i < m; i++)
        fin >> vm[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            if (vn[i-1] == vm[j-1])
                mat[i][j] = mat[i-1][j-1] + 1;
            else {
                mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
            }
    }

    int sol = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            sol = max(sol, mat[i][j]);
    }

    fout << sol << '\n';

    int x = n, y = m;
    while (sol) {
        if (mat[x-1][y] == sol)
            x--;
        else if (mat[x][y-1] == sol)
            y--;
        else{
            x--;
            sol--;
            y--;
            so[sol] = vn[x];
        }
    }
    for (int i = 0; i < mat[n][m]; i++)
    {
        fout << so[i] << ' ';
    }
    return 0;
}
