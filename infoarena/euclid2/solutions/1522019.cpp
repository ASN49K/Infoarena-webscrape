#include <fstream>
#include <iostream>
using namespace std;
int T, a, b;

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int main(void)
{
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
f>>T;

    for (; T; --T)
    {
        f>>a;
        f>>b;
g<<gcd(a, b)<<endl;
    }

    return 0;
}
