#include <bits/stdc++.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    long long n,a,b;
    f>>n;
    for(;n;n--)
        f>>a>>b,g<<__gcd(a,b)<<'\n';
    return 0;
}
