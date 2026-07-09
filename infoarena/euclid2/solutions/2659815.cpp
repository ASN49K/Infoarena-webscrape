#include <bits/stdc++.h>
using namespace std;
ifstream in ("euclid2.in");
ifstream out ("euclid2.out");

int gcd(int nA, int nB)
{
    if(!nB) return nA;
    return gcd(nB, nA % nB);
}



int main()
{
    int nA, nB, nT;
    cin >> nT;
    while(nT)
    {
        cin >> nA >> nB;
        cout << gcd(nA, nB);
        nT--;
    }
    return 0;
}
