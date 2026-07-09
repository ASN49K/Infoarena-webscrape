#include <iostream>
#include <cstdio>

using namespace std;

long i,t,a,b,r;

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%ld",&t);
    for (i=1;i<=t;i++)
    {
        scanf("%ld %ld",&a,&b);
        do
        {
            r=a%b;
            a=b;
            b=r;
        }
        while (r!=0);
        printf("%ld\n",a);
    }
    return 0;
}
