#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int mat[1030][1030];
int n, m, a[1030], b[1030];
void citire()
{
    f >> m >> n;
    int i, j;
    for(i = 1; i <= m; i++)
        f >> a[i];
    for(j = 1; j <= n; j++)
        f >> b[j];
}
void solve()
{
    int ii, jj;
    for(ii = 1; ii <= m; ii++)
        for(jj = 1; jj <= n; jj++)
            if(a[ii] == b[jj])
                mat[ii][jj] = 1 + mat[ii - 1][jj - 1];
            else
                mat[ii][jj] = max(mat[ii - 1][jj], mat[ii][jj - 1]);
    g << mat[m][n] << '\n';
}
void afisare(int i, int j)
{
    if(i > 0 or j > 0)
    {if(a[i] == b[j])
    {
        afisare(i - 1, j - 1);
        g << a[i] << ' ';
    }
    else
    {if(mat[i - 1][j] < mat[i][j-1])
        afisare(i, j - 1);
        else
            afisare(i - 1, j);}}
}
int main()
{
    citire();
    solve();
    afisare(m,n);
}
