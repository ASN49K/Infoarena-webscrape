#include <iostream>
///#define f cin
///#define g cout
using namespace std;

long long n, x, y;

ifstream f("euclid2.in");
ofstream g("euclid2.out")

int main()
{
    f >> n;
    while(n)
    {
        f >> x >> y;
        int r = y % x;
        while(r)
        {
            r = y % x;
            x = y;
            y = r;
        }
        g << x << '\n';
        --n;
    }
    return 0;
}
