#include <fstream>
#define max(a, b) ((a > b) ? a : b)
using namespace std;
int m, n, a[1025], b[1025], i, f[1025], d[1025][1025], c = 0, j;
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
void construct ()
{
    for (i = 1; i <= m; ++i)
    for (j = 1; j <= n; ++j)
    if (a[i] == b[j])
    d[i][j] = 1 + d[i - 1][j];
    else
    d[i][j] = max(d[i - 1][j], d[i][j - 1]);
}
void solve ()
{
    for (i = m, j = n; i; )
    if (a[i] == b[j])
    {
        f[++c] = a[i];
        --i;
        --j;
    }
    else
    if (d[i - 1][j] < d[i][j - 1])
    --j;
    else
    --i;
}
void afis ()
{
    ofstream out ("cmlsc.out");
    out << c << '\n';
    for (i = c; i >= 1; --i)
    out << f[i] << ' ';
    out.close ();
}
int main()
{
    citire ();
    construct ();
    solve ();
    afis ();
    return 0;
}
