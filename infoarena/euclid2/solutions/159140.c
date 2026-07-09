#include<stdio.h>
long n,i,a,b,c;

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%ld",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%ld %ld",&a,&b);
        while (b)    
        {
              c=a%b;
              a=b;
              b=c;
        }
        printf("%ld\n",a);
    }
    return 0;
}
