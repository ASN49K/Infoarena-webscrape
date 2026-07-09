#include <fstream>

using namespace std;

int Max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

short sol[1026], a[1026], b[1026], m[1026][1026];

int main()
{
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");

    int na, nb;
    in >> na >> nb;

    for (int i = 1; i <= na; i++)
        in >> a[i];
    for (int i = 1; i <= nb; i++)
        in >> b[i];

    for (int i = 1; i <= na; i++)
        for (int j = 1; j <= nb; j++)
            if (a[i] == b[j])
                m[i][j] = m[i-1][j-1]+1;
            else
                m[i][j] = Max(m[i-1][j], m[i][j-1]);

    out << m[na][nb] << '\n';

    int x = na, y = nb;
    int nr = m[na][nb];
    while (nr)
    {
        while (m[x-1][y-1] == m[x][y])
        {
            x--;
            y--;
        }
        while (m[x][y-1] == m[x][y])
            y--;
        while (m[x-1][y] == m[x][y])
            x--;

        sol[nr--] = a[x];
        x--;
        y--;
    }

    for (int i = 1; i <= m[na][nb]; i++)
        out << sol[i] << ' ';
    out << '\n';

    return 0;
}
