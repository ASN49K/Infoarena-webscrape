#include<bits/stdc++.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,a,b;
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        f>>a>>b;
        g<<(__gcd(a,b))<<'\n';
    }
}
