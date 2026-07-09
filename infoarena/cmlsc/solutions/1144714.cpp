#include <fstream>

using namespace std;

short v[1030], w[1030], a[1030][1030], d[1030][1030];

int main()
{int n, m, i, j, s, p; bool start = 1;
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    in >> n >> m;
    for (i = 1; i <= n; ++i)
        in >> v[i];
    for (j = 1; j <= m; ++j)
        in >> w[j];
    p = 1;
    while (v[p] == w[p] && p <= n && p <= m)
        ++p;
    s = 0;
    while (v[n-s] == w[m-s] && n-s-p+1 > 0 && m-s-p+1 > 0)
        ++s;
    for (i = p; i <= n-s; ++i)
        for (j = p; j <= m-s;++j)
        {
            if (v[i] == w[j])
                a[i][j] = a[i-1][j-1]+1, d[i][j] = 3;
            else
                if (a[i-1][j] >= a[i][j-1])
                    a[i][j] = a[i-1][j], d[i][j] = 1;
                else
                    a[i][j] = a[i][j-1], d[i][j] = 2;
        }
    i = n-s;
    j = m-s;
    out << a[i][j] + p + s - 1 << '\n';
    if (p > 1)
    {
        start = 0;
        out << v[1];
        for (i = 2; i < p; ++i)
            out << ' ' << v[i];
    }
    i = n-s;
    j = m-s;
    n = 0;
    while (a[i][j] != 0)
    {
        if (d[i][j] == 3)
            v[++n] = w[j], --i, --j;
        else
        {
            if (d[i][j] == 1)
                --i;
            else
                --j;
        }
    }
    if (start)
    {
        out << v[n];
        --n;
        start = 0;
    }
    while (n)
        out << ' ' << v[n], --n;
    i = 0;
    if (start && s > 0)
        out << w[m], ++i;
    for (; i < s; ++i)
        out << ' ' << w[m-i];
    out << '\n';

    return 0;
}
