#include<stdio.h>
long a,b,i,t;

long cmmdc(long a, long b)
{
if(!b) return a;
return cmmdc(b,a%b);    
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    
    scanf("%ld",&t);
    for(i=1;i<=t;++i)
    {
        scanf("%ld%ld",&a,&b);
        printf("%ld\n",cmmdc(a,b));
    }    
    
return 0;
}
