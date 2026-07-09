#include <fstream>
using namespace std;
ifstream in ("euclid2.in");
ofstream out ("euclid2.out");
int t, a, b, r;
int main()
{
    in >> t;
    for (int i = 1; i <= t; i++)
    {
        in >> a >> b;
        while (b)
        {
            r = a % b;
            a = b; b = r;
        }
        out << a << '\n';
    }
    out.close(); return 0;
}
