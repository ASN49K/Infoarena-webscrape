#include <bits/stdc++.h>

using namespace std;
int gcd(int a,int b)
{
    int c;
    while (b!=0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main()
{
        int n,a,b;
        ifstream f("euclid2.in");
        ofstream g("euclid2.out");
        f>>n;
        for(int i=1; i<=n; ++i)
        {
            f>>a>>b;
            g<<gcd(a,b)<<'\n';
        }
    return 0;
}
