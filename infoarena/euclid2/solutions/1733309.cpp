#include <iostream>
#include <fstream>

using namespace std;

ifstream f ("euclid2.in");
ofstream t ("euclid2.out");

int euclid(long a, long b)
{
    long c;
    while (b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    long n,a,b;
    f>>n;
    for (long i=0; i<n; ++i)
    {
        f>>a>>b;
        t<<euclid(a,b);
    }
    return 0;
}
