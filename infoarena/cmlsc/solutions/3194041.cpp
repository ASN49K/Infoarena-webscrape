#include <fstream>

using namespace std;

const int N = 1024;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int l_max[N+1][N+1], a[N+1], b[N+1];

void refac_subsir(int l, int c)
{
    if (l == 0 || c == 0)
    {
        return;
    }
    if (a[l] == b[c])
    {
        refac_subsir(l - 1, c - 1);
        out << a[l] << " ";
    }
    else
    {
        if (l_max[l-1][c] > l_max[l][c-1])
        {
            refac_subsir(l - 1, c);
        }
        else
        {
            refac_subsir(l, c - 1);
        }
    }
}

int main()
{
    int m, n;
    in >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        in >> a[i];
    }
    for (int j = 1; j <= n; j++)
    {
        in >> b[j];
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i] == b[j])
            {
                l_max[i][j] = 1 + l_max[i-1][j-1];
            }
            else
            {
                l_max[i][j] = max(l_max[i-1][j], l_max[i][j-1]);
            }
        }
    }
    out << l_max[m][n] << "\n";
    refac_subsir(m, n);
    in.close();
    out.close();
    return 0;
}
