#include <bits/stdc++.h>

using namespace std;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
int t,a,b;
int gcd(int a,int b)
    {
        if (b==0)
            return a;
        return gcd(b,a%b);
    }
int main()
{
    f>>t;
    for (;t;t--)
    {
        f>>a>>b;
        g<<gcd(a,b)<<'\n';
    }
    return 0;
}
