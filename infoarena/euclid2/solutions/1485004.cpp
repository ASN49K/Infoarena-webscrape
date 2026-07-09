#include <iostream>
#include <bits/stdc++.h>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int gcd(int a, int b)
{
    if (a==0)
        return b;
    else
        return gcd(b%a,a);
}

int main()
{

    int n;
    f >> n;
    int x, y;
    for (int i=0; i<n; i++)
    {
        f >> x >>y;
        g<<gcd(x, y)<<'\n';
    }
    return 0;
}
