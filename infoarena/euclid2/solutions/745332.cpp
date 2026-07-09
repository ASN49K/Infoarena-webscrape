#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int a, int b)
{
    int c;

    while (b)
    {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
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
