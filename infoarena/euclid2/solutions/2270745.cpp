#include <iostream>
///#define f cin
///#define g cout
using namespace std;

int n, x, y;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    f >> n;
    ++n;
    while(--n)
    {
        f >> x >> y;
        while(y)
        {
            int r = y % x;
            x = y;
            y = r;
        }
        g << x << '\n';
    }
    return 0;
}
