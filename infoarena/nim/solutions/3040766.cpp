#include <fstream>

using namespace std;

ifstream in ("nim.in");
ofstream out ("nim.out");

void solve ()
{
    int n, xs = 0;
    in >> n;
    while (n--)
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
