#include <iostream>
#include <fstream>
///#define f cin
///#define g cout
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

long long n, x, y;

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
            r = x % y;
            x = y;
            y = r;
        }
        g << x << '\n';
    }
    return 0;
}
