#include <fstream>
using namespace std;
int m, n, a[1025], b[1025], i, f[1025], c = 0;
void citire ()
{
    ifstream in ("cmlsc.in");
    in >> m >> n;
    for (i = 1; i <= m; ++i)
    in >> a[i];
    for (i = 1; i <= n; ++i)
    in >> b[i];
    in.close ();
}
void frecventa ()
{
    for (i = 1; i <= m; ++i)
    ++f[a[i]];
    for (i = 1; i <= n; ++i)
    {
        ++f[b[i]];
        if (f[b[i]] == 2)
        ++c;
    }
}
void afis (int i, int x)
{
    int j;
    ofstream out ("cmlsc.out");
    out << c << '\n';
    if (x == n)
    {
        for (j = i; j <= x; ++j)
        if (f[b[j]] == 2)
        out << b[j] << ' ';
    }
    else
    for (j = i; j <= x; ++j)
    if (f[a[j]] == 2)
    out << a[j] << ' ';
    out << '\n';
    out.close ();
}
void solve ()
{
    int x, j;
    if (m < n)
    x = m;
    else
    x = n;
    if (x == n)
    {
        for (i = 1; i <= x; ++i)
        if (f[b[i]] == 2)
        {
            afis (i, x);
            i = x + 1;
        }
    }
    else
    for (i = 1; i <= x; ++i)
    if (f[a[i]] == 2)
    {
        afis (i, x);
        i = x + 1;
    }
}
int main()
{
    citire ();
    frecventa ();
    solve ();
    return 0;
}
