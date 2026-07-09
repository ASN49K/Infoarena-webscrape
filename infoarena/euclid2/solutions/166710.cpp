#include <stdio.h>
long t,a,b,i;
long dc(int a, int b)   
{   
    if (!b) return a;   
    return dc(b, a % b);   
}   

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdin);
    scanf("%ld",&t);
    for(i=1;i<=t;i++)
       {
       scanf("%ld %ld\n",&a,&b);
       printf("%ld\n",dc(a,b));
       }
    return 0;
}
