#include <fstream>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int maxim(int a, int b)
{
    return a > b ? a : b;
}

int a[1025], b[1025], n, m, i, j, p[1025][1025], cmlsc[1025], k;

int main()
{
    in >> n >> m;
    for (i = 1; i <= n; i++) in >> a[i];
    for (i = 1; i <= m; i++) in >> b[i];

    // Matrice
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (a[i] == b[j]) p[i][j] = 1 + p[i - 1][j - 1];
            else p[i][j] = maxim(p[i - 1][j], p[i][j - 1]);
        }
    }

    i = n; j = m;
    while (i > 0 && j > 0)
    {
        if (a[i] == b[j])
        {
            cmlsc[++k] = a[i];
            i--;
            j--;
        }
        else if (p[i - 1][j] < p[i][j - 1])
            j--;
        else
            i--;
    }

    for (i = k; i >= 1; i--) out << cmlsc[i] << ' ';

    return 0;
}