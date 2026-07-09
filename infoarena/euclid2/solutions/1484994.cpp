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
    int x[100000], y[100000];
    for (int i = 0; i<n; i++)
    {
        f>>x[i]>>y[i];
    }
    for (int i=0; i<n; i++)
        g<<gcd(x[i], y[i])<<'\n';
    return 0;
}
