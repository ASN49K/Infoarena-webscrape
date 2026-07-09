#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int t, x, y;

int cmmdc(int x, int y)
{
    int r;
    while(y)
    {
        r = x % y;
        x = y;
        y = r;
    }

    return x;
}

int main()
{
    f >> t;

    while(t--)
    {
        f >> x >> y;
        g << cmmdc(x, y) << '\n';
    }
    return 0;
}
