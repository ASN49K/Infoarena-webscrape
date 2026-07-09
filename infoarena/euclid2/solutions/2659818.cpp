#include <bits/stdc++.h>
using namespace std;
ifstream in ("euclid2.in");
ofstream out ("euclid2.out");

int gcd(int nA, int nB)
{
    if(!nB) return nA;
    return gcd(nB, nA % nB);
}

int main()
{
    int nA, nB, nT;
    in >> nT;
    while(nT)
    {
        in >> nA >> nB;
        out << gcd(nA, nB) << '\n';
        nT--;
    }
    return 0;
}
