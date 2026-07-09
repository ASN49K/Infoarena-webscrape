#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a , long long b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main()
{
     freopen("euclid2.in","r",stdin);
     freopen("euclid2.out","w",stdout);
     int test;

     scanf("%d",&test);
     for(int tc=1; tc <=test; tc++)
     {
        long long a,b;
        scanf("%lld%lld",&a,&b);
        printf("%lld\n",gcd(a,b));
     }
    return 0;
}

