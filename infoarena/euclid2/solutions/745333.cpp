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

int euclid(int a, int b)
{
    int c, step = min(bit(a), bit(b));

    while (b)
    {
        a /= bit(a);
        b /= bit(b);

        c = a % b;
        a = b;
        b = c;
    }

    return step * a;
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
