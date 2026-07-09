#include <fstream>
using namespace std;
int a[1025], b[1025], n, m, l[1025][1025], sol[1025];
void read ()
{
    int i;
    ifstream in ("cmlsc.in");
    in >> n >> m;
    for (i = 1; i <= n; ++i)
    in >> a[i];
    for (i = 1; i <= m; ++i)
    in >> b[i];
    in.close ();
}
int max (int a, int b)
{
    if (a > b)
    return a;
    else
    return b;
}
int solve ()
{
    int nr = 0, i, j;
    for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j)
    if (a[i] == b[j])
    l[i][j] = l[i - 1][j - 1] + 1;
    else
    l[i][j] = max (l[i - 1][j], l[i][j - 1]);
    for (i = n; i >= 1; --i)
    for (j = m; j >= 1; --j)
    if (a[i] == b[j])
    {
        sol[++nr] = a[i];
        break;
    }
    return nr;
}
void write (int nr)
{
    ofstream out ("cmlsc.out");
    out << nr << '\n';
    for (int i = nr; i >= 1; --i)
    out << sol[i] << ' ';
    out << '\n';
    out.close ();
}
int main()
{
    int nr;
    read ();
    nr = solve ();
    write (nr);
    return 0;
}
