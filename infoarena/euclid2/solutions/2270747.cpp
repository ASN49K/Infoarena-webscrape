#include <iostream>
#include <fstream>
///#define f cin
///#define g cout
using namespace std;

long long n, x, y;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    f >> n;
    ++n;
    while(--n)
    {
        f >> x >> y;
        long long r;
        while(y)
        {
            r = y % x;
            x = y;
            y = r;
        }
        g << x << '\n';
    }
    return 0;
}
