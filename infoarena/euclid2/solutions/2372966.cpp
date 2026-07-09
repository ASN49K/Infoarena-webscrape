#include <iostream>
#include <fstream>

using namespace std;

int gcd(int a, int b)
{
    int r=a%b;
    while (r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int T, a, b;
    f>>T;
    while (T--)
    {
        f>>a>>b;
        g<<gcd(a, b)<<'\n';
    }
}
