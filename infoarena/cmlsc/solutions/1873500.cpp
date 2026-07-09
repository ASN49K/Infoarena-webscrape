#include <fstream>
using namespace std;

ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");

int x[1026], y[1026], a[1026][1026], v[1026];

int main ()
{
    int i, j, n, m;
    f>>n>>m;
    for (i=1; i<=n; i++) f>>x[i];
    for (j=1; j<=m; j++) f>>y[j];

    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
        {
            if (x[i]==y[j])
                a[i][j] = a[i-1][j-1] + 1;
            else
                a[i][j] = max(a[i-1][j], a[i][j-1]);
        }

    int l = a[n][m];
    i = n, j = m;
    int ll = l;
    g<<l<<'\n';

    while (l>0)
    {
        if (x[i]==y[j])
        {
            v[l--] = x[i];
            i--, j--;
        }

        else if (a[i][j]==a[i-1][j])
            i--;
        else
            j--;
    }

    for (i=1; i<=ll; i++)
        g<<v[i]<<' ';

    f.close(); g.close(); return 0;
}
