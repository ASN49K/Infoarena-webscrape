#include <bits/stdc++.h>

using namespace std;

using num = unsigned long long;

constexpr num gcd(const int a, const int b)
{
    return (b==0)?a:gcd(b,a%b);
}


int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    num a,b;
    cin >>a>>b;
    const num r = gcd(a,b);
    cout<<r;
    return 0;
}
