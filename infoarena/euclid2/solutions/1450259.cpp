#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

template <typename F>
F CMMDC(F a, F b)
{
    if (b)
        return CMMDC(b, a%b);
    else
        return a;
}

int main()
{
    int n, x, y;
    f >> n;
    for (int i = 1; i <= n; i++)
    {
        f >> x >> y;
        g << CMMDC(x, y) << "\n";
    }
}
