#include <stdio.h>

typedef long long int li;

li cmmdc(li a, li b)
{
    li t;
    if (a % b == 0) return b;
    while(a > b)
    {
            t = a;
            a = a / b;
            b = t % b;           
    }
    return b;
}

int main()
{
    li a, b;
    int t;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&t);
    while(t) {
     scanf("%lld %lld",&a,&b);
     if (a > b) printf("%lld\n",cmmdc(a,b));
     else printf("%lld\n",cmmdc(b,a));
     t--;
    }
    return 0;
}
