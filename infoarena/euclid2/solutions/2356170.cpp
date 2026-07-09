#include <iostream>

using namespace std;

using num = unsigned long long;

constexpr num gcd(const int a, const int b)
{
    return (b==0)?a:gcd(b,a%b);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    num a,b;
    cin >>a>>b;
    const num r = gcd(a,b);
    if(r == 1)cout<<0;
    else cout<<r;
    return 0;
}
