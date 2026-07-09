#include <fstream>
#include <vector>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, i, j, sz, mat[1025][1025], a[1025], b[1025];
vector <int> out;
int main()
{
    fin >> n >> m;
    for (i = 1; i <= n; i++)
        fin >> a[i];
    for (i = 1; i <= m; i++)
        fin >> b[i];
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
                mat[i][j] = mat[i-1][j-1]+1;
            else
                mat[i][j] = max (mat[i-1][j], mat[i][j-1]);
        }
    }
    fout << mat[n][m] << '\n';
    sz = mat[n][m];
    i = n; j = m;
    while (sz > 0)
    {
        if (a[i] == b[j])
        {
            sz--;
            out.push_back(a[i]);
            i--; j--;
        }
        else
        {
            if (mat[i][j] == mat[i-1][j])
                i--;
            else if (mat[i][j] == mat[i][j-1])
                j--;
        }
    }
    for (auto it = out.rbegin(); it != out.rend(); it++)
        fout << *it << ' ';
    return 0;
}
