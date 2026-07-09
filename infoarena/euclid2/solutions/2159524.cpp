#include <bits/stdc++.h>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}
int main()
{
    int n,x,y;
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>x>>y;
        //g<<__gcd(x,y)<<"\n";
        g<<gcd(x,y)<<"\n";
    }

    return 0;
}
