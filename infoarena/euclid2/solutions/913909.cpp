#include <iostream>
#include <cstdio>

using namespace std;

int gcd (long long x, long long y)
{
    if (y==0) return x;
        else gcd(y,x%y);
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int T,i;
    long long a,b,r;
    scanf("%d",&T);
    for (i=1;i<=T;i++)
        {
            scanf("%lld %lld", &a, &b);
            a=gcd(a,b);
            printf("%lld\n",a);
        }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
