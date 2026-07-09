#include <fstream>

using namespace std;

fstream f("cmlsc.in", ios::in);
fstream g("cmlsc.out", ios::out);

const int nmax = 1050;

int a[nmax][nmax], x[nmax], y[nmax], sol[nmax];
int n, m, i, j;

void read()
{
    f >> n >> m;
    for (i = 1; i <= n; i++) f >> x[i];
    for (i = 1; i <= m; i++) f >> y[i];
}

void build()
{
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
        {
            if (x[i] == y[j]) a[i][j] = a[i - 1][j - 1] + 1;
                else a[i][j] = max(a[i - 1][j], a[i][j - 1]);
        }
}

void write()
{
    g << a[n][m] << '\n';
    i = n; j = m;
    int nr = 0;
    while ((i > 0) && (j > 0))
    {
        if (x[i] == y[j]) {
                            sol[++nr] = x[i];
                            i--;
                            j--;
        }
        else if (a[i - 1][j] > a[i][j - 1]) i--;
                                    else j--;
    }
    for (i = nr; i >= 1; i--) g << sol[i] << ' ';
}

int main()
{
    read();
    build();
    write();
    return 0;
}
