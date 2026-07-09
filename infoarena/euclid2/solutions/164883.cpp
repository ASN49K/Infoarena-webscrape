#include <stdio.h>

long t,a,b,c,r,i;

int main()
{   freopen ("euclid2.in","r",stdin);
    freopen ("euclid2.out","w",stdout);
    
    scanf("%ld", &t);
    
    for (i=1;i<=t;i++){
        scanf("%ld%ld",&a,&b);
        if (a<b) t=a,a=b,b=t;
        do{
           c=a/b;
           r=a%b;
           a=b,b=r;
        }while (a!=b);
        printf("%ld\n", a);
    }
    return 0;
    
}

