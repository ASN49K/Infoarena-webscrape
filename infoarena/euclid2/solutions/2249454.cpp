#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int q, x, y;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int gcd(int x, int y)
{
    int r = 0;
    while(y != 0) {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main()
{
    f >> q;
    while(q --) {
        f >> x >> y;
        g << gcd(x, y) << '\n';
    }
    return 0;
}
