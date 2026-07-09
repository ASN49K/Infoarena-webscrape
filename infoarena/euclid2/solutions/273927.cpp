#include <stdio.h>

using namespace std;

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    long x;
    scanf("%ld", &x);
    long a,b,r;
    while(x!=0)
        {
            scanf("%ld",&a);
            scanf("%ld",&b);
            while(b!=0){r=a%b;a=b;b=r;}
            printf("%ld\n", a);
            x--;
        }
    return 0;
}
