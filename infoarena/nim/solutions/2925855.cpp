#include <fstream>

using namespace std;

ifstream in ("nim.in");
ofstream out ("nim.out");

void solve ()
{
    int n;
    in >> n;
    int xs = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        in >> x;
        xs ^= x;
    }
    if (xs == 0)
    {
        out << "NU";
    }
    else
    {
        out << "DA";
    }
    out << '\n';
}

int main ()
{
    int t;
    in >> t;
    while (t--)
    {
        solve();
    }
    in.close();
    out.close();
    return 0;
}
