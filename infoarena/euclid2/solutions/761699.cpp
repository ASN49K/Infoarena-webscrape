#include <cstdio>

long i,n,a,b,rest;

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%ld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%ld%ld",&a,&b);
        do
        {
            rest=a%b;
            a=b;
            b=rest;
        }
        while(rest!=0);
        printf("%ld/n",a);
    }
}
