#include<stdio.h>
int a, b, r, t;
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%ld",&t);
    while (t)
    {
        t--;
        scanf("%ld %ld",&a,&b);
        r=a%b;
        while (r)
        {
            a=b;    b=r;
            r=a%b;
        }
        printf("%ld\n",b);
    }
    return 0;
}
