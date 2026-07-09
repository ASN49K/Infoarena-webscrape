#include <bits/stdc++.h>
using namespace std;

ifstream f ("euclid2.in");
ofstream g("euclid2.out");

void  Euclid(int n, int m)
{
    while(m != 0)
    {
        int r = n % m;
        n = m;
        m = r;
    }
    g << n <<'\n';
}

int main()
{
    int nr, a, b;
    f>>nr;
    for(;nr;nr--)
    {
        f>>a>>b;
        Euclid(a,b);
    }
}
