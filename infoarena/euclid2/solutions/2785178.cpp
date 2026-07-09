#include <iostream>
#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int gcd(int d, int i) // d = deîmpărțitul, i = împărțitorul
{
    int rest;

    while(i != 0)
    {
        rest = d % i;
        d = i;
        i = rest;
    }

    return d;
}

int T, a, b, i;

int main()
{
    f >> T;

    for(i = 1; i <= T; i ++)
    {
        f >> a >> b;
        g << gcd(a, b) << "\n";
    }

    f.close();
    g.close();

    return 0;
}
