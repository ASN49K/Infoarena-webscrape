#include <bits/stdc++.h>
using namespace std;

int n, a, b;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    f >> n;
    while(n--)
    {
        f >> a >> b;
        g << __gcd(a,b) << '\n';
    }
}
