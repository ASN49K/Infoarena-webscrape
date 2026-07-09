#include <bits/stdc++.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long gcd(long long a,long long b)
{
    long long c;
    while(b)
        c=a%b,a=b,b=c;
    return a;
}
int main()
{
    long long n,a,b;
    f>>n;
    for(;n;n--)
        f>>a>>b,g<<gcd(a,b)<<'\n';
    return 0;
}
