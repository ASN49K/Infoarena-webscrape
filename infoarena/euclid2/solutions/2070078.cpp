#include <bits/stdc++.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int T, A, B;

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int main(void)
{
    f>>T;
    for (;T;--T)
    {
        f>>A>>B;
        g<<gcd(A, B)<<"\n";
    }
    return 0;
}
