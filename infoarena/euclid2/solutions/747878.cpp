#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

inline int min(int a, int b)
{
    return a < b ? a : b;
}

inline int bit(int a)
{
    return a & (-a);
}

inline int cnt_bit(int x)
{
    int i;

    for (i = 0 ; (x & 1) == 0 ; x >>= 1, i++);

    return i;
}

inline void del_bit(int& x)
{
    while (~x & 1)
        x >>= 1;
}

int binary_gcd(int a, int b)
{
    if (!b)
        return a;
    if (!a)
        return b;

    int shift = min(cnt_bit(a), cnt_bit(b));

    a >>= shift;
    b >>= shift;

    while (a && b && a != b)
    {
        del_bit(a);
        del_bit(b);

        if (a > b)
            a -= b;
        else
            b -= a;
    }

    return (a ? a : b) << shift;
}

int main()
{
    int t, x, y;

    in >> t;

    while (t--)
    {
        in >> x >> y;
        out << binary_gcd(x, y) << "\n";
    }

    return 0;
}
