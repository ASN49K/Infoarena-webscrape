#include <fstream>

using namespace std;

ifstream in("nim.in");
ofstream out("nim.out");

int main()
{
    int t, n, a;
    in >> t;
    for (int q = 1; q <= t; ++q)
    {
        in >> n;
        int s = 0;
        for (int i = 1; i <= n; ++i)
        {
            in >> a;
            s ^= a;
        }
        if (s)
            out << "DA";
        else
            out << "NU";
        out << '\n';
    }
    return 0;
}
