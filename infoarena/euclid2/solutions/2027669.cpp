#include <bits/stdc++.h>

using namespace std;

int T;

int gcd(int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

void read()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f >> T;
    for(int a,b ; T; --T)
    {
        f >> a >> b;
        g << gcd(a, b) << '\n';
    }
    f.close();
    g.close();
}

int main()
{
    read();
    return 0;
}
