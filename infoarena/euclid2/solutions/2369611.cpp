#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int a, b, t;

int main()
{
    f >> t;
    while(t--)
    {
        f >> a >> b;
        g << __gcd(a, b) << '\n';
    }
    return 0;
}
