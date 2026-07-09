#include <iostream>
#include <stdio.h>
#define fr(i,a,b) for(int i=a;i<b;++i)
#define ll long long

ll gcd (ll a,ll b)
{
    return b?gcd(b,a%b):a;
}

int main()
{
    ll a,b;
    int n;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&n);
    fr(i,0,n)
    {
        scanf("%lld %lld",&a,&b);
        ll er=gcd(a,b);
        printf("%lld\n",er);
    }
}
