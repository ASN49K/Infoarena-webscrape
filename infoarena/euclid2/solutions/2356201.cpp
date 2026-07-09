#include <bits/stdc++.h>

using namespace std;

constexpr int gcd(unsigned long a, unsigned long b)
{
    return (b==0)?a:gcd(b,a%b);
}


int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    unsigned int a,b,n;
    cin>>n;
    while(n){
    cin >>a>>b;
    cout<<gcd(a,b)<<endl;
    n--;
    }
    return 0;
}
