#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int t, i, a, b;

int cmmdc (int x, int y)
{
    int r=0;
    while (y)
    {
        r = x%y;
        x = y;
        y = r;
    }
    return x;
}

int main ()
{
    f >> t;
    for (i=1; i<=t; i++)
    {
        f >> a >> b;
        g << cmmdc (a, b) << "\n";
    }
    return 0;
}
