#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int n;
long long a, b;

long long gcd (long long a, long long b)
{
    long long r = a % b;
    while (r)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

void rezolvare()
{
    f>>n;
    for (int i = 1; i <= n; ++i)
    {
        f>>a>>b;
        g<<gcd(a, b)<<'\n';
    }
}

int main()
{
    rezolvare();

    f.close();
    g.close();
    return 0;
}
