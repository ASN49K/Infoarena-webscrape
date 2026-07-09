#include <fstream>

using namespace std;

ifstream is("euclid2.in");
ofstream os("euclid2.out");

int t, a, b;

int Euclid(int x, int y)
{
    int r = 0;
    while (y != 0)
    {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main()
{
    is >> t;
    for (int i = 1; i <= t; ++i)
    {
        is >> a >> b;
        if (a > b)
            os << Euclid(a, b) << '\n';
        else
            os << Euclid(b, a) << '\n';
    }

    is.close();
    os.close();
    return 0;
}
