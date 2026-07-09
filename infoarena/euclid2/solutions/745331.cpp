#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

inline int bit(int x)
{
    return x & (-x);
}

int euclid(int a, int b)
{
    int step, rez = 1;
    while (a && b)
    {
        rez *= min(bit(a), bit(b));
        a /= bit(a);
        b /= bit(b);
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return rez * (a ? a : b);
}

int main()
{
    int t, x, y;

    in >> t;

    while (t--)
    {
        in >> x >> y;
        out << euclid(x, y) << "\n";
    }

    return 0;
}
