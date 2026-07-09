#include <fstream>
using namespace std;
ifstream in ("euclid2.in");
ofstream out ("euclid2.out");
void solve ()
{
    int a, b;
    in >> a >> b;
    int r = 0;
    while (b)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    out << b << '\n';
    return;
}
int main ()
{
    int t;
    in >> t;
    while (t--)
        solve();
    return 0;
}
