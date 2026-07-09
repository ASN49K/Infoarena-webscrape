#include <stdio.h>

long t,a,b,temp,i;

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    
    scanf("%ld\n",&t);  
    for (i=1;i<=t;i++)
    {
        scanf("%ld %ld\n",&a,&b);
        while (b>0)
        {
              temp = a % b;
              a=b;
              b=temp;     
        }
        printf("%ld\n",a);
    }
    
    return 0;
}
