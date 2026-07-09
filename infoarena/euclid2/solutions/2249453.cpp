#include <iostream>
#include <algorithm>
#include <fstream>

#define gcd __gcd

using namespace std;

int q, x, y;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    f >> q;
    while(q --) {
        f >> x >> y;
        g << gcd(x, y) << '\n';
    }
    return 0;
}
