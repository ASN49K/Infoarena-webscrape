#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
short m, n, a[1025], b[1025], v[1025][1025], sol[1025];

short maxim1 (int x, int y)
{
    if (x>y)
        return x;
    return y;
}
int main()
{
    f >> m >> n;
    for (int i=1; i<=m; ++i)
        f >> a[i];
    for (int i=1; i<=n; ++i)
        f >> b[i];
    for (int i=1; i<=m; ++i)
        for (int j=1; j<=n; ++j)
        {
            if (a[i] == b[j])
                v[i][j] = v[i-1][j-1] + 1;
            else
                v[i][j] = maxim1(v[i-1][j], v[i][j-1]);
        }
    g << v[m][n] << '\n';
    short lung_sol=v[m][n], x=m, y=n;
    while (lung_sol)
    {
        if (a[x] == b[y] /*&& v[x][y] == sol[lung_sol+1]-1*/)
        {
            sol[lung_sol--] = a[x];
            --x, --y;
            continue;
        }
        if (v[x][y-1] == lung_sol)
            --y;
        else
            --x;
    }
    for (int i=1; i<=v[m][n]; ++i)
        g << sol[i] << " ";
    return 0;
}
