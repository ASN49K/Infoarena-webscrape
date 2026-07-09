#include <fstream>
#include <vector>
#include <stack>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, i, j, mat[1025][1025];
vector <int> a, b;
stack <int> out;
int main()
{
    fin >> n >> m; a.resize(n+1); b.resize(m+1);
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
                mat[i][j] = max (mat[i][j-1], mat[i-1][j]);
        }
    }
    fout << mat[n][m] << '\n';
    i = n; j = m;
    while (i > 0 && j > 0)
    {
        if (a[i] == b[j])
        {
            out.push(a[i]);
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
    while (!out.empty())
        fout << out.top() << " ", out.pop();
    return 0;
}
